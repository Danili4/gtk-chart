#include "chart.h"

void _setup_chart(GtkAllocation loc);
void _draw_background(cairo_t* cr);
void _draw_axis(cairo_t* cr);
void _draw_dashed_grid(cairo_t* cr);

static rect_t rect;
static rect_t axis;
static rect_t disp;


gboolean on_draw_event(GtkWidget* widget, cairo_t* cr, gpointer user_data)
{
GtkAllocation loc;
gtk_widget_get_allocation(widget, &loc);
_setup_chart(loc);
_draw_background(cr);
_draw_axis(cr);
_draw_dashed_grid(cr);

return FALSE;
}

void _draw_dashed_grid(cairo_t* cr)
{
int i;
cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
cairo_set_line_width(cr, 1.0);
static const double dashed[]={2.0};
cairo_set_dash(cr, dashed, 1, 0);
for(i=1;;i++)
{
if((axis.x+i*50)>=(axis.x+axis.width)) break;
cairo_move_to(cr, axis.x+i*50, axis.y);
cairo_line_to(cr, axis.x+i*50, axis.y+axis.height);
cairo_stroke(cr);
}
for(i=1;;i++)
{
if((axis.y+i*40)>=(axis.y+axis.height)) break;
cairo_move_to(cr, axis.x, axis.y+i*40);
cairo_line_to(cr, axis.x+axis.width, axis.y+i*40);
cairo_stroke(cr);
}
}

void _setup_chart(GtkAllocation loc)
{
rect.x=5.5, rect.y=5.5, rect.width=loc.width-10.5, rect.height=loc.height-10.5;
axis.x=60.5, axis.y=40.5, axis.width=rect.width-80.5, axis.height=rect.height-75.5;
disp.x=loc.x, disp.y=loc.y, disp.width=loc.width, disp.height=loc.height;
}

void _draw_axis(cairo_t* cr)
{
cairo_text_extents_t extents;
double text_length;
char* axisY="Axis Y";
char* axisX="Axis X";
cairo_set_line_width(cr, 0.15);
cairo_set_source_rgb(cr, 0.9, 0.9, 1.0);
cairo_rectangle(cr, axis.x, axis.y, axis.width, axis.height);
cairo_stroke(cr);
cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
cairo_set_font_size(cr, 10.0);
cairo_text_extents(cr, (const char*)axisY, &extents);
text_length=extents.width/2.0+extents.x_bearing;
cairo_move_to(cr, axis.x-10.0, axis.y+text_length+(axis.height)/2.0);
cairo_save(cr);
cairo_rotate(cr, -1.57);
cairo_show_text(cr, (const char*)axisY);
cairo_restore(cr);
cairo_text_extents(cr, (const char*)axisX, &extents);
text_length=extents.width/2.0+extents.x_bearing;
cairo_move_to(cr, axis.x-text_length+(axis.width)/2.0, axis.y+axis.height+20.0);
cairo_show_text(cr, (const char*)axisX);
}
void _draw_background(cairo_t* cr)
{
cairo_pattern_t* pat;
pat=cairo_pattern_create_linear(rect.width/2-5,5, rect.width/2-5, rect.height-5);
cairo_pattern_add_color_stop_rgba(pat, 0.0, 0.0, 0.07, 0.09, 0.5);
cairo_pattern_add_color_stop_rgba(pat, 1.0, 0.0, 0.0, 0.0, 0.9);
cairo_set_source(cr, pat);
cairo_rectangle(cr, rect.x, rect.y, rect.width, rect.height);
cairo_fill(cr);
}
