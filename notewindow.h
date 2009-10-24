#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>

class NoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    NoteWindow(QWidget *parent = 0);

private:
    void createToolbar();

    QToolBar *toolbar;
};

#endif // NOTEWINDOW_H
