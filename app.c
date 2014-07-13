#include "app.h"


#ifdef __cplusplus
extern "C" {
#endif

void app_init(int* argc, char*** argv) {
gtk_init(argc, argv);
}

void app_ui_from_file(app_t* handle, const char* file) {
GError* error=NULL;
handle->builder=gtk_builder_new();
if( ! gtk_builder_add_from_file( handle->builder, file, &error ))
    {
        g_warning( "%s", error->message );
        g_free( error );
    }
    handle->window = GTK_WIDGET( gtk_builder_get_object( handle->builder, "window1" ) );
    
    handle->darea = GTK_WIDGET( gtk_builder_get_object( handle->builder, "drawingarea1" ) );

    gtk_builder_connect_signals( handle->builder, NULL );

    g_object_unref( G_OBJECT( handle->builder ) );

    gtk_widget_show( handle->window );
}

void app_main_loop() {
gtk_main();
}

#ifdef __cplusplus
}
#endif
