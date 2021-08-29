# F722ZE_USART_Example
NUCLEO F722ZE USART examples

1. Common settings/actions

Item  | Value
------------- | -------------
Baud rate  | 115200
Word length  | 8 bits
Parity  | None
Stop bits  | 1
</br>

![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_setting1.png)
</br>Fig1. Common setting
</br>
- Character echo
- STM32CubeIDE Formatter setting
  Window -> Preference -> C/C++ -> Code Style -> Formatter -> Import
  </br>
  -> Select My_Formatter.xml file in c_style directory -> Apply and Close

2. Polling example

3. Interrupt RX example
- Interrupt setting</br>
![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_interrupt_setting1.png)
</br>Fig2. Interrupt setting

4. Interrupt RX/TX example

5. DMA RX example
- DMA RX interrupt setting</br>
![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_rx_dma_interrupt_setting1.png)
</br>Fig3. DMA RX Interrupt setting

- DMA RX setting</br>
  Mode : Circular</br>
![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_rx_dma_setting1.png)
</br>Fig4. DMA RX setting


6. DMA RX/TX example
- DMA RX/TX interrupt setting</br>
![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_rxtx_dma_interrupt_setting1.png)
</br>Fig5. DMA RX/TX Interrupt setting

- DMA RX setting</br>
  Mode : Circular</br>
![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_rxtx_rx_dma_setting1.png)
</br>Fig6. DMA RX setting

- DMA TX setting</br>
  Mode : Normal</br>
![](https://github.com/heecheol-jung/F722ZE_USART_Example/blob/main/pictures/usart3_rxtx_tx_dma_setting1.png)
</br>Fig7. DMA TX setting

7. USB CDC example
