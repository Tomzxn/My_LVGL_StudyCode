#include "lv_obj_test.h"
#include "lvgl.h"
#include "delay.h"
#include "usart.h"
#include "key.h"


//lv_obj_t * scr;
//lv_obj_t * obj1 = NULL;
//lv_obj_t * obj2 = NULL;
//lv_obj_t * obj3 = NULL;
//lv_style_t red_style;

////������ں���
//void lv_obj_test_start()
//{
//	scr = lv_scr_act();//��ȡ��ǰ��Ծ����Ļ����
//	
//	//�ȴ���һ����ɫ��������ʽ,������ʽ��صĴ���,�������Ļ�,û��ϵ,�������ϸ����
//	
//	lv_style_copy(&red_style,&lv_style_plain_color);//�ȴ�ϵͳ�Դ���lv_style_plain��ʽ��������,�����Ͳ��ö�ÿ�����Խ��и�ֵ��
//	red_style.body.main_color = LV_COLOR_RED;
//	red_style.body.grad_color = LV_COLOR_RED;
//	
//	//����һ����������1
//	obj1 = lv_obj_create(scr,NULL);
//	lv_obj_set_pos(obj1,20,20);//��������λ��
//	lv_obj_set_size(obj1,100,100);//���ô�С
//	
//	//����һ����������2,�����1�����ⲿ���¾��ж���,ͬʱy������ƫ��10������,
//	//Ŀ����Ϊ����obj2��һ����ѹ��obj1��,���������ʾz��㼶�ı��API�ӿ�
//	obj2 = lv_obj_create(scr,NULL);
//	lv_obj_set_size(obj2,50,50);
//	lv_obj_set_style(obj2,&red_style);//�����µ���ʽ
//	lv_obj_align(obj2,obj1,LV_ALIGN_OUT_BOTTOM_MID,0,-20);
//	
//}

////��������
////ע��:�밴���Ȱ�KEY0��,�ٰ�KEY1��,���KEY2����˳�����۲�ʵ������
//void key_handler()
//{
//	u8 key = KEY_Scan(0);
//	
//	if(key==KEY0_PRES) 
//	{
//		//z��㼶�ı���ʾ,��obj1��������ö�,������ʵ�ַ�ʽ
//		#define Z_LAYER_MODE	1 //1,2,3�ֱ��Ӧ����ʵ�ַ�ʽ
//		
//		#if(Z_LAYER_MODE==1)
//			if(obj1)
//				lv_obj_move_foreground(obj1);
//		#elif(Z_LAYER_MODE==2)
//			lv_obj_move_background(obj2);
//		#elif(Z_LAYER_MODE==3)
//			lv_obj_set_top(obj1,true);
//		#endif
//		printf("obj1 is on top layer\r\n");
//	}else if(key==KEY1_PRES)
//	{
//		//��̬����һ������3,����Ļ���ж���,Ȼ����Ķ���2�ĸ���Ϊ����3
//		obj3 = lv_obj_create(scr,obj1);//��obj1��������,����һЩ���Եĸ�ֵ
//		lv_obj_align(obj3,NULL,LV_ALIGN_CENTER,0,0);//��NULL,��ô��������ǲο�����
//		lv_obj_set_drag(obj3,true);//����obj3���Ա���ק
//		lv_obj_set_drag_throw(obj3,true);//ͬʱʹ��obj3����ק���Ի�������
//		lv_obj_set_parent(obj2,obj3);//�޸�obj2�ĸ�����Ϊobj3
//		lv_obj_set_pos(obj2,10,10);//obj2����������һ������
//		
//		lv_obj_set_opa_scale_enable(obj1,true);//��ʹ��obj1��͸���ȹ���
//		lv_obj_set_opa_scale(obj1,100);//������obj1��͸����Ϊ50
//		
//		//������,�������һ������Ļ����קobj3
//		//���ö���3���Ա���ק,ע����קʱ,��ָһ���ð���obj3��,
//		//���ܰ���obj2��,���򿴲�����ȷ����ק����,��Ȼobj2��obj3
//		//���Ӷ���,����obj2��û��ʹ����ק���ܵ�
//	}else if(key==KEY2_PRES)
//	{
//		if(obj1)
//		{
//			//ɾ��obj1����,��2��ʵ�ַ�ʽ
//			#define DEL_MODE	1 
//			
//			#if(DEL_MODE==1)
//				lv_obj_del(obj1);
//			#elif(DEL_MODE==2)
//				lv_obj_del_async(obj1);
//			#endif
//			obj1 = NULL;
//			printf("obj1 is deleted\r\n");
//		}
//	}
//}










