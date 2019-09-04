/*--------Khong duoc phep thay doi-------*/
#define		MAIN_Fosc		12000000L

#include "stc15.h"

union  var16
{
  u16 w;
  u8 b[2];
};

#define BIT0		0x1
#define BIT1		0x2
#define BIT2		0x4
#define BIT3		0x8
#define BIT4		0x10
#define BIT5		0x20
#define BIT6		0x40
#define BIT7		0x80

#define BANK0		0
#define BANK1		1
#define BANK2		2
#define BANK3		3

#define WATCHDOG WDT_CONTR |= D_CLR_WDT


#define EXT0_INT	0
#define TIMER0_INT	1
#define EXT1_INT	2
#define TIMER1_INT	3
#define SERIAL_INT	4
#define TIMER2_INT	5

#define EXT0_MEM	BANK0
#define TIMER0_MEM	BANK1
#define SERIAL_MEM	BANK2
#define TIMER1_MEM	BANK3

#define MOTOR_TIMER_L	TL0
#define MOTOR_TIMER_H	TH0
#define MOTOR_TR		TR0
#define MOTOR_ET		ET0
#define INT_MOTOR		TIMER0_INT
#define MEM_MOTOR		BANK2 

#define	INT_DONG_HO		EXT0_INT
#define	INT_DHO_EX		EX0
#define	INT_DHO_IT		IT0
#define	MEM_DONG_HO		BANK1

#define TIMER_ON	MOTOR_TR = MOTOR_ET = 1
#define TIMER_OFF	MOTOR_TR = MOTOR_ET = 0

#define BYTE_HIGH	0
#define BYTE_LOW	1

