#ifndef __APP_H__
#define __APP_H__

#include <cairo/cairo.h>
#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct app_tag app_t;

struct app_tag {
GtkBuilder* builder;
GtkWidget* window;
GtkWidget* darea;
};

void app_init(int* argc, char*** argv);

void app_ui_from_file(app_t* handle, const char* file);

void app_main_loop();

#ifdef __cplusplus
}
#endif

#endif
