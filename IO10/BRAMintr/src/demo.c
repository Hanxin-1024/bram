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


#include "xuartps.h"
#include "xparameters.h"
#include "bram_driver.h"




void Bram_demo();

//void show8();
//void show9();


extern int TotalReceivedCount;


int main ()
{
xil_printf("start\r\n");
//	count();
//	LVDS_demo();
  Bram_demo();


}



void Bram_demo()
{
	int Status;
	int Length;
	int i;
	Bram_init();

	Bram0sendpacket();
	Bram1sendpacket();
	Bram2sendpacket();
	Bram3sendpacket();

}
void Bram0sendpacket()
{
	int Status;
	int Length;
	int i;
	Bram_init();

		/*初始化发送包内容*/
		for(i = 0;i < 128;i++)
		{
			XBram_Out32(XPAR_BRAM_2_BASEADDR+(i*4),i);
//			Status = XBram_In32(XPAR_BRAM_7_BASEADDR+(i*4));
//			xil_printf("Bram tx value is 0x%x\r\n",Status);
		}

		XBram_Out32(XPAR_BRAM_0_BASEADDR+4,0x100);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8,0x1);

	    sleep(1);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+4,0x10);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8,0x1);

}
void Bram1sendpacket()
{
	int Status;
	int Length;
	int i;
	Bram_init();

		/*初始化发送包内容*/
		for(i = 0;i < 128;i++)
		{
			XBram_Out32(XPAR_BRAM_3_BASEADDR+(i*4),i+1);
//			Status = XBram_In32(XPAR_BRAM_7_BASEADDR+(i*4));
//			xil_printf("Bram tx value is 0x%x\r\n",Status);
		}

		XBram_Out32(XPAR_BRAM_0_BASEADDR+4+16,0x100);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8+16,0x1);

	    sleep(1);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+4+16,0x10);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8+16,0x1);

}
void Bram2sendpacket()
{
	int Status;
	int Length;
	int i;
	Bram_init();

		/*初始化发送包内容*/
		for(i = 0;i < 128;i++)
		{
			XBram_Out32(XPAR_BRAM_5_BASEADDR+(i*4),i+2);
//			Status = XBram_In32(XPAR_BRAM_7_BASEADDR+(i*4));
//			xil_printf("Bram tx value is 0x%x\r\n",Status);
		}

		XBram_Out32(XPAR_BRAM_0_BASEADDR+4+16+16,0x100);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8+16+16,0x1);

	    sleep(1);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+4+16+16,0x10);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8+16+16,0x1);

}
void Bram3sendpacket()
{
	int Status;
	int Length;
	int i;
	Bram_init();

		/*初始化发送包内容*/
		for(i = 0;i < 128;i++)
		{
			XBram_Out32(XPAR_BRAM_7_BASEADDR+(i*4),i+3);
//			Status = XBram_In32(XPAR_BRAM_7_BASEADDR+(i*4));
//			xil_printf("Bram tx value is 0x%x\r\n",Status);
		}

		XBram_Out32(XPAR_BRAM_0_BASEADDR+4+16+16+16,0x100);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8+16+16+16,0x1);

	    sleep(1);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+4+16+16+16,0x10);
	    XBram_Out32(XPAR_BRAM_0_BASEADDR+8+16+16+16,0x1);

}
