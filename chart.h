#ifndef __CHART_H__
#define __CHART_H__
#include "app.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rect_tag rect_t;
struct rect_tag {
double x, y, width, height;
};

gboolean on_draw_event(GtkWidget* widget, cairo_t* cr, gpointer user_data);

#ifdef __cplusplus
}
#endif

#endif
