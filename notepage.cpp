#include <QtGui>
#include "notepage.h"

NotePage::NotePage(QWidget *parent):QWidget(parent)
{
    setupUI();
}

void NotePage::setupUI()
{

    QGridLayout *gridLayout_2 = new QGridLayout(this);
    gridLayout_2->setSpacing(0);
    gridLayout_2->setMargin(0);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setSpacing(0);

    QHBoxLayout *horizontalLayout = new QHBoxLayout();
    QSpacerItem *verticalSpacer = new QSpacerItem(17, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
    horizontalLayout->addItem(verticalSpacer);
    QSpacerItem *horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    horizontalLayout->addItem(horizontalSpacer_2);
    gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);


    titleEdit = new QLineEdit(this);

    QFont font;
    font.setFamily(QString::fromUtf8("Consolas"));
    font.setPointSize(12);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(false);
    font.setWeight(75);
    font.setKerning(false);
    titleEdit->setFont(font);
    titleEdit->setFrame(false);
    titleEdit->setReadOnly(false);

    gridLayout->addWidget(titleEdit, 1, 1, 1, 1);

    QVBoxLayout *verticalLayout = new QVBoxLayout();

    QSpacerItem *horizontalSpacer = new QSpacerItem(52, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

    verticalLayout->addItem(horizontalSpacer);

    QSpacerItem *verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_2);


    gridLayout->addLayout(verticalLayout, 2, 0, 1, 1);

    contentEdit = new QPlainTextEdit(this);
    QFont font1;
    font1.setFamily(QString::fromUtf8("Nimbus Sans L"));
    font1.setPointSize(11);
    contentEdit->setFont(font1);
    contentEdit->setFrameShape(QFrame::NoFrame);
    contentEdit->setFrameShadow(QFrame::Plain);

    gridLayout->addWidget(contentEdit, 2, 1, 1, 1);


    gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

    // need to refactor
    QPalette pal = titleEdit->palette();
    pal.setColor(titleEdit->backgroundRole(), Qt::transparent);
    titleEdit->setPalette(pal);

    contentEdit->setAutoFillBackground(false);
    contentEdit->viewport()->setAutoFillBackground(false);
    contentEdit->verticalScrollBar()->setVisible(false);
}


void NotePage::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // painter.setBrush(Qt::white);
    painter.setBrush(QColor(255,255,200));
    painter.drawRect(0,0,this->width(),this->height());
    painter.setPen(QColor(255,0,0,128));
    painter.drawLine(50,0,50,this->height());
    QFontMetrics fontM(contentEdit->font());
    int lineHeight=fontM.height();
    // FOR LINUX we have to use Line width


    painter.setPen(QColor(153,204,255,128));

    int startheight=20 + titleEdit->height();
    //    lineHeight += 1;
    for(int i=startheight ;i<= this->height();i+=lineHeight)
    {
        painter.drawLine(0,i,this->width(),i);
    }

}
