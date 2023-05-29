/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 14 May , 2023
* SWC     : LED Matrix
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "LEDMATRIX_interface.h"
#include "LEDMATRIX_private.h"
#include "LEDMATRIX_config.h"

void HLEDMATRIX_voidInit()
{
		/*** set the rows and columns pins as output mode ***/
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R0_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R1_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R2_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R3_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R4_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R5_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R6_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R7_PIN,GPIO_MODE_OUTPUT);

	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C0_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C1_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C2_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C3_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C4_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C5_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C6_PIN,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C7_PIN,GPIO_MODE_OUTPUT);

		/***set rows and columns pins output mode ***/
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R0_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R1_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R2_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R3_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R4_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R5_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R6_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R7_PIN,OUTPUT_PUSH_PULL);
 
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C0_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C1_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C2_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C3_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C4_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C5_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C6_PIN,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C7_PIN,OUTPUT_PUSH_PULL);

	/*** set rows and columns pins speed ***/
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R0_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R1_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R2_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R3_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R4_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R5_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R6_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_ROW_PORT,HLEDMATRIX_R7_PIN,MEDIUM_SPEED);

	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C0_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C1_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C2_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C3_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C4_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C5_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C6_PIN,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C7_PIN,MEDIUM_SPEED);
	
}
static void HLEDMATRIX_voidDisableAllCols()
{
		/*** Disable all cols ***/
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C0_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C1_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C2_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C3_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C4_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C5_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C6_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,HLEDMATRIX_C7_PIN,GPIO_HIGH);
}

void HLEDMATRIX_voidDisplay(u8 *Copy_pu8Data)
{	
	u8 Local_u8ColumnIndex = 0;
	u8 Local_u8RowIndex = 0;
	u8 Local_u8Bit = 0;
	/* 3mlna el array dol 34an lw el pins msh wra b3d */
	static u8 Local_RowsArray[8] = {HLEDMATRIX_R0_PIN,HLEDMATRIX_R1_PIN,HLEDMATRIX_R2_PIN,HLEDMATRIX_R3_PIN,HLEDMATRIX_R4_PIN,HLEDMATRIX_R5_PIN,HLEDMATRIX_R6_PIN,HLEDMATRIX_R7_PIN};
	static u8 Local_ColumnsArray[8] = {HLEDMATRIX_C0_PIN,HLEDMATRIX_C1_PIN,HLEDMATRIX_C2_PIN,HLEDMATRIX_C3_PIN,HLEDMATRIX_C4_PIN,HLEDMATRIX_C5_PIN,HLEDMATRIX_C6_PIN,HLEDMATRIX_C7_PIN};
	for(Local_u8ColumnIndex = 0;Local_u8ColumnIndex<8;Local_u8ColumnIndex++)
	{
		HLEDMATRIX_voidDisableAllCols();
		for(Local_u8RowIndex = 0;Local_u8RowIndex<8;Local_u8RowIndex++)
		{
			Local_u8Bit = GET_BIT(Copy_pu8Data[Local_u8ColumnIndex],Local_u8RowIndex);
			MGPIO_voidSetPinValue(HLEDMATRIX_ROW_PORT,Local_RowsArray[Local_u8RowIndex],Local_u8Bit);
		}
		MGPIO_voidSetPinValue(HLEDMATRIX_COLUMN_PORT,Local_ColumnsArray[Local_u8ColumnIndex],GPIO_LOW);
		MSTK_voidSetBusyWait(500);
	}
}