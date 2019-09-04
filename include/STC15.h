#ifndef STC15Fxx_H
#define STC15Fxx_H

#include <compiler.h>

// 包含本头文件后,不用另外再包含"REG51.H"
// 适用于 STC15Wxx / STC15Fxx 系列的芯片
// Modified based on STC-ISP version by: ZnHoCn

/////////////////////////////////////////////////
//注意: STC15W4K32S4系列的芯片,上电后所有与PWM相关的IO口均为
//      高阻态,需将这些口设置为准双向口或强推挽模式方可正常使用
//相关IO: P0.6/P0.7/P1.6/P1.7/P2.1/P2.2
//        P2.3/P2.7/P3.7/P4.2/P4.4/P4.5
/////////////////////////////////////////////////

//内核特殊功能寄存器    //复位值    描述
#define _ACC 0xE0
SFR(ACC, 0xE0);         //0000,0000 累加器Accumulator
#define _B 0xF0
SFR(B, 0xF0);           //0000,0000 B寄存器
#define _PSW 0xD0
SFR(PSW, 0xD0);         //0000,0000 程序状态字
SBIT(CY, _PSW, 7);
SBIT(AC, _PSW, 6);
SBIT(F0, _PSW, 5);
SBIT(RS1, _PSW, 4);
SBIT(RS0, _PSW, 3);
SBIT(OV, _PSW, 2);
SBIT(F1, _PSW, 1);
SBIT(P, _PSW, 0);
#define _SP 0x81
SFR(SP, 0x81);          //0000,0111 堆栈指针
#define _DPL 0x82
SFR(DPL, 0x82);         //0000,0000 数据指针低字节
#define _DPH 0x83
SFR(DPH, 0x83);         //0000,0000 数据指针高字节

//I/O 口特殊功能寄存器
#define _P0 0x80
SFR(P0, 0x80);          //1111,1111 端口0
SBIT(P00, _P0, 0);
SBIT(P01, _P0, 1);
SBIT(P02, _P0, 2);
SBIT(P03, _P0, 3);
SBIT(P04, _P0, 4);
SBIT(P05, _P0, 5);
SBIT(P06, _P0, 6);
SBIT(P07, _P0, 7);
#define _P1 0x90
SFR(P1, 0x90);          //1111,1111 端口1
SBIT(P10, _P1, 0);
SBIT(P11, _P1, 1);
SBIT(P12, _P1, 2);
SBIT(P13, _P1, 3);
SBIT(P14, _P1, 4);
SBIT(P15, _P1, 5);
SBIT(P16, _P1, 6);
SBIT(P17, _P1, 7);
SBIT(RXD2,_P1,0);
SBIT(TXD2,_P1,1);
SBIT(CCP1,_P1,0);
SBIT(CCP0,_P1,1);
SBIT(SPI_SS,_P1,2);
SBIT(SPI_MOSI,_P1,3);
SBIT(SPI_MISO,_P1,4);
SBIT(SPI_SCLK,_P1,5);
#define _P2 0xA0
SFR(P2, 0xA0);          //1111,1111 端口2
SBIT(P20, _P2, 0);
SBIT(P21, _P2, 1);
SBIT(P22, _P2, 2);
SBIT(P23, _P2, 3);
SBIT(P24, _P2, 4);
SBIT(P25, _P2, 5);
SBIT(P26, _P2, 6);
SBIT(P27, _P2, 7);
#define _P3 0xB0
SFR(P3, 0xB0);          //1111,1111 端口3
SBIT(P30, _P3, 0);
SBIT(P31, _P3, 1);
SBIT(P32, _P3, 2);
SBIT(P33, _P3, 3);
SBIT(P34, _P3, 4);
SBIT(P35, _P3, 5);
SBIT(P36, _P3, 6);
SBIT(P37, _P3, 7);
SBIT(RXD,_P3,0);
SBIT(TXD,_P3,1);
SBIT(INT0,_P3,2);
SBIT(INT1,_P3,3);
SBIT(T0,_P3,4);
SBIT(T1,_P3,5);
SBIT(WR,_P3,6);
SBIT(RD,_P3,7);
SBIT(CCP2,_P3,7);

SBIT(CLKOUT0,_P3,5);
SBIT(CLKOUT1,_P3,4);
#define _P4 0xC0
SFR(P4, 0xC0);          //1111,1111 端口4
SBIT(P40, _P4, 0);
SBIT(P41, _P4, 1);
SBIT(P42, _P4, 2);
SBIT(P43, _P4, 3);
SBIT(P44, _P4, 4);
SBIT(P45, _P4, 5);
SBIT(P46, _P4, 6);
SBIT(P47, _P4, 7);
#define _P5 0xC8
SFR(P5, 0xC8);          //xxxx,1111 端口5
SBIT(P50, _P5, 0);
SBIT(P51, _P5, 1);
SBIT(P52, _P5, 2);
SBIT(P53, _P5, 3);
SBIT(P54, _P5, 4);
SBIT(P55, _P5, 5);
SBIT(P56, _P5, 6);
SBIT(P57, _P5, 7);
#define _P6 0xE8
SFR(P6, 0xE8);          //0000,0000 端口6
SBIT(P60, _P6, 0);
SBIT(P61, _P6, 1);
SBIT(P62, _P6, 2);
SBIT(P63, _P6, 3);
SBIT(P64, _P6, 4);
SBIT(P65, _P6, 5);
SBIT(P66, _P6, 6);
SBIT(P67, _P6, 7);
#define _P7 0xF8
SFR(P7, 0xF8);          //0000,0000 端口7
SBIT(P70, _P7, 0);
SBIT(P71, _P7, 1);
SBIT(P72, _P7, 2);
SBIT(P73, _P7, 3);
SBIT(P74, _P7, 4);
SBIT(P75, _P7, 5);
SBIT(P76, _P7, 6);
SBIT(P77, _P7, 7);

#define _P0M0 0x94
SFR(P0M0, 0x94);        //0000,0000 端口0模式寄存器0
#define _P0M1 0x93
SFR(P0M1, 0x93);        //0000,0000 端口0模式寄存器1
#define _P1M0 0x92
SFR(P1M0, 0x92);        //0000,0000 端口1模式寄存器0
#define _P1M1 0x91
SFR(P1M1, 0x91);        //0000,0000 端口1模式寄存器1
#define _P2M0 0x96
SFR(P2M0, 0x96);        //0000,0000 端口2模式寄存器0
#define _P2M1 0x95
SFR(P2M1, 0x95);        //0000,0000 端口2模式寄存器1
#define _P3M0 0xB2
SFR(P3M0, 0xB2);        //0000,0000 端口3模式寄存器0
#define _P3M1 0xB1
SFR(P3M1, 0xB1);        //0000,0000 端口3模式寄存器1
#define _P4M0 0xB4
SFR(P4M0, 0xB4);        //0000,0000 端口4模式寄存器0
#define _P4M1 0xB3
SFR(P4M1, 0xB3);        //0000,0000 端口4模式寄存器1
#define _P5M0 0xCA
SFR(P5M0, 0xCA);        //0000,0000 端口5模式寄存器0
#define _P5M1 0xC9
SFR(P5M1, 0xC9);        //0000,0000 端口5模式寄存器1
#define _P6M0 0xCC
SFR(P6M0, 0xCC);        //0000,0000 端口6模式寄存器0
#define _P6M1 0xCB
SFR(P6M1, 0xCB);        //0000,0000 端口6模式寄存器1
#define _P7M0 0xE2
SFR(P7M0, 0xE2);        //0000,0000 端口7模式寄存器0
#define _P7M1 0xE1
SFR(P7M1, 0xE1);        //0000,0000 端口7模式寄存器1

//系统管理特殊功能寄存器
#define _PCON 0x87
SFR(PCON, 0x87);        //0001,0000 电源控制寄存器
#define _AUXR 0x8E
SFR(AUXR, 0x8E);        //0000,0000 辅助寄存器
SFR(AUXR2,0X8F);
#define _AUXR1 0xA2
SFR(AUXR1, 0xA2);       //0000,0000 辅助寄存器1
#define _P_SW1 0xA2
SFR(P_SW1, 0xA2);       //0000,0000 外设端口切换寄存器1
#define _CLK_DIV 0x97
SFR(CLK_DIV, 0x97);     //0000,0000 时钟分频控制寄存器
SFR(PCON2,0X97);
#define _BUS_SPEED 0xA1
SFR(BUS_SPEED, 0xA1);   //xx10,x011 总线速度控制寄存器
#define _P1ASF 0x9D
SFR(P1ASF, 0x9D);       //0000,0000 端口1模拟功能配置寄存器
#define _P_SW2 0xBA
SFR(P_SW2, 0xBA);       //0xxx,x000 外设端口切换寄存器

//中断特殊功能寄存器
#define _IE 0xA8
SFR(IE, 0xA8);          //0000,0000 中断控制寄存器
SBIT(EA, _IE, 7);
SBIT(ELVD, _IE, 6);
SBIT(EADC, _IE, 5);
SBIT(ES, _IE, 4);
SBIT(ET1, _IE, 3);
SBIT(EX1, _IE, 2);
SBIT(ET0, _IE, 1);
SBIT(EX0, _IE, 0);
#define _IP 0xB8
SFR(IP, 0xB8);          //0000,0000 中断优先级寄存器
SBIT(PPCA, _IP, 7);
SBIT(PLVD, _IP, 6);
SBIT(PADC, _IP, 5);
SBIT(PS, _IP, 4);
SBIT(PT1, _IP, 3);
SBIT(PX1, _IP, 2);
SBIT(PT0, _IP, 1);
SBIT(PX0, _IP, 0);
#define _IE2 0xAF
SFR(IE2, 0xAF);         //0000,0000 中断控制寄存器2
#define _IP2 0xB5
SFR(IP2, 0xB5);         //xxxx,xx00 中断优先级寄存器2
#define _INT_CLKO 0x8F
SFR(INT_CLKO, 0x8F);    //0000,0000 外部中断与时钟输出控制寄存器

//定时器特殊功能寄存器
#define _TCON 0x88
SFR(TCON, 0x88);        //0000,0000 T0/T1控制寄存器
SBIT(TF1, _TCON, 7);
SBIT(TR1, _TCON, 6);
SBIT(TF0, _TCON, 5);
SBIT(TR0, _TCON, 4);
SBIT(IE1, _TCON, 3);
SBIT(IT1, _TCON, 2);
SBIT(IE0, _TCON, 1);
SBIT(IT0, _TCON, 0);
#define _TMOD 0x89
SFR(TMOD, 0x89);        //0000,0000 T0/T1模式寄存器
#define _TL0 0x8A
SFR(TL0, 0x8A);         //0000,0000 T0低字节
#define _TL1 0x8B
SFR(TL1, 0x8B);         //0000,0000 T1低字节
#define _TH0 0x8C
SFR(TH0, 0x8C);         //0000,0000 T0高字节
#define _TH1 0x8D
SFR(TH1, 0x8D);         //0000,0000 T1高字节
#define _T4T3M 0xD1
SFR(T4T3M, 0xD1);       //0000,0000 T3/T4模式寄存器
// #default _T3T4M 0xD1
// SFR(T3T4M, 0xD1);    //0000,0000 T3/T4模式寄存器
#define _T4H 0xD2
SFR(T4H, 0xD2);         //0000,0000 T4高字节
#define _T4L 0xD3
SFR(T4L, 0xD3);         //0000,0000 T4低字节
#define _T3H 0xD4
SFR(T3H, 0xD4);         //0000,0000 T3高字节
#define _T3L 0xD5
SFR(T3L, 0xD5);         //0000,0000 T3低字节
#define _T2H 0xD6
SFR(T2H, 0xD6);         //0000,0000 T2高字节
#define _T2L 0xD7
SFR(T2L, 0xD7);         //0000,0000 T2低字节
#define _WKTCL 0xAA
SFR(WKTCL, 0xAA);       //0000,0000 掉电唤醒定时器低字节
#define _WKTCH 0xAB
SFR(WKTCH, 0xAB);       //0000,0000 掉电唤醒定时器高字节
#define _WDT_CONTR 0xC1
SFR(WDT_CONTR, 0xC1);   //0000,0000 看门狗控制寄存器

//串行口特殊功能寄存器
#define _SCON 0x98
SFR(SCON, 0x98);        //0000,0000 串口1控制寄存器
SBIT(SM0, _SCON, 7);
SBIT(SM1, _SCON, 6);
SBIT(SM2, _SCON, 5);
SBIT(REN, _SCON, 4);
SBIT(TB8, _SCON, 3);
SBIT(RB8, _SCON, 2);
SBIT(TI, _SCON, 1);
SBIT(RI, _SCON, 0);
#define _SBUF 0x99
SFR(SBUF, 0x99);        //xxxx,xxxx 串口1数据寄存器
#define _S2CON 0x9A
SFR(S2CON, 0x9A);       //0000,0000 串口2控制寄存器
#define _S2BUF 0x9B
SFR(S2BUF, 0x9B);       //xxxx,xxxx 串口2数据寄存器
#define _S3CON 0xAC
SFR(S3CON, 0xAC);       //0000,0000 串口3控制寄存器
#define _S3BUF 0xAD
SFR(S3BUF, 0xAD);       //xxxx,xxxx 串口3数据寄存器
#define _S4CON 0x84
SFR(S4CON, 0x84);       //0000,0000 串口4控制寄存器
#define _S4BUF 0x85
SFR(S4BUF, 0x85);       //xxxx,xxxx 串口4数据寄存器
SFR(SPIDAT,0X86);
#define _SADDR 0xA9
SFR(SADDR, 0xA9);       //0000,0000 从机地址寄存器
#define _SADEN 0xB9
SFR(SADEN, 0xB9);       //0000,0000 从机地址屏蔽寄存器
SFR(BRT,0X9C);
//ADC 特殊功能寄存器
#define _ADC_CONTR 0xBC
SFR(ADC_CONTR, 0xBC);   //0000,0000 A/D转换控制寄存器
#define _ADC_RES 0xBD
SFR(ADC_RES, 0xBD);     //0000,0000 A/D转换结果高8位
#define _ADC_RESL 0xBE
SFR(ADC_RESL, 0xBE);    //0000,0000 A/D转换结果低2位

//SPI 特殊功能寄存器
#define _SPSTAT 0xCD
SFR(SPSTAT, 0xCD);      //00xx,xxxx SPI状态寄存器
#define _SPCTL 0xCE
SFR(SPCTL, 0xCE);       //0000,0100 SPI控制寄存器
#define _SPDAT 0xCF
SFR(SPDAT, 0xCF);       //0000,0000 SPI数据寄存器

//IAP/ISP 特殊功能寄存器
#define _IAP_DATA 0xC2
SFR(IAP_DATA, 0xC2);    //0000,0000 EEPROM数据寄存器
#define _IAP_ADDRH 0xC3
SFR(IAP_ADDRH, 0xC3);   //0000,0000 EEPROM地址高字节
#define _IAP_ADDRL 0xC4
SFR(IAP_ADDRL, 0xC4);   //0000,0000 EEPROM地址第字节
#define _IAP_CMD 0xC5
SFR(IAP_CMD, 0xC5);     //xxxx,xx00 EEPROM命令寄存器
#define _IAP_TRIG 0xC6
SFR(IAP_TRIG, 0xC6);    //0000,0000 EEPRPM命令触发寄存器
#define _IAP_CONTR 0xC7
SFR(IAP_CONTR, 0xC7);   //0000,x000 EEPROM控制寄存器

//PCA/PWM 特殊功能寄存器
#define _CCON 0xD8
SFR(CCON, 0xD8);        //00xx,xx00 PCA控制寄存器
SBIT(CF, _CCON, 7);
SBIT(CR, _CCON, 6);
SBIT(CCF2, _CCON, 2);
SBIT(CCF1, _CCON, 1);
SBIT(CCF0, _CCON, 0);
#define _CMOD 0xD9
SFR(CMOD, 0xD9);        //0xxx,x000 PCA 工作模式寄存器
#define _CL 0xE9
SFR(CL, 0xE9);          //0000,0000 PCA计数器低字节
#define _CH 0xF9
SFR(CH, 0xF9);          //0000,0000 PCA计数器高字节
#define _CCAPM0 0xDA
SFR(CCAPM0, 0xDA);      //0000,0000 PCA模块0的PWM寄存器
#define _CCAPM1 0xDB
SFR(CCAPM1, 0xDB);      //0000,0000 PCA模块1的PWM寄存器
#define _CCAPM2 0xDC
SFR(CCAPM2, 0xDC);      //0000,0000 PCA模块2的PWM 寄存器
#define _CCAP0L 0xEA
SFR(CCAP0L, 0xEA);      //0000,0000 PCA模块0的捕捉/比较寄存器低字节
#define _CCAP1L 0xEB
SFR(CCAP1L, 0xEB);      //0000,0000 PCA模块1的捕捉/比较寄存器低字节
#define _CCAP2L 0xEC
SFR(CCAP2L, 0xEC);      //0000,0000 PCA模块2的捕捉/比较寄存器低字节
#define _PCA_PWM0 0xF2
SFR(PCA_PWM0, 0xF2);    //xxxx,xx00 PCA模块0的PWM寄存器
#define _PCA_PWM1 0xF3
SFR(PCA_PWM1, 0xF3);    //xxxx,xx00 PCA模块1的PWM寄存器
#define _PCA_PWM2 0xF4
SFR(PCA_PWM2, 0xF4);    //xxxx,xx00 PCA模块1的PWM寄存器
#define _CCAP0H 0xFA
SFR(CCAP0H, 0xFA);      //0000,0000 PCA模块0的捕捉/比较寄存器高字节
#define _CCAP1H 0xFB
SFR(CCAP1H, 0xFB);      //0000,0000 PCA模块1的捕捉/比较寄存器高字节
#define _CCAP2H 0xFC
SFR(CCAP2H, 0xFC);      //0000,0000 PCA模块2的捕捉/比较寄存器高字节

//比较器特殊功能寄存器
#define _CMPCR1 0xE6
SFR(CMPCR1, 0xE6);      //0000,0000 比较器控制寄存器1
#define _CMPCR2 0xE7
SFR(CMPCR2, 0xE7);      //0000,0000 比较器控制寄存器2

//增强型PWM波形发生器特殊功能寄存器
#define _PWMCFG 0xF1
SFR(PWMCFG, 0xF1);      //x000,0000 PWM配置寄存器
#define _PWMCR 0xF5
SFR(PWMCR, 0xF5);       //0000,0000 PWM控制寄存器
#define _PWMIF 0xF6
SFR(PWMIF, 0xF6);       //x000,0000 PWM中断标志寄存器
#define _PWMFDCR 0xF7
SFR(PWMFDCR, 0xF7);     //xx00,0000 PWM外部异常检测控制寄存器

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
#define PWMC        (*(unsigned int  volatile xdata *)0xfff0)
#define PWMCH       (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL       (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS      (*(unsigned char volatile xdata *)0xfff2)
#define PWM2T1      (*(unsigned int  volatile xdata *)0xff00)
#define PWM2T1H     (*(unsigned char volatile xdata *)0xff00)
#define PWM2T1L     (*(unsigned char volatile xdata *)0xff01)
#define PWM2T2      (*(unsigned int  volatile xdata *)0xff02)
#define PWM2T2H     (*(unsigned char volatile xdata *)0xff02)
#define PWM2T2L     (*(unsigned char volatile xdata *)0xff03)
#define PWM2CR      (*(unsigned char volatile xdata *)0xff04)
#define PWM3T1      (*(unsigned int  volatile xdata *)0xff10)
#define PWM3T1H     (*(unsigned char volatile xdata *)0xff10)
#define PWM3T1L     (*(unsigned char volatile xdata *)0xff11)
#define PWM3T2      (*(unsigned int  volatile xdata *)0xff12)
#define PWM3T2H     (*(unsigned char volatile xdata *)0xff12)
#define PWM3T2L     (*(unsigned char volatile xdata *)0xff13)
#define PWM3CR      (*(unsigned char volatile xdata *)0xff14)
#define PWM4T1      (*(unsigned int  volatile xdata *)0xff20)
#define PWM4T1H     (*(unsigned char volatile xdata *)0xff20)
#define PWM4T1L     (*(unsigned char volatile xdata *)0xff21)
#define PWM4T2      (*(unsigned int  volatile xdata *)0xff22)
#define PWM4T2H     (*(unsigned char volatile xdata *)0xff22)
#define PWM4T2L     (*(unsigned char volatile xdata *)0xff23)
#define PWM4CR      (*(unsigned char volatile xdata *)0xff24)
#define PWM5T1      (*(unsigned int  volatile xdata *)0xff30)
#define PWM5T1H     (*(unsigned char volatile xdata *)0xff30)
#define PWM5T1L     (*(unsigned char volatile xdata *)0xff31)
#define PWM5T2      (*(unsigned int  volatile xdata *)0xff32)
#define PWM5T2H     (*(unsigned char volatile xdata *)0xff32)
#define PWM5T2L     (*(unsigned char volatile xdata *)0xff33)
#define PWM5CR      (*(unsigned char volatile xdata *)0xff34)
#define PWM6T1      (*(unsigned int  volatile xdata *)0xff40)
#define PWM6T1H     (*(unsigned char volatile xdata *)0xff40)
#define PWM6T1L     (*(unsigned char volatile xdata *)0xff41)
#define PWM6T2      (*(unsigned int  volatile xdata *)0xff42)
#define PWM6T2H     (*(unsigned char volatile xdata *)0xff42)
#define PWM6T2L     (*(unsigned char volatile xdata *)0xff43)
#define PWM6CR      (*(unsigned char volatile xdata *)0xff44)
#define PWM7T1      (*(unsigned int  volatile xdata *)0xff50)
#define PWM7T1H     (*(unsigned char volatile xdata *)0xff50)
#define PWM7T1L     (*(unsigned char volatile xdata *)0xff51)
#define PWM7T2      (*(unsigned int  volatile xdata *)0xff52)
#define PWM7T2H     (*(unsigned char volatile xdata *)0xff52)
#define PWM7T2L     (*(unsigned char volatile xdata *)0xff53)
#define PWM7CR      (*(unsigned char volatile xdata *)0xff54)


//user-defined

#define		SPI_INT_ENABLE()		IE2 |=  2	
#define		SPI_INT_DISABLE()		IE2 &= ~2	
#define		UART2_INT_ENABLE()		IE2 |=  1	
#define		UART2_INT_DISABLE()		IE2 &= ~1

#define		PPCAH	0x80
#define		PLVDH	0x40
#define		PADCH	0x20
#define		PSH		0x10
#define		PT1H	0x08
#define		PX1H	0x04
#define		PT0H	0x02
#define		PX0H	0x01

#define		PCA_InterruptFirst()	PPCA = 1
#define		LVD_InterruptFirst()	PLVD = 1
#define		ADC_InterruptFirst()	PADC = 1
#define		UART1_InterruptFirst()	PS   = 1
#define		Timer1_InterruptFirst()	PT1  = 1
#define		INT1_InterruptFirst()	PX1  = 1
#define		Timer0_InterruptFirst()	PT0  = 1
#define		INT0_InterruptFirst()	PX0  = 1

#define		S1_DoubleRate()		PCON |= 0x80
#define		S1_SHIFT()			SCON &= 0x3f
#define		S1_8bit()			SCON  = (SCON & 0x3f) | 0x40
#define		S1_9bit()			SCON  = (SCON & 0x3f) | 0xc0
#define		S1_RX_Enable()		SCON |= 0x10
#define		S1_USE_P30P31()		P_SW1 &= ~0xc0				
#define		S1_USE_P36P37()		P_SW1 = (P_SW1 & ~0xc0) | 0x40
#define		S1_USE_P16P17()		P_SW1 = (P_SW1 & ~0xc0) | 0x80
#define		S1_TXD_RXD_SHORT()	PCON2 |=  (1<<4)
#define		S1_TXD_RXD_OPEN()	PCON2 &= ~(1<<4)
#define 	S1_BRT_UseTimer2()	AUXR |=  1
#define 	S1_BRT_UseTimer1()	AUXR &= ~1

#define		S2_8bit()		S2CON &= ~(1<<7)
#define		S2_9bit()		S2CON |=  (1<<7)
#define		S2_RX_Enable()		S2CON |=  (1<<4)

#define		S2_MODE0()		S2CON &= ~(1<<7)
#define		S2_MODE1()		S2CON |=  (1<<7)
#define		S2_RX_EN()		S2CON |=  (1<<4)
#define		S2_RX_Disable()		S2CON &= ~(1<<4)
#define		TI2			(S2CON & 2) !=0
#define		RI2			(S2CON & 1) !=0
#define		SET_TI2()		S2CON |=  2
#define		CLR_TI2()		S2CON &= ~2
#define		CLR_RI2()		S2CON &= ~1
#define		S2TB8_SET()		S2CON |=  8
#define		S2TB8_CLR()		S2CON &= ~8
#define		S2_Int_en()		IE2   |=  1		
#define		S2_USE_P10P11()		P_SW2 &= ~1		
#define		S2_USE_P46P47()		P_SW2 |=  1		

#define		S3_USE_P00P01()		P_SW2 &= ~2		
#define		S3_USE_P50P51()		P_SW2 |=  2		
#define		S4_USE_P02P03()		P_SW2 &= ~4		
#define		S4_USE_P52P53()		P_SW2 |=  4		


/**********************************************************/

#define		Timer0_16bitAutoReload()	TMOD &= ~0x03					
#define		Timer0_16bit()			TMOD  = (TMOD & ~0x03) | 0x01	
#define		Timer0_8bitAutoReload()		TMOD  = (TMOD & ~0x03) | 0x02	
#define		Timer0_16bitAutoRL_NoMask()	TMOD |=  0x03		
#define		Timer0_AsCounterP32()		TMOD |=  4		
#define		Timer0_AsTimer()		TMOD &= ~4		
#define		Timer0_ExtControlP34()		TMOD |=  4		
#define 	Timer0_Run()			TR0 = 1				
#define 	Timer0_Stop()			TR0 = 0				
#define 	Timer0_InterruptEnable()	ET0 = 1				
#define 	Timer0_InterruptDisable()	ET0 = 0				

#define		Timer1_16bitAutoReload()	TMOD &= ~0x30					
#define		Timer1_16bit()			TMOD  = (TMOD & ~0x30) | 0x10	
#define		Timer1_8bitAutoReload()		TMOD  = (TMOD & ~0x30) | 0x20	
#define		Timer1_16bitAutoRL_NoMask()	TMOD |=  0x30		
#define		Timer1_AsCounterP33()		TMOD |=  (1<<6)		
#define		Timer1_AsTimer()		TMOD &= ~(1<<6)		
#define		Timer1_ExtControlP35()		TMOD |=  (1<<7)		
#define 	Timer1_Run()	 		TR1 = 1				
#define 	Timer1_Stop()	 		TR1 = 0				
#define 	Timer1_InterruptEnable()	ET1 = 1				
#define 	Timer1_InterruptDisable()	ET1 = 0				


//						   7     6       5      4     3      2      1      0    Reset Value
//sfr(AUXR,0x8E);		T0x12 T1x12 UART_M0x6  T2R  T2_C/T T2x12 EXTRAM  S1ST2  0000,0000	//Auxiliary Register 

#define 	Timer0_1T()				AUXR |=  (1<<7)
#define 	Timer0_12T()			AUXR &= ~(1<<7)
#define 	Timer1_1T()				AUXR |=  (1<<6)
#define 	Timer1_12T()			AUXR &= ~(1<<6)
#define		S1_M0x6()				AUXR |=  (1<<5)
#define		S1_M0x1()				AUXR &= ~(1<<5)
#define 	Timer2_Run() 			AUXR |=  (1<<4)	
#define 	Timer2_Stop()	 		AUXR &= ~(1<<4)	
#define		Timer2_AsCounterP31()	AUXR |=  (1<<3)	
#define		Timer2_AsTimer()		AUXR &= ~(1<<3)	
#define 	Timer2_1T()				AUXR |=  (1<<2)
#define 	Timer2_12T()			AUXR &= ~(1<<2)
#define 	Timer2_InterruptEnable()	IE2  |=  (1<<2)	
#define 	Timer2_InterruptDisable()	IE2  &= ~(1<<2)	

#define 	ExternalRAM_enable()		AUXR |=  2
#define 	InternalRAM_enable()		AUXR &= ~2

#define		T0_pulseP34_enable()		AUXR2 |=  1		
#define		T0_pulseP34_disable()		AUXR2 &= ~1
#define		T1_pulseP35_enable()		AUXR2 |=  2		
#define		T1_pulseP35_disable()		AUXR2 &= ~2
#define		T2_pulseP30_enable()		AUXR2 |=  4		
#define		T2_pulseP30_disable()		AUXR2 &= ~4



//sfr(WDT_CONTR,0xC1); //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
#define D_WDT_FLAG			(1<<7)
#define D_EN_WDT			(1<<5)
#define D_CLR_WDT			(1<<4)
#define D_IDLE_WDT			(1<<3)
#define WDT_SCALE_2		0
#define WDT_SCALE_4		1
#define WDT_SCALE_8		2	
#define WDT_SCALE_16		3
#define WDT_SCALE_32		4
#define WDT_SCALE_64		5
#define WDT_SCALE_128		6
#define WDT_SCALE_256		7

#define EN_WDT		0x40
#define CLR_WDT		0x20
#define IDLE_WDT	0x10

#define	WDT_reset(n)	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + (n)


//						  7     6      5    4     3      2    1     0     Reset Value
//sfr(PCON,0x87);	SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000	 //Power Control 

#define		LVDF		(1<<5)	


#define		MCU_IDLE()		PCON |= 1	
#define		MCU_POWER_DOWN()	PCON |= 2	


//sfr(ISP_CMD,0xC5);
#define		ISP_STANDBY()	ISP_CMD = 0		
#define		ISP_READ()		ISP_CMD = 1		
#define		ISP_WRITE()		ISP_CMD = 2		
#define		ISP_ERASE()		ISP_CMD = 3		

//sfr(ISP_TRIG,0xC6);
#define 	ISP_TRIGER()	ISP_TRIG = 0x5A;	ISP_TRIG = 0xA5		



//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		//1: 
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		//0: 
#define	SPI_Enable()		SPCTL |=  (1<<6)		//1: 
#define	SPI_Disable()		SPCTL &= ~(1<<6)		//0: 
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		//1: 
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		//0: 
#define	SPI_Master()		SPCTL |=  (1<<4)		//1: 
#define	SPI_Slave()		SPCTL &= ~(1<<4)		//0: 
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		//1: 
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		//0: 
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		//1: 
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		//0: 
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	

//sfr(SPDAT,0xCF); //SPI Data Register                                                     0000,0000

//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		
#define	WCOL	0x40		

#define		SPI_USE_P12P13P14P15()	AUXR1 &= ~0x0c
#define		SPI_USE_P24P23P22P21()	AUXR1 = (AUXR1 & ~0x0c) | 0x04
#define		SPI_USE_P54P40P41P43()	AUXR1 = (AUXR1 & ~0x0c) | 0x08


#define		PWM0_NORMAL()	PCA_PWM0 &= ~3
#define		PWM0_OUT_0()	PCA_PWM0 |=  3
#define		PWM0_OUT_1()	PCA_PWM0 &= ~3, CCAP0H = 0

#define		PWM1_NORMAL()	PCA_PWM1 &= ~3
#define		PWM1_OUT_0()	PCA_PWM1 |=  3
#define		PWM1_OUT_1()	PCA_PWM1 &= ~3, CCAP1H = 0

#define		PWM2_NORMAL()	PCA_PWM2 &= ~3
#define		PWM2_OUT_0()	PCA_PWM2 |=  3
#define		PWM2_OUT_1()	PCA_PWM2 &= ~3, CCAP2H = 0


//					 7     6     5     4     3     2     1     0    Reset Value
//sfr(CMOD,0xD9);	CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,0000	
#define PCA_IDLE_OFF()		CMOD |=  (1<<7)
#define PCA_IDLE_ON()		CMOD &= ~(1<<7)
#define PCA_CLK_12T()		CMOD &= ~0x0E
#define PCA_CLK_2T()		CMOD = (CMOD & ~0x0E) + 2
#define PCA_CLK_T0()		CMOD = (CMOD & ~0x0E) + 4
#define PCA_CLK_ECI()		CMOD = (CMOD & ~0x0E) + 6
#define PCA_CLK_1T()		CMOD = (CMOD & ~0x0E) + 8
#define PCA_CLK_4T()		CMOD = (CMOD & ~0x0E) + 10
#define PCA_CLK_6T()		CMOD = (CMOD & ~0x0E) + 12
#define PCA_CLK_8T()		CMOD = (CMOD & ~0x0E) + 14
#define PCA_INT_ENABLE()	CMOD |=  1
#define PCA_INT_DISABLE()	CMOD &= ~1

//					    7      6       5        4       3       2       1      0    Reset Value
//sfr(AUXR1,0xA2);	  S1_S1  S1_S0  CCP_S1   CCP_S0  SPI_S1   SPI_S0    -     DPS   0100,0000	//Auxiliary Register 1

#define		PCA_USE_P12P11P10P37()	AUXR1 &= ~0x30
#define		PCA_USE_P34P35P36P37()	AUXR1 = (AUXR1 & ~0x30) | 0x10
#define		PCA_USE_P24P25P26P27()	AUXR1 = (AUXR1 & ~0x30) | 0x20

#define		DPS_SEL1()		AUXR1 |=  1
#define		DPS_SEL0()		AUXR1 &= ~1


/*******************************************************************/
#define		PCA0_none()				CCAPM0 = 0
#define		PCA0_PWM(nbit)			CCAPM0 = 0x42,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_rise_int(nbit) CCAPM0 = 0x63,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_fall_int(nbit) CCAPM0 = 0x53,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_PWM_edge_int(nbit) CCAPM0 = 0x73,PCA_PWM0 = (PCA_PWM0 & 0x0c) | ((8-nbit)<<6)
#define		PCA0_capture_rise()		CCAPM0 = (0x20 + 1)
#define		PCA0_capture_fall()		CCAPM0 = (0x10 + 1)
#define		PCA0_capture_edge()		CCAPM0 = (0x30 + 1)
#define		PCA0_16bit_Timer()		CCAPM0 = (0x48 + 1)
#define		PCA0_High_Pulse()		CCAPM0 = (0x4C + 1)

#define		PCA1_none()			CCAPM1 = 0
#define		PCA1_PWM(nbit)			CCAPM1 = 0x42,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_rise_int(nbit) CCAPM1 = 0x63,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_fall_int(nbit) CCAPM1 = 0x53,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_PWM_edge_int(nbit) CCAPM1 = 0x73,PCA_PWM1 = (PCA_PWM1 & 0x0c) | ((8-nbit)<<6)
#define		PCA1_capture_rise()		CCAPM1 = (0x20 + 1)
#define		PCA1_capture_fall()		CCAPM1 = (0x10 + 1)
#define		PCA1_capture_edge()		CCAPM1 = (0x30 + 1)
#define		PCA1_16bit_Timer()		CCAPM1 = (0x48 + 1)
#define		PCA1_High_Pulse()		CCAPM1 = (0x4C + 1)

#define		PCA2_none()			CCAPM2 = 0
#define		PCA2_PWM(nbit)			CCAPM2 = 0x42,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_rise_int(nbit) CCAPM2 = 0x63,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_fall_int(nbit) CCAPM2 = 0x53,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_PWM_edge_int(nbit) CCAPM2 = 0x73,PCA_PWM2 = (PCA_PWM2 & 0x0c) | ((8-nbit)<<6)
#define		PCA2_capture_rise()		CCAPM2 = (0x20 + 1)
#define		PCA2_capture_fall()		CCAPM2 = (0x10 + 1)
#define		PCA2_capture_edge()		CCAPM2 = (0x30 + 1)
#define		PCA2_16bit_Timer()		CCAPM2 = (0x48 + 1)
#define		PCA2_High_Pulse()		CCAPM2 = (0x4C + 1)

/* Above is STC additional SFR(or,change) */


/**********************************************************/
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	unsigned long	u32;
typedef 	unsigned char 	U8; 
/**********************************************************/



#define		LVD_InterruptEnable()		ELVD = 1
#define		LVD_InterruptDisable()		ELVD = 0


//sfr(WKTCL,0xAA);	
//sfr(WKTCH,0xAB);	
//	B7		B6	B5	B4	B3	B2	B1	B0		B7	B6	B5	B4	B3	B2	B1	B0
//	WKTEN				S11	S10	S9	S8		S7	S6	S5	S4	S3	S2	S1	S0	n * 560us
#define		WakeTimerDisable()		WKTCH &= 0x7f	
#define		WakeTimerSet(scale)		WKTCL = (scale) % 256,WKTCH = (scale) / 256 | 0x80	//WKTEN = 1	


//sfr(CLK_DIV,0x97); //Clock Divder    -     -  CLKS2 CLKS1 CLKS0 xxxx,x000
#define		SYSTEM_CLK_1T()		CLK_DIV &= ~0x07	//default
#define		SYSTEM_CLK_2T()		CLK_DIV = (CLK_DIV & ~0x07) | 1
#define		SYSTEM_CLK_4T()		CLK_DIV = (CLK_DIV & ~0x07) | 2
#define		SYSTEM_CLK_8T()		CLK_DIV = (CLK_DIV & ~0x07) | 3
#define		SYSTEM_CLK_16T()	CLK_DIV = (CLK_DIV & ~0x07) | 4
#define		SYSTEM_CLK_32T()	CLK_DIV = (CLK_DIV & ~0x07) | 5
#define		SYSTEM_CLK_64T()	CLK_DIV = (CLK_DIV & ~0x07) | 6
#define		SYSTEM_CLK_128T()	CLK_DIV =  CLK_DIV          | 7

#define		MCLKO_P54_None()	CLK_DIV &= ~0xc0					
#define		MCLKO_P54_DIV1()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x40	
#define		MCLKO_P54_DIV2()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x80	
#define		MCLKO_P54_DIV4()	CLK_DIV  =  CLK_DIV | 0xc0			

#define		MCLKO_P34_None()	CLK_DIV &= ~0xc0					
#define		MCLKO_P34_DIV1()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x40	
#define		MCLKO_P34_DIV2()	CLK_DIV  = (CLK_DIV & ~0xc0) | 0x80	
#define		MCLKO_P34_DIV4()	CLK_DIV  =  CLK_DIV | 0xc0			

//sfr(BUS_SPEED,0xA1); //Stretch register      -   -  -  -   -   -  EXRTS1  EXRTSS0 xxxx,xx10
#define		BUS_SPEED_1T()	BUS_SPEED = 0
#define		BUS_SPEED_2T()	BUS_SPEED = 1
#define		BUS_SPEED_4T()	BUS_SPEED = 2
#define		BUS_SPEED_8T()	BUS_SPEED = 3

/*   interrupt vector */
#define		INT0_VECTOR		0
#define		TIMER0_VECTOR	1
#define		INT1_VECTOR		2
#define		TIMER1_VECTOR	3
#define		UART1_VECTOR	4
#define		ADC_VECTOR		5
#define		LVD_VECTOR		6
#define		PCA_VECTOR		7
#define		UART2_VECTOR	8
#define		SPI_VECTOR		9
#define		INT2_VECTOR		10
#define		INT3_VECTOR		11
#define		TIMER2_VECTOR	12
#define		INT4_VECTOR		16
#define		UART3_VECTOR	17
#define		UART4_VECTOR	18
#define		TIMER3_VECTOR	19
#define		TIMER4_VECTOR	20
#define		CMP_VECTOR		21


#define	TRUE	1
#define	FALSE	0

//========================================

#define	PolityLow			0	
#define	PolityHigh			1	

//========================================

#define		MCLKO_None	0
#define		MCLKO_DIV1	1
#define		MCLKO_DIV2	2
#define		MCLKO_DIV4	3

#define		ENABLE		1
#define		DISABLE		0

#define		STC15F_L2K08S2	8
#define		STC15F_L2K16S2	16
#define		STC15F_L2K24S2	24
#define		STC15F_L2K32S2	32
#define		STC15F_L2K40S2	40
#define		STC15F_L2K48S2	48
#define		STC15F_L2K56S2	56
#define		STC15F_L2K60S2	60
#define		IAP15F_L2K61S2	61

/*Define ADC operation const for ADC_CONTR*/
#define		ADC_POWER		0x80
#define		ADC_FLAG		0x10
#define		ADC_START		0x08
#define		ADC_SPEEDLL		0x00
#define		ADC_SPEEDL		0x20
#define		ADC_SPEEDH		0x40
#define		ADC_SPEEDHH		0x60

#define     nop()   __asm nop __endasm

#endif
