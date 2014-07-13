#include "data.h"
#include "chart.h"
//#include "app.h"

int main(int argc, char* argv[]) {
app_t application;
app_init(&argc, &argv);
app_ui_from_file(&application, "ui.glade");
g_signal_connect(G_OBJECT(application.darea), "draw", G_CALLBACK(on_draw_event), NULL);
app_main_loop();
return 0;
}
