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

//#include "count.h"
#include "Fire.h"
#include "LVDS_driver.h"
//#include "Uart_driver.h"
//#include "xdma_driver.h"
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
xil_printf("start\r\n");
//	count();
	LVDS_demo();
//	Xdma_demo();
//    Uart_demo();
//	speed_demo();
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
					xil_printf("DMA5RxDone = %d \r\n",DMA5RxDone);
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

