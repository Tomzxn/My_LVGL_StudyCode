#include "test.h"

lv_style_t line_style;
const lv_point_t points[] = {{10,10},{50,70},{80,50},{100,100}};
#define points_num (sizeof(points)/sizeof(points[0]))

void event_handler(lv_obj_t* obj,lv_event_t event)
{

}


void test_start()
{
    lv_obj_t* scr = lv_scr_act();

    lv_style_copy(&line_style,&lv_style_plain_color);
    line_style.line.color = LV_COLOR_RED;
    line_style.line.width = 4;
    line_style.line.rounded = 1;


    lv_obj_t* line1 =lv_line_create(scr,NULL);
    lv_line_set_auto_size(line1,false);
    lv_obj_set_size(line1,200,200);
    lv_obj_align(line1,NULL,LV_ALIGN_CENTER,0,0);
    lv_line_set_points(line1,points,points_num);
    lv_line_set_style(line1,LV_LINE_STYLE_MAIN,&line_style);
}
