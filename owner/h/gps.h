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
	Pointfp64  	position;	  	  //��ǰ����	
	fp64				        distancestep1; 	//����1����ǰ������
	fp64				        distancestep2;  //����2����ǰ������
	fp64			          distance1;	  	//����1ǰ������
	fp64			        	distance2;		  //����2ǰ������
	fp64  	        		angle;        	//��ǰ�Ƕ� 		
	fp64				        radian;			    //��ǰ����
	fp64				        speed;			    //��ǰ�ٶ�
	fp64				        acceleration;	  //��ǰ���ٶ�
	fp64			         	rotationspeed;	//��ǰ��ת�ٶ�
	fp64				        rotationacc;	  //��ǰ��ת���ٶ�
}Gps_State;


extern Gps_State Gps_List[GPS_STATCOUNT];
extern Pointfp64 Gps_assume;//��������ͷ���߼����У��ʱ�����õı���

void GPS_Update(void);
void GPS_Clear(void);
void GPS_Init(Pointfp64 position,fp64 radian);
#endif
