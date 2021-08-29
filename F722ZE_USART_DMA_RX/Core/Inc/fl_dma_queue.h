// Firmware library DMA queue
// fl_dma_queue.h

#ifndef FL_DMA_QUEUE_H
#define FL_DMA_QUEUE_H

#include "fl_def.h"
#include "usart.h"

#define FL_DMA_HANDLE   DMA_HandleTypeDef*

FL_BEGIN_PACK1

typedef struct _fl_dma_queue
{
  FL_DMA_HANDLE     dma_handle;
  volatile uint8_t* buf;

  uint32_t          buf_size;

  volatile uint8_t  head;

  volatile uint8_t  tail;

  volatile uint32_t  count;
} fl_dma_queue_t;

FL_END_PACK

FL_BEGIN_DECLS

FL_DECLARE(void) fl_dma_q_init(fl_dma_queue_t* q, FL_DMA_HANDLE dma_handle, uint8_t* buf, uint32_t buf_size);
FL_DECLARE(uint32_t) fl_dma_q_count(fl_dma_queue_t* q);
FL_DECLARE(fl_status_t) fl_dma_q_pop(fl_dma_queue_t* q, uint8_t* data);

FL_END_DECLS

#endif
