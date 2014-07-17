#include "data.h"
//#include "chart.h"
#include "app.h"

int main(int argc, char* argv[]) {
app_t application;
app_init(&argc, &argv);
app_ui_from_file(&application, "ui.glade");
app_main_loop();
return 0;
}
