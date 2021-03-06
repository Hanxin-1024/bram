/*
 * demo.c
 *
 *  Created on: 2020年12月26日
 *      Author: xin.han
 *      //串口驱动

//LVDS

//8B/10

//IO

//RS485

//1553B
 *
 */

#include "count.h"
#include "Fire.h"
#include "LVDS_driver.h"
#include "Uart_driver.h"
#include "xdma_driver.h"
#include "xuartps.h"
#include "xparameters.h"

#include "xtime_l.h"



void Uart_demo();
void Xdma_demo();
void LVDS_demo();
void speed_demo();
//void show8();
//void show9();


extern int TotalReceivedCount;


int main ()
{
//xil_printf("start\r\n");
//	count();
//	LVDS_demo();
//	Xdma_demo();
    Uart_demo();

}

void Uart_demo()
{
	int i,Status;

//	u8 sendbuf[] = "HelloWorld";
	u8 sendbuf[] = "U";
	u8 recvbuf[FIFO_SIZE] = {};
	u8 recvbuf1[FIFO_SIZE] = {};
	u8 recvbuf2[FIFO_SIZE] = {};
	u8 recvbuf3[FIFO_SIZE] = {};
	u8 recvbuf4[FIFO_SIZE] = {};
	u8 recvbuf5[FIFO_SIZE] = {};
	u8 recvbuf6[FIFO_SIZE] = {};
	u8 recvbuf7[FIFO_SIZE] = {};
	u8 recvbuf8[FIFO_SIZE] = {};
	u8 recvbuf9[FIFO_SIZE] = {};
	u8 recvbuf10[FIFO_SIZE] = {};
//	u8 recvbuf11[FIFO_SIZE] = {};



//	FifoInit(&Uart0FIFO,&RecvBuffer[0],FIFO_SIZE);
//	FifoInit(&Uart1FIFO,RecvBuffer[1],FIFO_SIZE);
//	FifoInit(&Uart2FIFO,RecvBuffer[2],FIFO_SIZE);
//	FifoInit(&Uart3FIFO,RecvBuffer[3],FIFO_SIZE);
//	FifoInit(&Uart4FIFO,RecvBuffer[4],FIFO_SIZE);
//	FifoInit(&Uart5FIFO,RecvBuffer[5],FIFO_SIZE);
//	FifoInit(&Uart6FIFO,RecvBuffer[6],FIFO_SIZE);
//	FifoInit(&Uart7FIFO,RecvBuffer[7],FIFO_SIZE);
//	FifoInit(&Uart8FIFO,RecvBuffer[8],FIFO_SIZE);
//	FifoInit(&Uart9FIFO,RecvBuffer[9],FIFO_SIZE);
//	FifoInit(&Uart10FIFO,RecvBuffer[10],FIFO_SIZE);
//	FifoInit(&Uart11FIFO,RecvBuffer[11],FIFO_SIZE);



//	XUartPs_SetBaudRate(&Uart_Ps,1000000);
	//XUartNs550_SetBaud
	     Status = UartNs550Init(&IntcInstance0,
					&Uart0Ns550Instance,
					XPAR_UARTNS550_0_DEVICE_ID,
					XPAR_FABRIC_AXI_UART16550_0_IP2INTC_IRPT_INTR);
	   XUartNs550_SetBaudRate(&Uart0Ns550Instance,115200);
	    if (Status != XST_SUCCESS)
	       {
		        xil_printf("Uartns550 0 interrupt Example Failed\r\n");
		        return XST_FAILURE;
           }


         Status = UartNs550Init(&IntcInstance0,
					            &Uart1Ns550Instance,
					            XPAR_UARTNS550_1_DEVICE_ID,
					            XPAR_FABRIC_AXI_UART16550_1_IP2INTC_IRPT_INTR);
	    if (Status != XST_SUCCESS)
	       {
		        xil_printf("Uartns550 1 interrupt Example Failed\r\n");
		        return XST_FAILURE;
	       }
	     Status = UartNs550Init(&IntcInstance0,
						        &Uart2Ns550Instance,
						        XPAR_UARTNS550_2_DEVICE_ID,
						        XPAR_FABRIC_AXI_UART16550_2_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
		   {
			    xil_printf("Uartns550  2 interrupt Example Failed\r\n");
			    return XST_FAILURE;
		   }
		 Status = UartNs550Init(&IntcInstance0,
							    &Uart3Ns550Instance,
							    XPAR_UARTNS550_3_DEVICE_ID,
							    XPAR_FABRIC_AXI_UART16550_3_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 3 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
		Status = UartNs550Init(&IntcInstance0,
								&Uart4Ns550Instance,
								XPAR_UARTNS550_4_DEVICE_ID,
								XPAR_FABRIC_AXI_UART16550_4_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 4 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
	    Status = UartNs550Init(&IntcInstance0,
								&Uart5Ns550Instance,
								XPAR_UARTNS550_5_DEVICE_ID,
								XPAR_FABRIC_AXI_UART16550_5_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 5 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
		 Status = UartNs550Init(&IntcInstance0,
							&Uart6Ns550Instance,
							XPAR_UARTNS550_6_DEVICE_ID,
							XPAR_FABRIC_AXI_UART16550_6_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 6 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}

		 Status = UartNs550Init(&IntcInstance0,
							&Uart7Ns550Instance,
							XPAR_UARTNS550_7_DEVICE_ID,
							XPAR_FABRIC_AXI_UART16550_7_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 7 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
		 Status = UartNs550Init(&IntcInstance0,
							&Uart8Ns550Instance,
							XPAR_UARTNS550_8_DEVICE_ID,
							XPAR_FABRIC_AXI_UART16550_8_IP2INTC_IRPT_INTR);
		 XUartNs550_SetBaudRate(&Uart8Ns550Instance,10000000);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 8 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
		 Status = UartNs550Init(&IntcInstance0,
							&Uart9Ns550Instance,
							XPAR_UARTNS550_9_DEVICE_ID,
							XPAR_FABRIC_AXI_UART16550_9_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 9 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
		 Status = UartNs550Init(&IntcInstance0,
							&Uart10Ns550Instance,
							XPAR_UARTNS550_10_DEVICE_ID,
							XPAR_FABRIC_AXI_UART16550_10_IP2INTC_IRPT_INTR);
		if (Status != XST_SUCCESS)
			{
				xil_printf("Uartns550 10 interrupt Example Failed\r\n");
				return XST_FAILURE;
			}
//		XUartNs550_SetBaudRate(&Uart10Ns550Instance,1000000);



//		 Status = UartNs550Init(&IntcInstance0,
//							&Uart11Ns550Instance,
//							XPAR_UARTNS550_11_DEVICE_ID,
//							XPAR_FABRIC_AXI_UART16550_11_IP2INTC_IRPT_INTR);
//		if (Status != XST_SUCCESS)
//			{
//				xil_printf("Uartns550 11 interrupt Example Failed\r\n");
//				return XST_FAILURE;
//			}
	//XUartNs550_Send(&UartNs550Instance, sendbuf, 14);
	//XUartNs550_Recv(&UartNs550Instance, recvbuf, TEST_BUFFER_SIZE);
	//XUartNs550_Recv(&UartNs550Instance, recvbuf, 8);

		//XUartNs550_Recv(&Uart0Ns550Instance, recvbuf, 1);

	XUartNs550_Recv(&Uart0Ns550Instance, recvbuf, 256);
	XUartNs550_Recv(&Uart1Ns550Instance, recvbuf1, 256);
	XUartNs550_Recv(&Uart2Ns550Instance, recvbuf2, 256);
	XUartNs550_Recv(&Uart3Ns550Instance, recvbuf3, 256);
	XUartNs550_Recv(&Uart4Ns550Instance, recvbuf4, 256);
	XUartNs550_Recv(&Uart5Ns550Instance, recvbuf5, 256);
	XUartNs550_Recv(&Uart6Ns550Instance, recvbuf6, 256);
	XUartNs550_Recv(&Uart7Ns550Instance, recvbuf7, 256);
	XUartNs550_Recv(&Uart8Ns550Instance, recvbuf8, 256);
	XUartNs550_Recv(&Uart9Ns550Instance, recvbuf9, 256);
	XUartNs550_Recv(&Uart10Ns550Instance, recvbuf10, 256);
//	XUartNs550_Recv(&Uart11Ns550Instance, recvbuf, 256);

	while(1)
	{
		sleep(3);

		//FifoRead(&Uart0FIFO,recvbuf,40);
//		FifoRead(&Uart1FIFO,recvbuf1,20);
//		FifoRead(&Uart2FIFO,recvbuf2,20);
//		FifoRead(&Uart3FIFO,recvbuf3,20);
//		FifoRead(&Uart4FIFO,recvbuf4,20);
//		FifoRead(&Uart5FIFO,recvbuf5,20);
//		FifoRead(&Uart6FIFO,recvbuf6,20);
//		FifoRead(&Uart7FIFO,recvbuf7,20);
//		FifoRead(&Uart8FIFO,recvbuf8,20);
//		FifoRead(&Uart9FIFO,recvbuf9,20);
//		FifoRead(&Uart10FIFO,recvbuf10,20);
//		FifoRead(&Uart11FIFO,recvbuf11,20);
		//XUartNs550_ReadReg(XPAR_UARTNS550_0_BASEADDR,0x1000);
	    XUartNs550_Send(&Uart0Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart1Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart2Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart3Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart4Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart5Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart6Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart7Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart8Ns550Instance, sendbuf, 1);
	    XUartNs550_Send(&Uart9Ns550Instance, sendbuf, 10);
	    XUartNs550_Send(&Uart10Ns550Instance, sendbuf, 10);
//	    XUartNs550_Send(&Uart11Ns550Instance, sendbuf, 14);

		if(TotalReceivedCount > 0)
		{
			XUartNs550_Recv(&Uart0Ns550Instance, recvbuf, 256);
			XUartNs550_Recv(&Uart1Ns550Instance, recvbuf1, 256);
			XUartNs550_Recv(&Uart2Ns550Instance, recvbuf2, 256);
			XUartNs550_Recv(&Uart3Ns550Instance, recvbuf3, 256);
			XUartNs550_Recv(&Uart4Ns550Instance, recvbuf4, 256);
			XUartNs550_Recv(&Uart5Ns550Instance, recvbuf5, 256);
			XUartNs550_Recv(&Uart6Ns550Instance, recvbuf6, 256);
			XUartNs550_Recv(&Uart7Ns550Instance, recvbuf7, 256);
			XUartNs550_Recv(&Uart8Ns550Instance, recvbuf8, 256);
			XUartNs550_Recv(&Uart9Ns550Instance, recvbuf9, 256);
			XUartNs550_Recv(&Uart10Ns550Instance, recvbuf10, 256);
			//FifoWrite(&Uart0FIFO,recvbuf,256);
			TotalReceivedCount = 0;
		}

		for(int i=0; i < 20; i++)
		  {xil_printf("%c ",recvbuf[i]);}
		   xil_printf("\r\n");
		for(int i=0; i < 20; i++)
		  {xil_printf("%c ",recvbuf1[i]);}
		   xil_printf("\n\r");
		for(int i=0; i < 20; i++)
		  {xil_printf("%c ",recvbuf2[i]);}
		   xil_printf("\n\r");
		for(int i=0; i < 20; i++)
		   {xil_printf("%c ",recvbuf3[i]);}
			xil_printf("\n\r");
		for(int i=0; i < 20; i++)
			{xil_printf("%c ",recvbuf4[i]);}
		    xil_printf("\n\r");
		for(int i=0; i < 20; i++)
			{xil_printf("%c ",recvbuf5[i]);}
			xil_printf("\n\r");
	    for(int i=0; i < 20; i++)
			{xil_printf("%c ",recvbuf6[i]);}
		     xil_printf("\n\r");
		for(int i=0; i < 20; i++)
			{xil_printf("%c ",recvbuf7[i]);}
			xil_printf("\n\r");
		for(int i=0; i < 10; i++)
			{xil_printf("%c ",recvbuf8[i]);}
			xil_printf("\n\r");
	   for(int i=0; i < 20; i++)
			{xil_printf("%c ",recvbuf9[i]);}
		    xil_printf("\n\r");
		for(int i=0; i < 10; i++)
		    {xil_printf("%c ",recvbuf10[i]);}
		    	xil_printf("\n\r");
//		for(int i=0; i < 20; i++)
//			{xil_printf("%c ",recvbuf11[i]);}
//				xil_printf("\n\r");
		memset(recvbuf,0,256);
		memset(recvbuf1,0,256);
		memset(recvbuf2,0,256);
		memset(recvbuf3,0,256);
		memset(recvbuf4,0,256);
		memset(recvbuf5,0,256);
		memset(recvbuf6,0,256);
		memset(recvbuf7,0,256);
		memset(recvbuf8,0,256);
		memset(recvbuf9,0,256);
		memset(recvbuf10,0,256);
//		memset(recvbuf11,0,20);
	}

}



void Xdma_demo()
{
	int Status;
	int Length;
	u8 rBuffer[256] = {0};
	u8 wBuffer[256] = {0};

	int i;

	dma_init();

    for(i=0;i<256;i++)
    {
    	wBuffer[i]=i+2;
    }
	dma_8_10b_send(&AxiDma,wBuffer,8);
    for(i=0;i<256;i++)
    {
    	wBuffer[i]=i+2;
    }
	dma_8_10b_send(&AxiDma1,wBuffer , 16);
    for(i=0;i<256;i++)
    {
    	wBuffer[i]=i+3;
    }
	dma_8_10b_send(&AxiDma2,wBuffer , 32);
    for(i=0;i<256;i++)
    {
    	wBuffer[i]=i+4;
    }
	dma_8_10b_send(&AxiDma3,wBuffer , 32);

	while(1)
	{
		if(DMA0RxDone == 1)
		{
//			Status = XAxiDma_ReadReg(XPAR_AXI_DMA_0_BASEADDR,0x58);
//						xil_printf("length2 is 0x%x\r\n",Status);
//		    Status = XAxiDma_ReadReg(XPAR_AXI_DMA_0_BASEADDR,0x28);
//						xil_printf("TX length2 is 0x%x\r\n",Status);

			Length = dma_8_10b_recv(&AxiDma,rBuffer);
			xil_printf("length DMA0 is 0x%x\r\n",Length);
			xil_printf("DATE: ");
			for(i=0; i<33; i++)
			{
				xil_printf("%x ",rBuffer[i]);
			}
			xil_printf("\r\n");
			DMA0RxDone = 0;
		}
		if(DMA1RxDone == 1)
		{
			Length = dma_8_10b_recv(&AxiDma1,rBuffer);
		xil_printf("length DMA1 is 0x%x\r\n",Length);

			xil_printf("DATE: ");
			for(i=0; i<33; i++)
			{
				xil_printf("%x ",rBuffer[i]);
			}
			xil_printf("\r\n");
			DMA1RxDone = 0;
		}
		if(DMA2RxDone == 1)
		{
			dma_8_10b_recv(&AxiDma2,rBuffer);
			xil_printf("DATE: ");
			for(i=0; i<33; i++)
			{
				xil_printf("%x ",rBuffer[i]);
			}
			xil_printf("\r\n");
			DMA2RxDone = 0;
		}
		if(DMA3RxDone == 1)
		{
			dma_8_10b_recv(&AxiDma3,rBuffer);
			xil_printf("DATE: ");
			for(i=0; i<33; i++)
			{
				xil_printf("%x ",rBuffer[i]);
			}
			xil_printf("\r\n");
			DMA3RxDone = 0;
		}

	}

}

void LVDS_demo()
{
	int Status;
	u8 rBuffer[256] = {0};
	u8 wBuffer[256] = {0};

	int i;
	unsigned int ret = 0;

	LVDS_init();

//

	while(1)
	{
//
		while(DMA4RxDone != 0)
		{
			ret = LVDS_recv(&AxiDma4,rBuffer);
			//xil_printf("ret=%d\r\n ",ret);
		   // show8();
			xil_printf("DATE: ");
			for(i=0; i<128; i++)
			{
				xil_printf("%x ",rBuffer[i]);
				if(i%16 == 0 && (i != 0))
				{
					xil_printf("\r\n");
				}
			}
			xil_printf("\r\n");
			DMA4RxDone--;
			xil_printf("DMA4RxDone = %d \r\n",DMA4RxDone);
		}
		while(DMA5RxDone != 0)
				{
					ret = LVDS_recv(&AxiDma5,rBuffer);
					//xil_printf("ret=%d\r\n ",ret);
				   // show8();
					xil_printf("DATE: ");
					for(i=0; i<128; i++)
					{
						xil_printf("%x ",rBuffer[i]);
						if(i%16 == 0 && (i != 0))
						{
							xil_printf("\r\n");
						}
					}
					xil_printf("\r\n");
					DMA5RxDone--;
					xil_printf("DMA4RxDone = %d \r\n",DMA5RxDone);
				}

	}

	return XST_SUCCESS;
}

//void show8()
//{
//	int i,rev;
//	 for(i=0; i<32; i++)
//	{
//		rev = Xil_In32(RX_BUFFER_BASE4+i*4);
//		xil_printf("8 address at  %x data is : %x \n\r" ,RX_BUFFER_BASE4+i*4, rev);
//
//	}
//}
//void show9()
//{
//	int i,rec;
//	 for(i=0; i<32; i++)
//	{
//		rec = Xil_In32(RX_BUFFER_BASE5+i*4);
//		xil_printf("9 address at  %x data is : %x \n\r" ,RX_BUFFER_BASE5+i*4, rec);
//	}
//}
