#include "lv_cont_test.h"
#include "lvgl.h"
#include "key.h"
#include <stdio.h>

//lv_obj_t* cont;
//lv_obj_t* tip;
//lv_layout_t layout = LV_LAYOUT_CENTER;//起始的布局方式
//lv_fit_t fit = LV_FIT_TIGHT;//起始的自适应方式
//u8 child_no = 1;

////布局提示内容
//const char* const LAYOUT_STR[] = {
//	"LV_LAYOUT_OFF","LV_LAYOUT_CENTER","LV_LAYOUT_COL_L","LV_LAYOUT_COL_M","LV_LAYOUT_COL_R",
//	"LV_LAYOUT_ROW_T","LV_LAYOUT_ROW_M","LV_LAYOUT_ROW_B","LV_LAYOUT_PRETTY","LV_LAYOUT_GRID"
//};
////自适应提示内容
//const char* const FIT_STR[] = {"LV_FIT_NONE","LV_FIT_TIGHT","LV_FIT_FLOOD","LV_FIT_FILL"};

////将当前的布局方式和自适应方式通过label显示出来
//void info_tip()
//{
//	char buff[80];
//	sprintf(buff,"#ff0000 Fit:#%s\n#ff0000 Layout:#%s",FIT_STR[fit],LAYOUT_STR[layout]);
//	lv_label_set_text(tip,buff);
//	lv_obj_align(tip,NULL,LV_ALIGN_IN_BOTTOM_MID,0,-40);
//}


////例程入口函数
//void lv_cont_test_start()
//{
//	lv_obj_t* scr = lv_scr_act();//获取当前活跃的屏幕对象

//	//1.创建容器并初始化
//	cont = lv_cont_create(scr,NULL);//创建容器
//	lv_obj_set_pos(cont,20,20);//设置坐标
//	//设置cont容器四个方向上的自适应方式,我们让容器的left左边和top上边无自适应,即保持不动
//	//因为容器的坐标为(20,20),数值比较小,如果左边和上边不设置为无自适应的话,当子对象
//	//数量增多时,容器因高或宽自动变大,就很容易碰到屏幕的左边缘或上边缘
//	lv_cont_set_fit4(cont,LV_FIT_NONE,fit,LV_FIT_NONE,fit);
//	//先设置容器布局方式
//	lv_cont_set_layout(cont,layout);
//	
//	static lv_style_t cont_style;
//	lv_style_copy(&cont_style,&lv_style_plain_color);//样式拷贝
//	//设置纯红色的背景
//	cont_style.body.main_color = LV_COLOR_RED;
//	cont_style.body.grad_color = LV_COLOR_RED;
//	//设置容器的4个内边距
//	cont_style.body.padding.top = 10;
//	cont_style.body.padding.left = 10;
//	cont_style.body.padding.right = 10;
//	cont_style.body.padding.bottom = 10;
//	cont_style.body.padding.inner = 10;//设置容器中子对象之间的间隙
//	
//	lv_cont_set_style(cont,LV_CONT_STYLE_MAIN,&cont_style);//给容器设置样式
//	
//	//2.创建一个提示用的label
//	tip = lv_label_create(scr,NULL);
//	lv_label_set_recolor(tip,true);//使能颜色重绘
//	info_tip();
//}

////在容器中添加子对象
//void cont_add_child()
//{
//	char no[4];//记录子对象的编号
//	lv_obj_t* child;
//	
//	child = lv_label_create(cont,NULL);
//	lv_label_set_long_mode(child,LV_LABEL_LONG_CROP);//设置长文本模式
//	lv_label_set_body_draw(child,true);//使能背景绘制
//	lv_obj_set_size(child,50,50);//设置固定的大小
//	lv_label_set_style(child,LV_LABEL_STYLE_MAIN,&lv_style_plain_color);//设置样式
//	lv_label_set_align(child,LV_LABEL_ALIGN_CENTER);//设置文本居中对齐
//	sprintf(no,"%d",child_no++);
//	lv_label_set_text(child,no);
//}

////删除容器最后添加的一个子对象
//void cont_del_child()
//{
//	lv_obj_t* child = lv_obj_get_child(cont,NULL);
//	if(child)//如果为NULL的话,说明没有子对象了
//	{
//		lv_obj_del(child);//删除掉此子对象
//		child_no--;
//	}
//}

////按键处理
//void key_handler()
//{
//	u8 key = KEY_Scan(0);
//	
//	if(key==KEY0_PRES)
//	{
//		//在cont容器中添加子对象
//		cont_add_child();
//	}else if(key==KEY1_PRES)
//	{
//		//删除掉cont容器中最后被添加进来的子对象
//		cont_del_child();
//	}else if(key==KEY2_PRES)
//	{
//		//为了让布局切换看得更明显,我们先把容器的自适应功能给关掉,然后给容器一个固定的大小
//		if(fit!=LV_FIT_NONE)//只需要执行一次就可以了
//		{
//			fit = LV_FIT_NONE;
//			lv_cont_set_fit(cont,fit);
//			lv_obj_set_size(cont,200,200);
//		}
//		//循环切换容器的布局
//		layout++;
//		if(layout==_LV_LAYOUT_NUM)
//			layout = LV_LAYOUT_CENTER;
//		lv_cont_set_layout(cont,layout);
//		info_tip();//信息提示
//	}
//}










