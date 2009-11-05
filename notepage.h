#ifndef NOTEPAGE_H
#define NOTEPAGE_H

#include <QWidget>
#include <QtGui>
class NotePage : public QWidget
{
public:
    NotePage(QWidget *parent = 0,QString titleName="untitled");
protected:
   void paintEvent(QPaintEvent *event);
private:
    void setupUI();
    void setupSignalsAndSlots();

    QPlainTextEdit *contentEdit;
    QLineEdit *titleEdit;
    QString titleName;

protected slots:
    void titleChanged();
};

#endif // NOTEPAGE_H
