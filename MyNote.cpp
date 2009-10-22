#include <QApplication>
#include "notewindow.h"
int main(int argc,char *argv[])
{
    QApplication app(argc,argv);
    NoteWindow *window=new NoteWindow;
    window->show();
    return app.exec();
}

