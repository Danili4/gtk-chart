#include "data.h"
#include "app.h"

int main(int argc, char* argv[]) {
  app_t application;
  app_init(&argc, &argv);
  if(app_ui_from_file(&application, "ui.glade"))
  {    
    return 1;
  }
  app_main_loop();
  return 0;
}
