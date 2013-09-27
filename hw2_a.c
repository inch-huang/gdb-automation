#include "hw2_a.h"
#include "stm32f10x.h"

void ShowString()
{
	USART_SendData(USART2, 'H');
	USART_SendData(USART2, 'e');
	USART_SendData(USART2, 'l');
	USART_SendData(USART2, 'l');
	USART_SendData(USART2, 'o');
	USART_SendData(USART2, '!');	
}

void USART2_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	//enable clocks
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	//Set USART2 Tx (PA.02) as AF-PP
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	//Set USART2 Rx (PA.03) as Input Floating
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx; 
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	//Write USART2 parameters
	USART_Init(USART2, &USART_InitStructure);
	//Enable USART2
	USART_Cmd(USART2, ENABLE);

}


