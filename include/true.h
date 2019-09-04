#include"common.h"

#define True_device		1

#define		PORT_KEY	P3
#define		PORT_OUT 	P2
#define		PORT_LCD 	P0
#define		KEY_MASK	0x38
#define		PORT_MASK	0xf8
#define		MOTOR_TRUE		1
#define		MOTOR_FALSE		0


#define P3_save	ACC = 0x77;  AccSimPw = sim_pw_out; P3 = ACC
#define P2_save	P2 = 0xff
#define P1_save	ACC = 0x30; AccMotor = motor_out; AccRlay = TimerRelay_out; P1 = ACC
#define P0_save	ACC = 0x10; AccMpPw = mp3_power_out; AccMpStop = mp3_stop_out; AccMpInc = mp3_inc_out; P0 = ACC

/*********** Keys ***************/
#define		key_in1		P35
#define		key_in2		P33
#define		key_in3		P34

/************ CAMS ******************/
#define		cam_sign	P36
#define		zero_sign	P37

/*********** DALAS ***************/
#define		clock_in	P32
#define		sda_bit		P40
#define		scl_bit		P55

/************ MOTOR STATUS ******************/
#define		motor_run_sign	P41

/************ LED ******************/
#define		over_cur_led	P07

/************ LCD ******************/
#define		lcd_pw		P06
#define		LCD_rs		P05
#define		LCD_en		P04

#define		LCD_D4		P03
#define		LCD_D5		P02
#define		LCD_D6		P01
#define		LCD_D7		P00

/*********** Timer ***************/
#define		TimerRelay		P21
#define		ChargeRelay		P22
#define		RingRelay		P23
#define		sim_pw_ACC			ACC0
#define		TimerRelay_ACC		ACC1
#define		ChargeRelay_ACC		ACC2
#define		RingRelay_ACC		ACC3

/*********** MOTORS DC ***************/
// Timer 0 = motor control

#define		motorA0		P43
#define		motorA1		P44

#define		MotorDirection()	out_motorA0 = motorA0 = !motorDir; out_motorA1 = motorA1 = motorDir;MP3PowerRelay = MP3PowerRelay_out;
#define		MotorThuan()	out_motorA0 = motorA0 = 0; out_motorA1 = motorA1 = 1;MP3PowerRelay = MP3PowerRelay_out
#define		MotorNghich()	out_motorA0 = motorA0 = 1; out_motorA1 = motorA1 = 0;MP3PowerRelay = MP3PowerRelay_out
#define		MotorDung()		out_motorA0 = out_motorA1 = motorA0 = motorA1 = 0;MP3PowerRelay = MP3PowerRelay_out

/*********** MOTORS STEP ***************/
//D7	Orange	1	1	0	0	0	0	0	1
//D6	Yellow	0	1	1	1	0	0	0	0
//D4	Pink	0	0	0	1	1	1	0	0
//D3	Blue	0	0	0	0	0	1	1	1

u8 __code step_out[] = {
	0x10,0x30,0x20,0x60,0x40,0xC0,0x80,0x90
	};
#define STOP_COMM	0x0f
#define OFF_COMM	0x00
#define STEP_MASK	0xf0


#define off_motor  EA = 0; ACC = OFF_COMM; RingRelay_ACC = RingRelay_out; ChargeRelay_ACC = ChargeRelay_out; TimerRelay_ACC = TimerRelay_out; sim_pw_ACC = sim_pw_out; P2 = ACC; EA = 1
#define motor_output EA = 0; ACC = step_out[stindex]; RingRelay_ACC = RingRelay_out; ChargeRelay_ACC = ChargeRelay_out; TimerRelay_ACC = TimerRelay_out; sim_pw_ACC = sim_pw_out; P2 = ACC; EA = 1

#define motor_stop EA = 0; RingRelay_ACC = RingRelay_out; ChargeRelay_ACC = ChargeRelay_out; TimerRelay_ACC = TimerRelay_out; sim_pw_ACC = sim_pw_out; P2 = ACC; EA = 1
#define ini_motor0 EA = 0; ACC = step_out[0]; RingRelay_ACC = RingRelay_out; ChargeRelay_ACC = ChargeRelay_out; TimerRelay_ACC = TimerRelay_out; sim_pw_ACC = sim_pw_out; P2 = ACC; EA = 1
#define ini_motor7 EA = 0; ACC = step_out[7]; RingRelay_ACC = RingRelay_out; ChargeRelay_ACC = ChargeRelay_out; TimerRelay_ACC = TimerRelay_out; sim_pw_ACC = sim_pw_out; P2 = ACC; EA = 1

/********* ADC chanel**********/

#define		BATTERY_CH		0x03
#define		STEP_MOTOR_CH	0x04
#define		DC_MOTOR_CH		0x05

#define		VBAT_ADC_BIT		BIT3
#define		STEPMOTOR_ADC_BIT	BIT4
#define		DCMOTOR_ADC_BIT		BIT5

/*********** ADC Chanel select***************/

#define		DC_MOTOR_SEL	0x00
#define		STEP_MOTOR_SEL	0x01
#define		BATTERY_SEL		0x03
#define		VCCPW_SEL		0x05


/*********** Sim 900 ***************/
#define		sim_pw			P20
// Baurate general = Timer 1
#define		sim_RI			RI
#define		sim_TI			TI
#define		sim_SBUF		SBUF

#define		SIM_BAUD		9600


/*********** MP3 ***************/
// Baurate general = Timer 2
#define		Mp3_busy		P12
#define		MP3PowerRelay	P42
#define		mp3_RI			RI2
#define		mp3_TI			TI2
#define		mp3_SBUF		S2BUF
#define		mp3_RI_set()	S2CON |=  1	
#define		mp3_RI_clear()	S2CON &=  ~1
#define		mp3_TI_clear()	S2CON &=  ~2
#define		mp3_TI_set()	S2CON |=  2

#define		MP3_BAUD		9600


#ifdef DC_MOTOR
	#define	cam_sign_out	cam_out1
	#define	zero_sign_out	cam_out2
#endif

#ifdef STEP_MOTOR
	#define	cam_sign_out	cam_out2
	#define	zero_sign_out	cam_out1
#endif



/********** Eeprom *****************/

//#define ENABLE_IAP 0x80 //if SYSCLK<30MHz
//#define ENABLE_IAP 0x81 //if SYSCLK<24MHz
//#define ENABLE_IAP 0x82 //if SYSCLK<20MHz
#define ENABLE_IAP 0x83 //if SYSCLK<12MHz
//#define ENABLE_IAP 0x84 //if SYSCLK<6MHz
//#define ENABLE_IAP 0x85 //if SYSCLK<3MHz
//#define ENABLE_IAP 0x86 //if SYSCLK<2MHz
//#define ENABLE_IAP 0x87 //if SYSCLK<1MHz

#define IAP_ADDRESS 0x0400
