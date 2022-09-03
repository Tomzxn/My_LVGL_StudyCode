#include "lv_label_test.h"
#include "lvgl.h"
#include "delay.h"
#include "usart.h"
#include "key.h"

//lv_obj_t* label1;
//lv_obj_t* label2;

////模式标题
//const char * const MODE_STR[] = {"EXPAND","BREAK","DOT","SROLL","SROLL_CIRC","CROP"};

////事件处理
//void event_handler(lv_obj_t * obj, lv_event_t event)
//{
//	 static lv_label_long_mode_t mode = LV_LABEL_LONG_EXPAND;
//	 
//   if(obj==label2)
//	 {
//			if(event==LV_EVENT_RELEASED)//触摸释放事件
//			{
//				lv_label_set_long_mode(label2,mode);//设置新的长文本模式
//				if(mode==LV_LABEL_LONG_EXPAND)//自动扩展模式
//				{
//					lv_label_set_text(label2,"EXPAND:0123456789ABCDEFGHIJKLMN\nI am xiong jia yu\nWho are you?");
//				}else if(mode==LV_LABEL_LONG_BREAK)//自动换行模式
//				{
//					lv_obj_set_width(label2,100);
//					lv_label_set_text(label2,"BREAK:Auto to break line");
//				}else if(mode==LV_LABEL_LONG_DOT)//自动显示省略号模式
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"DOT:too long,0123456789ABCDEFGHIJKLMN");
//				}else if(mode==LV_LABEL_LONG_SROLL)//自动前后滚动模式
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"SROLL:KEY0 to add speed");
//				}else if(mode==LV_LABEL_LONG_SROLL_CIRC)//自动环形滚动模式
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"SROLL_CIRC:KEY0 to add speed");
//				}else if(mode==LV_LABEL_LONG_CROP)//剪切模式
//				{
//					lv_obj_set_size(label2,100,40);
//					lv_label_set_text(label2,"CROP:0123456789ABCDEF");
//				}
//				lv_obj_realign(label2);//因为label2的大小发生了改变,为了让label2继续与屏幕保持居中对齐,可以调用重对齐接口
//				lv_label_set_text(label1,MODE_STR[mode]);
//				printf("current long mode:%d\r\n",mode);
//				//切换到下一个模式
//				mode++;
//				if(mode>LV_LABEL_LONG_CROP)
//					mode = LV_LABEL_LONG_EXPAND;
//			}
//	 }
//}

////例程入口函数
//void lv_label_test_start()
//{
//	lv_obj_t* scr = lv_scr_act();//获取当前活跃的屏幕对象
//	
//	//创建label1标签,用来显示label2标签的长文本模式
//	label1 = lv_label_create(scr,NULL);//创建标签
//	lv_label_set_long_mode(label1,LV_LABEL_LONG_BREAK);//设置长文本模式
//	lv_obj_set_width(label1,160);//设置宽度,一定得放在lv_label_set_long_mode的后面,否则不起作用的
//	lv_label_set_recolor(label1,true);//使能文本重绘色功能
//	lv_label_set_text(label1,"#ff0000 Title:#mode");//设置文本,带有颜色重绘
//	lv_label_set_align(label1,LV_LABEL_ALIGN_CENTER);//文本居中对齐
//	lv_label_set_style(label1,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//设置主背景样式
//	lv_label_set_body_draw(label1,true);//使能背景绘制
//	//注意:设置与屏幕的对齐方式,这个接口也是跟调用位置有关系的,最好放到后面调用,因为放的太前调用的话,
//	//在那时标签对象的大小可能还是未知的,此时lv_obj_align接口就没办法算出对齐之后的坐标,从而也就
//	//达不到我们所要的对齐效果
//	lv_obj_align(label1,NULL,LV_ALIGN_IN_TOP_MID,0,20);
//		
//	
//	//创建label2标签
//	label2 = lv_label_create(scr,NULL);//创建标签
//	lv_label_set_style(label2,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//设置主背景样式
//	lv_label_set_body_draw(label2,true);//使能背景绘制
//	lv_obj_set_click(label2,true);//使能点击功能
//	lv_obj_set_event_cb(label2,event_handler);//设置事件回调函数
//	lv_label_set_text(label2,"Please click me!");//设置文本
//	lv_obj_align(label2,NULL,LV_ALIGN_CENTER,0,0);//设置其与屏幕居中对齐
//}

////按键处理
////注意:请按照先按KEY0键,再按KEY1键,最后按KEY2键的顺序来观察实验现象
//void key_handler()
//{
//	u8 key = KEY_Scan(0);
//	
//	if(key==KEY0_PRES)
//	{
//		//调节动画速度
//		lv_label_set_anim_speed(label2,lv_label_get_anim_speed(label2)+5);
//		printf("anim speed:%d\r\n",lv_label_get_anim_speed(label2));
//	}else if(key==KEY1_PRES)
//	{
//		//在label1文本的最前面插入OK字符串
//		lv_label_ins_text(label1,0,"OK");
//	}else if(key==KEY2_PRES)
//	{
//		//删除label1文本最前面的2个字符
//		lv_label_cut_text(label1,0,2);
//	}
//}










