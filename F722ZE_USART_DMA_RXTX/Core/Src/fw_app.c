#include <stdio.h>
#include <string.h>
#include "fw_app.h"

FL_DECLARE_DATA fw_app_t  g_app;
uint8_t                   _g_q1_buf[FW_APP_Q_SIZE];

extern DMA_HandleTypeDef hdma_usart3_rx;

// DO NOT ANY HARDWARE SETTINGS.
FL_DECLARE(void) fw_app_init(void)
{
  memset(&g_app, 0, sizeof(g_app));
  memset(_g_q1_buf, 0, sizeof(_g_q1_buf));

  fl_dma_q_init(&g_app.q1, &hdma_usart3_rx, _g_q1_buf, sizeof(_g_q1_buf));
}

FL_DECLARE(void) fw_app_hw_init(void)
{
  g_app.device_id = 1;

  HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);

  HAL_UART_Receive_DMA(&huart3, _g_q1_buf, sizeof(_g_q1_buf));
}

FL_DECLARE(void) fw_app_systick(void)
{
  g_app.tick++;
  // Do some work every 1 second.
  if (g_app.tick >= FW_APP_ONE_SEC_INTERVAL)
  {
    // LED1 toggle.
    HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
    g_app.tick = 0;
  }
}

FL_DECLARE(void) fw_app_dma_transmit(void)
{
  HAL_StatusTypeDef ret;
  uint8_t wait_count = 0;

  ret = HAL_UART_Transmit_DMA(&huart3, g_app.tx_buf1, (uint16_t)g_app.tx_len1);

  if (ret == HAL_OK)
  {
    while (1)
    {
      if (huart3.gState == HAL_UART_STATE_READY)
      {
        break;
      }
      HAL_Delay(1);
      wait_count++;
      if (wait_count >= FW_APP_DMA_TX_MAX_COUNT)
      {
        break;
      }
    }
  }

  g_app.tx_len1 = 0;
}
