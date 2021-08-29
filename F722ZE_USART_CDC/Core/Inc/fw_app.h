// fw_app.h
// Firmware application.

#ifndef FW_APP_H
#define FW_APP_H

#include "main.h"
#include "usbd_cdc_if.h"
#include "gpio.h"

#include "fl_def.h"
#include "fl_queue.h"

#define FW_APP_UART_HANDLE                                UART_HandleTypeDef*

#define FW_APP_ONE_SEC_INTERVAL     (999) // 1 second

#define FW_APP_PROTO_RX_TIMEOUT     (500)
#define FW_APP_PROTO_TX_TIMEOUT     (500)

FL_BEGIN_PACK1

// Firmware application manager.
typedef struct _fw_app
{
  uint32_t                device_id;

  // Current tick count.
  volatile uint32_t       tick;

  uint8_t                 rx_buf1[1];
  fl_queue_t              q1;
  uint8_t                 tx_buf1[APP_TX_DATA_SIZE];
  uint32_t                tx_len1;
} fw_app_t;

FL_END_PACK

FL_BEGIN_DECLS

FL_DECLARE_DATA extern fw_app_t g_app;

FL_DECLARE(void) fw_app_init(void);
FL_DECLARE(void) fw_app_hw_init(void);
FL_DECLARE(void) fw_app_systick(void);

FL_END_DECLS

#endif
