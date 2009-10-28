#ifndef NOTEPAGE_H
#define NOTEPAGE_H

#include <QWidget>
#include <QtGui>
class NotePage : public QWidget
{
public:
    NotePage(QWidget *parent = 0);
protected:
   void paintEvent(QPaintEvent *event);
private:
    void setupUI();
    QPlainTextEdit *contentEdit;
    QLineEdit *titleEdit;
};

#endif // NOTEPAGE_H
