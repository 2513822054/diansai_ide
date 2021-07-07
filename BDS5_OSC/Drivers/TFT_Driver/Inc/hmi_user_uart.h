#ifndef _USER_UART__
#define _USER_UART__

#include "stm32f4xx_it.h"     //�����û�MCU�����޸�
#include "obase.h"

#define uchar    unsigned char
#define uint8    unsigned char
#define uint16   unsigned short int
#define uint32   unsigned long
#define int16    short int
#define int32    long
#define Tx_MAX_CMD  20     //����ָ��������
#define Tx_MAX_SIZE 4000   //����ָ��������

typedef struct _Tx_STACK
{
	u16 _size[Tx_MAX_CMD];              //Ŀǰ����
	u8  _state[Tx_MAX_CMD];             //0:�� 1:������ 2:װ�����(����+֡β) 3:�������
	u8  _data[Tx_MAX_CMD][Tx_MAX_SIZE];	//�������ݻ�����
}Tx_STACK;

extern u8* TxBuffer;
extern u8 Txing_pos;
/****************************************************************************
* ��    �ƣ� UartInit()
* ��    �ܣ� ���ڳ�ʼ��
* ��ڲ����� ��
* ���ڲ����� ��
****************************************************************************/
void TFT_Init(void);
void Param_Update(void);
/*****************************************************************
* ��    �ƣ� SendChar()
* ��    �ܣ� ����1���ֽ�
* ��ڲ����� t  ���͵��ֽ�
* ���ڲ����� ��
 *****************************************************************/
void  SendChar(uchar t);
u16 Tx_stack_find_cmd(u8 **buffer);

#endif