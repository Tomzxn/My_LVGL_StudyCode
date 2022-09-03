#include "lv_style_test.h"
#include "lvgl.h"
#include "key.h"
#include "usart.h"

//lv_obj_t* dialog = NULL;
//lv_obj_t* title_label,* cancel,* ok;

//lv_obj_t* dialog_create(lv_obj_t* parent);


////事件回调函数
//static void event_handler(lv_obj_t* obj,lv_event_t event)
//{
//	if(event==LV_EVENT_PRESSED||event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST)
//	{
//		lv_style_t* style = (lv_style_t*)lv_label_get_style(obj,LV_LABEL_STYLE_MAIN);
//		if(event==LV_EVENT_PRESSED)
//		{
//			//让按钮看上去有点击的效果
//			style->body.radius = 10;
//			style->body.opa = LV_OPA_50;
//		}else{
//			//恢复松手后的状态
//			style->body.radius = 0;
//			style->body.opa = LV_OPA_COVER;
//		}
//		
//		lv_obj_refresh_style(obj);//通知对象,其所使用的样式发生了改变
//	}
//		
//	if(obj==title_label)
//	{
//		if(event==LV_EVENT_RELEASED)
//		{
//			if(dialog==NULL)//再次打开对话框
//				dialog = dialog_create(lv_scr_act());
//		}
//	}else if(obj==cancel||obj==ok)
//	{
//		if(event==LV_EVENT_RELEASED||event==LV_EVENT_PRESS_LOST)//松手事件,其中LV_EVENT_PRESS_LOST事件是指侧滑出对象的可视区了
//		{
//			if(dialog)
//			{
//				//删除对话框
//				lv_obj_del(dialog);
//				dialog = NULL;
//			}
//		}
//	}
//}

////创建一个自定义的对话框
//lv_obj_t* dialog_create(lv_obj_t* parent)
//{
//	#define DIALOG_WIDTH						180   //对话框的宽度
//	#define DIALOG_HEIGHT						150		//对话框的高度
//	#define DIALOG_BOTTOM_HEIGHT		40		//对话框的底部按钮栏高度(白色背景区域)
//	#define DIALOG_BOTTOM_PADDING		10    //内边距,也就是按钮与对话框边框的距离
//	
//	//1.创建一个带有半透明效果的灰色遮罩层
//	lv_obj_t* gray_layer = lv_obj_create(parent,NULL);//创建对象
//	lv_obj_set_pos(gray_layer,0,0);//设置坐标
//	lv_obj_set_size(gray_layer,lv_obj_get_width(parent),lv_obj_get_height(parent));//与父对象相同大小
//	static lv_style_t gray_layer_style;//必须得加static
//	lv_style_copy(&gray_layer_style,&lv_style_plain_color);//样式拷贝
//	gray_layer_style.body.main_color = LV_COLOR_GRAY;//上半部分背景色
//	gray_layer_style.body.grad_color = LV_COLOR_GRAY;//下半部分背景色
//	gray_layer_style.body.opa = LV_OPA_80;//透明度
//	lv_obj_set_style(gray_layer,&gray_layer_style);//设置样式
//	
//	//2.创建对话框的上面背景(黑色)
//	lv_obj_t* top_bg = lv_obj_create(gray_layer,NULL);//注意,为了保持控件的一体性,这里的父对象应该是传gray_layer,而不是parent
//	lv_obj_set_size(top_bg,DIALOG_WIDTH,DIALOG_HEIGHT);
//	lv_obj_align(top_bg,NULL,LV_ALIGN_CENTER,0,0);//居中对齐
//	static lv_style_t top_bg_style;
//	lv_style_copy(&top_bg_style,&lv_style_plain_color);
//	top_bg_style.body.main_color = LV_COLOR_MAKE(0x39, 0x3C, 0x4A);
//	top_bg_style.body.grad_color = LV_COLOR_MAKE(0x39, 0x3C, 0x4A);
//	top_bg_style.body.radius = 10;//圆角半径
////	top_bg_style.body.shadow.color = LV_COLOR_BLACK;//阴影效果,加了好像变丑了
////	top_bg_style.body.shadow.type = LV_SHADOW_FULL;
////	top_bg_style.body.shadow.width = 8;
//	lv_obj_set_style(top_bg,&top_bg_style);
//	
//	//3.创建对话框的下面背景(白色)
//	lv_obj_t* bottom_bg = lv_obj_create(gray_layer,NULL);
//	lv_obj_set_size(bottom_bg,DIALOG_WIDTH,DIALOG_BOTTOM_HEIGHT);
//	lv_obj_align(bottom_bg,top_bg,LV_ALIGN_IN_BOTTOM_MID,0,0);//与top_bg进行对齐
//	static lv_style_t bottom_bg_style;
//	lv_style_copy(&bottom_bg_style,&lv_style_plain_color);
//	bottom_bg_style.body.main_color = LV_COLOR_WHITE;
//	bottom_bg_style.body.grad_color = LV_COLOR_WHITE;
//	lv_obj_set_style(bottom_bg,&bottom_bg_style);
//	
//	//4.创建对话框的标题
//	lv_obj_t* title = lv_label_create(gray_layer,NULL);
//	lv_label_set_text(title,"Title");
//	lv_obj_align(title,top_bg,LV_ALIGN_IN_TOP_MID,0,10);
//	
//	//5.创建对话框的内容
//	lv_obj_t* content = lv_label_create(gray_layer,NULL);
//	lv_label_set_text(content,"This is a dialog\nDo you like it?");
//	lv_obj_align(content,top_bg,LV_ALIGN_CENTER,0,-12);
//	
//	//6.创建取消按钮,先用label对象来模拟
//	cancel = lv_label_create(gray_layer,NULL);
//	lv_label_set_long_mode(cancel,LV_LABEL_LONG_CROP);//要想有固定的大小,必须得先设置好长文本模式
//	lv_obj_set_size(cancel,(DIALOG_WIDTH-DIALOG_BOTTOM_PADDING*4)/2,DIALOG_BOTTOM_HEIGHT-DIALOG_BOTTOM_PADDING*2);//设置固定的大小
//	lv_label_set_text(cancel,"Cancel");//设置文本
//	lv_label_set_align(cancel,LV_LABEL_ALIGN_CENTER);//设置文本居中对齐
//	lv_obj_align(cancel,bottom_bg,LV_ALIGN_IN_LEFT_MID,DIALOG_BOTTOM_PADDING,0);
//	lv_label_set_body_draw(cancel,true);
//	static lv_style_t cancel_style;
//	lv_style_copy(&cancel_style,&lv_style_plain_color);
//	cancel_style.body.main_color = LV_COLOR_WHITE;
//	cancel_style.body.grad_color = LV_COLOR_WHITE;
//	cancel_style.body.border.width = 1;//边框的宽度
//  cancel_style.body.border.color = LV_COLOR_MAKE(0xBD,0xBA,0xBD);//边框的颜色
//	cancel_style.body.border.part = LV_BORDER_FULL;//四条边框全部绘制
//	cancel_style.text.color = LV_COLOR_MAKE(0x63,0x65,0x63);
//	lv_label_set_style(cancel,LV_LABEL_STYLE_MAIN,&cancel_style);
//	lv_obj_set_click(cancel,true);//使能点击
//	lv_obj_set_event_cb(cancel,event_handler);//注册事件回调函数
//	
//	//7.创建确定按钮
//	ok = lv_label_create(gray_layer,cancel);//直接从cancel拷贝过来
//	lv_label_set_text(ok,"Ok");//设置文本
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

////例程入口
//void lv_style_test_start()
//{
//	lv_obj_t* src = lv_scr_act();//获取当前的屏幕对象
//	
//	title_label = lv_label_create(src,NULL);//创建一个label,当点击它时,打开对话框
//	lv_label_set_text(title_label,"click to open dialog");//设置文本
//	lv_obj_align(title_label,NULL,LV_ALIGN_IN_TOP_MID,0,20);
//	lv_label_set_body_draw(title_label,true);//绘制背景
//	lv_label_set_style(title_label,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//设置样式
//	lv_obj_set_click(title_label,true);//使能点击
//	lv_obj_set_event_cb(title_label,event_handler);//注册事件回调函数
//	
//	dialog = dialog_create(src);//创建对话框
//}














