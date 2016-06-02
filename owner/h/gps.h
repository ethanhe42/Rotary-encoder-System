#ifndef _GPS_H
#define _GPS_H
  #include "stm32f10x.h"

#define GPS_STATCOUNT	2
typedef struct 
{
	fp64 x;
	fp64 y;
}Pointfp64;
typedef struct 
{   
	Pointfp64  	position;	  	  //当前坐标	
	fp64				        distancestep1; 	//码盘1本次前进距离
	fp64				        distancestep2;  //码盘2本次前进距离
	fp64			          distance1;	  	//码盘1前进距离
	fp64			        	distance2;		  //码盘2前进距离
	fp64  	        		angle;        	//当前角度 		
	fp64				        radian;			    //当前弧度
	fp64				        speed;			    //当前速度
	fp64				        acceleration;	  //当前加速度
	fp64			         	rotationspeed;	//当前自转速度
	fp64				        rotationacc;	  //当前自转加速度
}Gps_State;


extern Gps_State Gps_List[GPS_STATCOUNT];
extern Pointfp64 Gps_assume;//利用摄像头或者激光等校正时试验用的变量

void GPS_Update(void);
void GPS_Clear(void);
void GPS_Init(Pointfp64 position,fp64 radian);
#endif
