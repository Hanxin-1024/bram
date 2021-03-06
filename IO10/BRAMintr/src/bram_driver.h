/*
 * xdma_driver.h
 *
 *  Created on: 2020??12??28??
 *      Author: xin.han
 */

#ifndef SRC_BRAM_DRIVER_H_
#define SRC_BRAM_DRIVER_H_



#include "xaxidma.h"
#include "xparameters.h"
#include "xil_exception.h"
#include "xdebug.h"
#include "xbram.h"
#include <stdio.h>

#ifdef XPAR_UARTNS550_0_BASEADDR
#include "xuartns550_l.h"       /* to use uartns550 */
#endif

#ifdef XPAR_INTC_0_DEVICE_ID
 #include "xintc.h"
#else
 #include "xscugic.h"
#endif

#include "xgpiops.h"

XBram Bram0;
XBram Bram1;
XBram Bram2;
XBram Bram3;

/************************** Constant Definitions *****************************/

/*
 * Device hardware build related constants.
 */

#ifdef XPAR_INTC_0_DEVICE_ID
#define INTC_DEVICE_ID          XPAR_INTC_0_DEVICE_ID
#else
#define INTC_DEVICE_ID          XPAR_SCUGIC_SINGLE_DEVICE_ID
#endif

#ifdef XPAR_INTC_0_DEVICE_ID
 #define INTC		XIntc
 #define INTC_HANDLER	XIntc_InterruptHandler
#else
 #define INTC		XScuGic
 #define INTC_HANDLER	XScuGic_InterruptHandler
#endif



/* Timeout loop counter for reset
 */
#define RESET_TIMEOUT_COUNTER	10000

#define TEST_START_VALUE	0xC
/*
 * Buffer and Buffer Descriptor related constant definition
 */
#define MAX_PKT_LEN		0x100

#define NUMBER_OF_TRANSFERS	10

static XGpioPs Gpio; /* The Instance of the GPIO Driver */

/* The interrupt coalescing threshold and delay timer threshold
 * Valid range is 1 to 255
 *
 * We set the coalescing threshold to be the total number of packets.
 * The receive side will only get one completion interrupt for this example.
 */

/**************************** Type Definitions *******************************/


/***************** Macros (Inline Functions) Definitions *********************/


/************************** Function Prototypes ******************************/
#ifndef DEBUG
extern void xil_printf(const char *format, ...);
#endif

#ifdef XPAR_UARTNS550_0_BASEADDR
 void Uart550_Setup(void);
#endif

static int CheckData(int Length, u8 StartValue);
//static void TxIntrHandler(void *Callback);
//static void RxIntrHandler(void *Callback);


int dma_init(void);
int dma_8_10b_send(XAxiDma* AxiDmaIns,u8 *wBuffer , unsigned int length);
unsigned int dma_8_10b_recv(XAxiDma* AxiDmaIns,u8 *rBuffer);


static int SetupIntrSystem(INTC * IntcInstancePtr,
			   XAxiDma * AxiDmaPtr, u16 TxIntrId, u16 RxIntrId);
static void DisableIntrSystem(INTC * IntcInstancePtr,
					u16 TxIntrId, u16 RxIntrId);

 int SetupInterruptSystem(XScuGic *GicInstancePtr, XGpioPs *Gpio,
				u16 GpioIntrId);

static void Bram0RxIntrHandler();
static void Bram0TxIntrHandler();

/************************** Variable Definitions *****************************/
/*
 * Device instance definitions
 */




static INTC Intc;	/* Instance of the Interrupt Controller */

/*
 * Flags interrupt handlers use to notify the application context the events.
 */
volatile int TxDone;
volatile int DMA0RxDone;
volatile int DMA1RxDone;
volatile int DMA2RxDone;
volatile int DMA3RxDone;
volatile int Error;



#endif /* SRC_BRAM_DRIVER_H_ */
