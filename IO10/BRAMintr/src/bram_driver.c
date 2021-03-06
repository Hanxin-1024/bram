
#include "bram_driver.h"





static void Bram0TxIntrHandler()

{
	int Status;
	int i;

	  for(i = 0; i < 128;i++)
	  {
		Status = XBram_In32(XPAR_BRAM_2_BASEADDR+(i*4));
//		xil_printf("Bram3 tx  value is 0x%x\r\n",Status);
	  }
	  XBram_Out32(XPAR_BRAM_0_BASEADDR+8,0);//清除发送中断
	  xil_printf("TX done\r\n");

//
//	sleep(1);
	return XST_SUCCESS;
}

static void Bram0RxIntrHandler()
{
	int Status;
	int Length;
	int i;

	Length = XBram_In32(XPAR_BRAM_0_BASEADDR+8);//读：接收每包计数，包长
	 xil_printf("Bram0 rx length is 0x%x\r\n",Length);

		for(i = 0; i < Length;i++)
		{
			Status = XBram_In32(XPAR_BRAM_1_BASEADDR+(i*4));
			xil_printf("Bram0 rx value is 0x%x\r\n",Status);

		}
		XBram_Out32(XPAR_BRAM_0_BASEADDR,0x1);
		XBram_Out32(XPAR_BRAM_0_BASEADDR,0);//清除接收中断
}

static void Bram1TxIntrHandler()

{
	int Status;
	int i;

	  for(i = 0; i < 128;i++)
	  {
		Status = XBram_In32(XPAR_BRAM_3_BASEADDR+(i*4));
//		xil_printf("Bram1 tx  value is 0x%x\r\n",Status);
	  }
	  XBram_Out32(XPAR_BRAM_0_BASEADDR+24,0);//清除发送中断
	  xil_printf("TX done\r\n");

//
//	sleep(1);
	return XST_SUCCESS;
}

static void Bram1RxIntrHandler()
{
	int Status;
	int Length;
	int i;

	Length = XBram_In32(XPAR_BRAM_0_BASEADDR+12);//读：接收每包计数，包长
	 xil_printf("Bram1 rx length is 0x%x\r\n",Length);

		for(i = 0; i < Length;i++)
		{
			Status = XBram_In32(XPAR_BRAM_4_BASEADDR+(i*4));
			xil_printf("Bram1 rx value is 0x%x\r\n",Status);

		}
		XBram_Out32(XPAR_BRAM_0_BASEADDR+16,0x1);
		XBram_Out32(XPAR_BRAM_0_BASEADDR+16,0);//清除接收中断
}

static void Bram2TxIntrHandler()

{
	int Status;
	int i;

	  for(i = 0; i < 128;i++)
	  {
		Status = XBram_In32(XPAR_BRAM_5_BASEADDR+(i*4));
//		xil_printf("Bram2 tx  value is 0x%x\r\n",Status);
	  }
	  XBram_Out32(XPAR_BRAM_0_BASEADDR+40,0);//清除发送中断
	  xil_printf("TX done\r\n");

//
//	sleep(1);
	return XST_SUCCESS;
}

static void Bram2RxIntrHandler()
{
	int Status;
	int Length;
	int i;

	Length = XBram_In32(XPAR_BRAM_0_BASEADDR+16);//读：接收每包计数，包长
	 xil_printf("Bram2 rx length is 0x%x\r\n",Length);

		for(i = 0; i < Length;i++)
		{
			Status = XBram_In32(XPAR_BRAM_6_BASEADDR+(i*4));
			xil_printf("Bram2 rx value is 0x%x\r\n",Status);

		}
		XBram_Out32(XPAR_BRAM_0_BASEADDR+32,0x1);
		XBram_Out32(XPAR_BRAM_0_BASEADDR+32,0);//清除接收中断
}


static void Bram3TxIntrHandler()

{
	int Status;
	int i;

	  for(i = 0; i < 128;i++)
	  {
		Status = XBram_In32(XPAR_BRAM_7_BASEADDR+(i*4));
//		xil_printf("Bram3 tx  value is 0x%x\r\n",Status);
	  }
	  XBram_Out32(XPAR_BRAM_0_BASEADDR+56,0);//清除发送中断
	  xil_printf("TX done\r\n");

//
//	sleep(1);
	return XST_SUCCESS;
}

static void Bram3RxIntrHandler()
{
	int Status;
	int Length;
	int i;

	Length = XBram_In32(XPAR_BRAM_0_BASEADDR+20);//读：接收每包计数，包长
	 xil_printf("Bram3 rx length is 0x%x\r\n",Length);

		for(i = 0; i < Length;i++)
		{
			Status = XBram_In32(XPAR_BRAM_8_BASEADDR+(i*4));
			xil_printf("Bram3 rx value is 0x%x\r\n",Status);

		}
		XBram_Out32(XPAR_BRAM_0_BASEADDR+48,0x1);
		XBram_Out32(XPAR_BRAM_0_BASEADDR+48,0);//清除接收中断
}

/*****************************************************************************/
/*
*
* This function setups the interrupt system so interrupts can occur for the
* DMA, it assumes INTC component exists in the hardware system.
*
* @param	IntcInstancePtr is a pointer to the instance of the INTC.
* @param	AxiDmaPtr is a pointer to the instance of the DMA engine
* @param	TxIntrId is the TX channel Interrupt ID.
* @param	RxIntrId is the RX channel Interrupt ID.
*
* @return
*		- XST_SUCCESS if successful,
*		- XST_FAILURE.if not succesful
*
* @note		None.
*
******************************************************************************/

/****************************************************************************/
/**
* This function is the user layer callback function for the bank 0 interrupts of
* the GPIO device. It checks if all the switches have been pressed to stop the
* interrupt processing and exit from the example.
*
* @param	CallBackRef is a pointer to the upper layer callback reference.
* @param	Status is the Interrupt status of the GPIO bank.
*
* @return	None.
*
* @note		None.
*
******************************************************************************/
static void IntrHandler(void *CallBackRef, u32 Bank, u32 Status)
{

	XGpioPs *Gpio = (XGpioPs *)CallBackRef;
	u32 DataRead = 0;;

	/* Push the switch button */

	//DataRead = XGpioPs_ReadPin(Gpio, Input_Pin);
	DataRead = XGpioPs_Read(Gpio, 2);

	xil_printf("0x%x IntrHandler\r\n",DataRead);//GPIOzhongduan
	if ((DataRead & 0x1) == 0x01)
	{
		Bram0RxIntrHandler();
	}
	if((DataRead & 0x2) == 0x02)
	{
		Bram0TxIntrHandler();
	}
	if ((DataRead & 0x4) == 0x04)
	{
		Bram1RxIntrHandler();
	}
	if((DataRead & 0x8) == 0x08)
	{
		Bram1TxIntrHandler();
	}
	if ((DataRead & 0x10) == 0x010)
	{
		Bram2RxIntrHandler();
	}
	if((DataRead & 0x20) == 0x20)
	{
		Bram2TxIntrHandler();
	}
	if ((DataRead & 0x40) == 0x40)
	{
		Bram3RxIntrHandler();
	}
	if((DataRead & 0x80) == 0x080)
	{
		Bram3TxIntrHandler();
	}
	else
	{

	}
}

/*****************************************************************************/
/**
*
* This function sets up the interrupt system for the example. It enables falling
* edge interrupts for all the pins of bank 0 in the GPIO device.
*
* @param	GicInstancePtr is a pointer to the XScuGic driver Instance.
* @param	GpioInstancePtr contains a pointer to the instance of the GPIO
*		component which is going to be connected to the interrupt
*		controller.
* @param	GpioIntrId is the interrupt Id and is typically
*		XPAR_<GICPS>_<GPIOPS_instance>_VEC_ID value from
*		xparameters.h.
*
* @return	XST_SUCCESS if successful, otherwise XST_FAILURE.
*
* @note		None.
*
****************************************************************************/
 int SetupInterruptSystem(XScuGic *GicInstancePtr, XGpioPs *Gpio,
				u16 GpioIntrId)
{
	xil_printf("SetupInterruptSystem\r\n");
	int Status;

	XScuGic_Config *IntcConfig; /* Instance of the interrupt controller */

	Xil_ExceptionInit();

	/*
	 * Initialize the interrupt controller driver so that it is ready to
	 * use.
	 */
	IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);
	if (NULL == IntcConfig) {
		return XST_FAILURE;
	}

	Status = XScuGic_CfgInitialize(GicInstancePtr, IntcConfig,
					IntcConfig->CpuBaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}


	/*
	 * Connect the interrupt controller interrupt handler to the hardware
	 * interrupt handling logic in the processor.
	 */
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT,
				(Xil_ExceptionHandler)XScuGic_InterruptHandler,
				GicInstancePtr);

	/*
	 * Connect the device driver handler that will be called when an
	 * interrupt for the device occurs, the handler defined above performs
	 * the specific interrupt processing for the device.
	 */
	Status = XScuGic_Connect(GicInstancePtr, GpioIntrId,
				(Xil_ExceptionHandler)XGpioPs_IntrHandler,
				(void *)Gpio);
	if (Status != XST_SUCCESS) {
		return Status;
	}

	/* Enable falling edge interrupts for all the pins in bank 0. */
	XGpioPs_SetIntrType(Gpio, 2, 0x00, 0xFFFFFFFF, 0x00);


	/* Set the handler for gpio interrupts. */
	XGpioPs_SetCallbackHandler(Gpio, (void *)Gpio, IntrHandler);


	/* Enable the GPIO interrupts of Bank 2. */
	XGpioPs_IntrEnable(Gpio, 2, 0xFF);


	/* Enable the interrupt for the GPIO device. */
	XScuGic_Enable(GicInstancePtr, GpioIntrId);


	/* Enable interrupts in the Processor. */
	Xil_ExceptionEnableMask(XIL_EXCEPTION_IRQ);

	return XST_SUCCESS;
}



/*****************************************************************************/
/**
*
* This function disables the interrupts for DMA engine.
*
* @param	IntcInstancePtr is the pointer to the INTC component instance
* @param	TxIntrId is interrupt ID associated w/ DMA TX channel
* @param	RxIntrId is interrupt ID associated w/ DMA RX channel
*
* @return	None.
*
* @note		None.
*
******************************************************************************/
static void DisableIntrSystem(INTC * IntcInstancePtr,
					u16 TxIntrId, u16 RxIntrId)
{
#ifdef XPAR_INTC_0_DEVICE_ID
	/* Disconnect the interrupts for the DMA TX and RX channels */
	XIntc_Disconnect(IntcInstancePtr, TxIntrId);
	XIntc_Disconnect(IntcInstancePtr, RxIntrId);
#else
	XScuGic_Disconnect(IntcInstancePtr, TxIntrId);
	XScuGic_Disconnect(IntcInstancePtr, RxIntrId);
#endif
}

int Bram_init(void)
{
	int Status;
	XGpioPs_Config *ConfigPtr;
	xil_printf("\r\n--- Entering Bram init() --- \r\n");

	/* Initialize the Gpio driver. */
	ConfigPtr = XGpioPs_LookupConfig(0);
	if (ConfigPtr == NULL) {
		return XST_FAILURE;
	}
	XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);

	/* Set the direction for the specified pin to be input */
	XGpioPs_SetDirectionPin(&Gpio,54,0);
	XGpioPs_SetDirectionPin(&Gpio,55,0);
	XGpioPs_SetDirectionPin(&Gpio,56,0);
	XGpioPs_SetDirectionPin(&Gpio,57,0);
	XGpioPs_SetDirectionPin(&Gpio,58,0);
	XGpioPs_SetDirectionPin(&Gpio,59,0);
	XGpioPs_SetDirectionPin(&Gpio,60,0);
	XGpioPs_SetDirectionPin(&Gpio,61,0);
	/*
	 * Setup the interrupts such that interrupt processing can occur. If
	 * an error occurs then exit.
	 */
	Status = SetupInterruptSystem(&Intc, &Gpio, XPAR_XGPIOPS_0_INTR);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}


}

