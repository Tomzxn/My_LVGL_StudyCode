#include "lv_style_test.h"
#include "lvgl.h"
#include "key.h"
#include "usart.h"

//lv_obj_t* dialog = NULL;
//lv_obj_t* title_label,* cancel,* ok;

//lv_obj_t* dialog_create(lv_obj_t* parent);


////�¼��ص�����
//static void event_handler(lv_obj_t* obj,lv_event_t event)
//{
//	if(event==LV_EVENT_PRESSED||event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST)
//	{
//		lv_style_t* style = (lv_style_t*)lv_label_get_style(obj,LV_LABEL_STYLE_MAIN);
//		if(event==LV_EVENT_PRESSED)
//		{
//			//�ð�ť����ȥ�е����Ч��
//			style->body.radius = 10;
//			style->body.opa = LV_OPA_50;
//		}else{
//			//�ָ����ֺ��״̬
//			style->body.radius = 0;
//			style->body.opa = LV_OPA_COVER;
//		}
//		
//		lv_obj_refresh_style(obj);//֪ͨ����,����ʹ�õ���ʽ�����˸ı�
//	}
//		
//	if(obj==title_label)
//	{
//		if(event==LV_EVENT_RELEASED)
//		{
//			if(dialog==NULL)//�ٴδ򿪶Ի���
//				dialog = dialog_create(lv_scr_act());
//		}
//	}else if(obj==cancel||obj==ok)
//	{
//		if(event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST)//�����¼�,����LV_EVENT_PRESS_LOST�¼���ָ�໬������Ŀ�������
//		{
//			if(dialog)
//			{
//				//ɾ���Ի���
//				lv_obj_del(dialog);
//				dialog = NULL;
//			}
//		}
//	}
//}

////����һ���Զ���ĶԻ���
//lv_obj_t* dialog_create(lv_obj_t* parent)
//{
//	#define DIALOG_WIDTH						180   //�Ի���Ŀ��
//	#define DIALOG_HEIGHT						150		//�Ի���ĸ߶�
//	#define DIALOG_BOTTOM_HEIGHT		40		//�Ի���ĵײ���ť���߶�(��ɫ��������)
//	#define DIALOG_BOTTOM_PADDING		10    //�ڱ߾�,Ҳ���ǰ�ť��Ի���߿�ľ���
//	
//	//1.����һ�����а�͸��Ч���Ļ�ɫ���ֲ�
//	lv_obj_t* gray_layer = lv_obj_create(parent,NULL);//��������
//	lv_obj_set_pos(gray_layer,0,0);//��������
//	lv_obj_set_size(gray_layer,lv_obj_get_width(parent),lv_obj_get_height(parent));//�븸������ͬ��С
//	static lv_style_t gray_layer_style;//����ü�static
//	lv_style_copy(&gray_layer_style,&lv_style_plain_color);//��ʽ����
//	gray_layer_style.body.main_color = LV_COLOR_GRAY;//�ϰ벿�ֱ���ɫ
//	gray_layer_style.body.grad_color = LV_COLOR_GRAY;//�°벿�ֱ���ɫ
//	gray_layer_style.body.opa = LV_OPA_80;//͸����
//	lv_obj_set_style(gray_layer,&gray_layer_style);//������ʽ
//	
//	//2.�����Ի�������汳��(��ɫ)
//	lv_obj_t* top_bg = lv_obj_create(gray_layer,NULL);//ע��,Ϊ�˱��ֿؼ���һ����,����ĸ�����Ӧ���Ǵ�gray_layer,������parent
//	lv_obj_set_size(top_bg,DIALOG_WIDTH,DIALOG_HEIGHT);
//	lv_obj_align(top_bg,NULL,LV_ALIGN_CENTER,0,0);//���ж���
//	static lv_style_t top_bg_style;
//	lv_style_copy(&top_bg_style,&lv_style_plain_color);
//	top_bg_style.body.main_color = LV_COLOR_MAKE(0x39, 0x3C, 0x4A);
//	top_bg_style.body.grad_color = LV_COLOR_MAKE(0x39, 0x3C, 0x4A);
//	top_bg_style.body.radius = 10;//Բ�ǰ뾶
////	top_bg_style.body.shadow.color = LV_COLOR_BLACK;//��ӰЧ��,���˺�������
////	top_bg_style.body.shadow.type = LV_SHADOW_FULL;
////	top_bg_style.body.shadow.width = 8;
//	lv_obj_set_style(top_bg,&top_bg_style);
//	
//	//3.�����Ի�������汳��(��ɫ)
//	lv_obj_t* bottom_bg = lv_obj_create(gray_layer,NULL);
//	lv_obj_set_size(bottom_bg,DIALOG_WIDTH,DIALOG_BOTTOM_HEIGHT);
//	lv_obj_align(bottom_bg,top_bg,LV_ALIGN_IN_BOTTOM_MID,0,0);//��top_bg���ж���
//	static lv_style_t bottom_bg_style;
//	lv_style_copy(&bottom_bg_style,&lv_style_plain_color);
//	bottom_bg_style.body.main_color = LV_COLOR_WHITE;
//	bottom_bg_style.body.grad_color = LV_COLOR_WHITE;
//	lv_obj_set_style(bottom_bg,&bottom_bg_style);
//	
//	//4.�����Ի���ı���
//	lv_obj_t* title = lv_label_create(gray_layer,NULL);
//	lv_label_set_text(title,"Title");
//	lv_obj_align(title,top_bg,LV_ALIGN_IN_TOP_MID,0,10);
//	
//	//5.�����Ի��������
//	lv_obj_t* content = lv_label_create(gray_layer,NULL);
//	lv_label_set_text(content,"This is a dialog\nDo you like it?");
//	lv_obj_align(content,top_bg,LV_ALIGN_CENTER,0,-12);
//	
//	//6.����ȡ����ť,����label������ģ��
//	cancel = lv_label_create(gray_layer,NULL);
//	lv_label_set_long_mode(cancel,LV_LABEL_LONG_CROP);//Ҫ���й̶��Ĵ�С,����������úó��ı�ģʽ
//	lv_obj_set_size(cancel,(DIALOG_WIDTH-DIALOG_BOTTOM_PADDING*4)/2,DIALOG_BOTTOM_HEIGHT-DIALOG_BOTTOM_PADDING*2);//���ù̶��Ĵ�С
//	lv_label_set_text(cancel,"Cancel");//�����ı�
//	lv_label_set_align(cancel,LV_LABEL_ALIGN_CENTER);//�����ı����ж���
//	lv_obj_align(cancel,bottom_bg,LV_ALIGN_IN_LEFT_MID,DIALOG_BOTTOM_PADDING,0);
//	lv_label_set_body_draw(cancel,true);
//	static lv_style_t cancel_style;
//	lv_style_copy(&cancel_style,&lv_style_plain_color);
//	cancel_style.body.main_color = LV_COLOR_WHITE;
//	cancel_style.body.grad_color = LV_COLOR_WHITE;
//	cancel_style.body.border.width = 1;//�߿�Ŀ��
//  cancel_style.body.border.color = LV_COLOR_MAKE(0xBD,0xBA,0xBD);//�߿����ɫ
//	cancel_style.body.border.part = LV_BORDER_FULL;//�����߿�ȫ������
//	cancel_style.text.color = LV_COLOR_MAKE(0x63,0x65,0x63);
//	lv_label_set_style(cancel,LV_LABEL_STYLE_MAIN,&cancel_style);
//	lv_obj_set_click(cancel,true);//ʹ�ܵ��
//	lv_obj_set_event_cb(cancel,event_handler);//ע���¼��ص�����
//	
//	//7.����ȷ����ť
//	ok = lv_label_create(gray_layer,cancel);//ֱ�Ӵ�cancel��������
//	lv_label_set_text(ok,"Ok");//�����ı�
//	lv_obj_align(ok,bottom_bg,LV_ALIGN_IN_RIGHT_MID,-DIALOG_BOTTOM_PADDING,0);
//	static lv_style_t ok_style;
//	lv_style_copy(&ok_style,&lv_style_plain_color);
//	ok_style.body.main_color = LV_COLOR_MAKE(0x31,0xAA,0xFF);
//	ok_style.body.grad_color = LV_COLOR_MAKE(0x31,0xAA,0xFF);
//	ok_style.text.color = LV_COLOR_WHITE;
//	lv_label_set_style(ok,LV_LABEL_STYLE_MAIN,&ok_style);
//	
//	return gray_layer;
//}

////�������
//void lv_style_test_start()
//{
//	lv_obj_t* src = lv_scr_act();//��ȡ��ǰ����Ļ����
//	
//	title_label = lv_label_create(src,NULL);//����һ��label,�������ʱ,�򿪶Ի���
//	lv_label_set_text(title_label,"click to open dialog");//�����ı�
//	lv_obj_align(title_label,NULL,LV_ALIGN_IN_TOP_MID,0,20);
//	lv_label_set_body_draw(title_label,true);//���Ʊ���
//	lv_label_set_style(title_label,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//������ʽ
//	lv_obj_set_click(title_label,true);//ʹ�ܵ��
//	lv_obj_set_event_cb(title_label,event_handler);//ע���¼��ص�����
//	
//	dialog = dialog_create(src);//�����Ի���
//}














