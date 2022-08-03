#ifndef __CHART_H__
#define __CHART_H__
#include <cairo/cairo.h>
#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rect rect_t;
struct rect {
  double x, y, width, height;
};

gboolean on_draw_event(GtkWidget* widget, cairo_t* cr, gpointer user_data);
void on_realize(GtkWidget* widget, gpointer user_data);
#ifdef __cplusplus
}
#endif

#endif
