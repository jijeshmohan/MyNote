#ifndef NOTEWINDOW_H
#define NOTEWINDOW_H

#include <QMainWindow>

class NotePage;
class NoteWindow : public QMainWindow
{
    Q_OBJECT

public:
    NoteWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event);

private:
    void createToolbar();
    void readSettings();
    void writeSettings();

    QToolBar *toolbar;
    NotePage *notepage;

};

#endif // NOTEWINDOW_H
