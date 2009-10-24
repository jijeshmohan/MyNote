#include <QApplication>
#include "notewindow.h"
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    NoteWindow *window=new NoteWindow;
    window->show();
    return app.exec();
}


/*

  1. create a toolbar for main window.
  2. status bar
  3. create a custom widget for notepage
  4. add text field,text area, and paint event for the same






  */
