#include "app.h"
#include "../src/chart.h"
//#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

void app_init(int* argc, char*** argv) {
  gtk_init(argc, argv);
}

void on_open(GtkWidget* widget, gpointer user_data) {
  GtkWidget* dialog;
  gint res;

  dialog = gtk_file_chooser_dialog_new("Открыть",
                    user_data,
                    GTK_FILE_CHOOSER_ACTION_OPEN,
                    (const gchar*)"_Отмена",
                    GTK_RESPONSE_CANCEL,
                    (const gchar*)"_Открыть",
                    GTK_RESPONSE_ACCEPT,
                    NULL);
  
  res = gtk_dialog_run(GTK_DIALOG(dialog));
  //if (GTK_RESPONSE_ACCEPT == res)
    //return TRUE;
  //return FALSE;
  gtk_widget_destroy(dialog);
}

void app_ui_from_file(app_t* handle, const char* file) {
  GError* error=NULL;
  handle->builder=gtk_builder_new();
  if(!gtk_builder_add_from_file(handle->builder, file, &error))
  {
    g_warning("%s", error->message);
    g_free(error);
  }
  handle->window = GTK_WIDGET(gtk_builder_get_object(handle->builder, "window1"));    
  handle->darea = GTK_WIDGET(gtk_builder_get_object( handle->builder, "drawingarea1"));
  handle->open = GTK_WIDGET(gtk_builder_get_object( handle->builder, "imagemenuitem2"));
  gtk_builder_connect_signals(handle->builder, NULL);
  g_object_unref(G_OBJECT(handle->builder ));
  /*g_signal_connect(G_OBJECT(handle->darea), "draw", G_CALLBACK(on_draw_event), NULL);
  g_signal_connect(G_OBJECT(handle->darea), "realize", G_CALLBACK(on_realize), NULL);
  g_signal_connect(G_OBJECT(handle->darea), "size-allocate", G_CALLBACK(on_realize), NULL);
  g_signal_connect(G_OBJECT(handle->open), "activate", G_CALLBACK(on_open), NULL);*/
  gtk_widget_show(handle->window);
}

void app_main_loop() {
  gtk_main();
}

#ifdef __cplusplus
}
#endif
