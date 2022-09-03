#include "lv_label_test.h"
#include "lvgl.h"
#include "delay.h"
#include "usart.h"
#include "key.h"

//lv_obj_t* label1;
//lv_obj_t* label2;

////ģʽ����
//const char * const MODE_STR[] = {"EXPAND","BREAK","DOT","SROLL","SROLL_CIRC","CROP"};

////�¼�����
//void event_handler(lv_obj_t * obj, lv_event_t event)
//{
//	 static lv_label_long_mode_t mode = LV_LABEL_LONG_EXPAND;
//	 
//   if(obj==label2)
//	 {
//			if(event==LV_EVENT_RELEASED)//�����ͷ��¼�
//			{
//				lv_label_set_long_mode(label2,mode);//�����µĳ��ı�ģʽ
//				if(mode==LV_LABEL_LONG_EXPAND)//�Զ���չģʽ
//				{
//					lv_label_set_text(label2,"EXPAND:0123456789ABCDEFGHIJKLMN\nI am xiong jia yu\nWho are you?");
//				}else if(mode==LV_LABEL_LONG_BREAK)//�Զ�����ģʽ
//				{
//					lv_obj_set_width(label2,100);
//					lv_label_set_text(label2,"BREAK:Auto to break line");
//				}else if(mode==LV_LABEL_LONG_DOT)//�Զ���ʾʡ�Ժ�ģʽ
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"DOT:too long,0123456789ABCDEFGHIJKLMN");
//				}else if(mode==LV_LABEL_LONG_SROLL)//�Զ�ǰ�����ģʽ
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"SROLL:KEY0 to add speed");
//				}else if(mode==LV_LABEL_LONG_SROLL_CIRC)//�Զ����ι���ģʽ
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"SROLL_CIRC:KEY0 to add speed");
//				}else if(mode==LV_LABEL_LONG_CROP)//����ģʽ
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"CROP:0123456789ABCDEF");
//				}
//				lv_obj_realign(label2);//��Ϊlabel2�Ĵ�С�����˸ı�,Ϊ����label2��������Ļ���־��ж���,���Ե����ض���ӿ�
//				lv_label_set_text(label1,MODE_STR[mode]);
//				printf("current long mode:%d\r\n",mode);
//				//�л�����һ��ģʽ
//				mode++;
//				if(mode>LV_LABEL_LONG_CROP)
//					mode = LV_LABEL_LONG_EXPAND;
//			}
//	 }
//}

////������ں���
//void lv_label_test_start()
//{
//	lv_obj_t* scr = lv_scr_act();//��ȡ��ǰ��Ծ����Ļ����
//	
//	//����label1��ǩ,������ʾlabel2��ǩ�ĳ��ı�ģʽ
//	label1 = lv_label_create(scr,NULL);//������ǩ
//	lv_label_set_long_mode(label1,LV_LABEL_LONG_BREAK);//���ó��ı�ģʽ
//	lv_obj_set_width(label1,160);//���ÿ��,һ���÷���lv_label_set_long_mode�ĺ���,���������õ�
//	lv_label_set_recolor(label1,true);//ʹ���ı��ػ�ɫ����
//	lv_label_set_text(label1,"#ff0000 Title:#mode");//�����ı�,������ɫ�ػ�
//	lv_label_set_align(label1,LV_LABEL_ALIGN_CENTER);//�ı����ж���
//	lv_label_set_style(label1,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//������������ʽ
//	lv_label_set_body_draw(label1,true);//ʹ�ܱ�������
//	//ע��:��������Ļ�Ķ��뷽ʽ,����ӿ�Ҳ�Ǹ�����λ���й�ϵ��,��÷ŵ��������,��Ϊ�ŵ�̫ǰ���õĻ�,
//	//����ʱ��ǩ����Ĵ�С���ܻ���δ֪��,��ʱlv_obj_align�ӿھ�û�취�������֮�������,�Ӷ�Ҳ��
//	//�ﲻ��������Ҫ�Ķ���Ч��
//	lv_obj_align(label1,NULL,LV_ALIGN_IN_TOP_MID,0,20);
//		
//	
//	//����label2��ǩ
//	label2 = lv_label_create(scr,NULL);//������ǩ
//	lv_label_set_style(label2,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//������������ʽ
//	lv_label_set_body_draw(label2,true);//ʹ�ܱ�������
//	lv_obj_set_click(label2,true);//ʹ�ܵ������
//	lv_obj_set_event_cb(label2,event_handler);//�����¼��ص�����
//	lv_label_set_text(label2,"Please click me!");//�����ı�
//	lv_obj_align(label2,NULL,LV_ALIGN_CENTER,0,0);//����������Ļ���ж���
//}

////��������
////ע��:�밴���Ȱ�KEY0��,�ٰ�KEY1��,���KEY2����˳�����۲�ʵ������
//void key_handler()
//{
//	u8 key = KEY_Scan(0);
//	
//	if(key==KEY0_PRES)
//	{
//		//���ڶ����ٶ�
//		lv_label_set_anim_speed(label2,lv_label_get_anim_speed(label2)+5);
//		printf("anim speed:%d\r\n",lv_label_get_anim_speed(label2));
//	}else if(key==KEY1_PRES)
//	{
//		//��label1�ı�����ǰ�����OK�ַ���
//		lv_label_ins_text(label1,0,"OK");
//	}else if(key==KEY2_PRES)
//	{
//		//ɾ��label1�ı���ǰ���2���ַ�
//		lv_label_cut_text(label1,0,2);
//	}
//}










