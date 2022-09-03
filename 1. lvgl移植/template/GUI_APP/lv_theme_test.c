#include "lv_theme_test.h"
#include "lvgl.h"


//const char * const btnm_str[] = {"1", "2", "3", LV_SYMBOL_OK, LV_SYMBOL_CLOSE, ""};

////tab1选项卡初始化
//void tab1_init(lv_obj_t * parent)
//{
//  //1.设置页面的布局方式
//  lv_page_set_scrl_layout(parent,LV_LAYOUT_PRETTY);

//  //2.创建一个按钮
//  lv_obj_t * btn = lv_btn_create(parent,NULL);
//  lv_obj_t * btn_label = lv_label_create(btn,NULL);
//  lv_label_set_text(btn_label,"Button");

//  //3.创建一个矩阵按钮
//  lv_obj_t * btnm = lv_btnm_create(parent,NULL);
//  lv_obj_set_size(btnm,LV_HOR_RES_MAX/4, 2*LV_DPI/3);
//  lv_btnm_set_map(btnm,(const char **)btnm_str);
//  lv_btnm_set_btn_ctrl_all(btnm,LV_BTNM_CTRL_TGL_ENABLE);
//  lv_btnm_set_one_toggle(btnm,true);

//  //4.创建一个开关
//  lv_sw_create(parent,NULL);

//  //5.创建一个进度条
//  lv_obj_t * bar = lv_bar_create(parent,NULL);
//  lv_bar_set_value(bar,70,false);

//  //6.创建一个滑块
//  lv_obj_t * slider = lv_slider_create(parent,NULL);
//  lv_slider_set_value(slider,50,false);

//  //7.创建一个下拉列表框
//  lv_obj_t * ddlist = lv_ddlist_create(parent,NULL);
//  lv_ddlist_set_fix_width(ddlist,lv_obj_get_width(ddlist)+LV_DPI/2);//为右侧的箭头腾出点空间
//  lv_ddlist_set_draw_arrow(ddlist,true);
//}

////tab2选项卡初始化
//void tab2_init(lv_obj_t * parent)
//{
//  //1.设置页面的布局方式
//  lv_page_set_scrl_layout(parent,LV_LAYOUT_PRETTY);

//  //2.创建一个列表
//  lv_obj_t * list = lv_list_create(parent,NULL);
//  lv_obj_set_size(list,LV_HOR_RES_MAX/4,LV_VER_RES_MAX/2);
//  lv_list_add_btn(list,LV_SYMBOL_VIDEO,"Video");
//  lv_list_add_btn(list,LV_SYMBOL_CALL,"Call");
//  lv_list_add_btn(list,LV_SYMBOL_BELL,"Bell");
//  lv_list_add_btn(list,LV_SYMBOL_FILE,"File");
//  lv_list_add_btn(list,LV_SYMBOL_EDIT,"Edit");
//  lv_list_add_btn(list,LV_SYMBOL_CUT,"Cut");
//  lv_list_add_btn(list,LV_SYMBOL_COPY,"Copy");

//  //3.创建一个滚轮
//  lv_obj_t * roller = lv_roller_create(parent,NULL);
//  lv_roller_set_options(roller,"Monday\nTuesday\nWednesday\nThursday\nFriday\nSaturday\nSunday",true);
//  lv_roller_set_selected(roller,1,false);
//  lv_roller_set_visible_row_count(roller,3);
//}


////例程入口
//void lv_theme_test_start()
//{
//  lv_obj_t * scr = lv_scr_act();//获取当前活跃的屏幕对象

//  //1.使用night主题,当然了,你也可以换成其他的主题
//  lv_theme_t * theme = lv_theme_night_init(210,NULL);//创建主题
//  lv_theme_set_current(theme);//使用主题

//  //2.在屏幕上创建一些控件来查看主题的界面效果
//  lv_obj_t * tabview = lv_tabview_create(scr,NULL);
//  //2.1 创建tab1选项卡
//  lv_obj_t * tab1 = lv_tabview_add_tab(tabview,"Tab 1");
//  tab1_init(tab1);
//  //2.2 创建tab2选项卡
//  lv_obj_t * tab2 = lv_tabview_add_tab(tabview,"Tab 2");
//  tab2_init(tab2);
//}




