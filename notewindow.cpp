#include <QtGui>
#include "notewindow.h"

NoteWindow::NoteWindow(QWidget *parent):QMainWindow(parent)
{
    createToolbar();
    setWindowIcon(QIcon(":/images/appIcon"));
}

void NoteWindow::createToolbar()
{
    toolbar=addToolBar(tr("MyNote"));
    toolbar->setFloatable(false);
    toolbar->setMovable(false);
    toolbar->setIconSize(QSize(16,16));

    QAction *newAction = new QAction(QIcon(":/images/new"),tr("&New"), this);
    newAction->setShortcut(tr("Ctrl+N"));
    newAction->setToolTip("New Notepage");
    toolbar->addAction(newAction);

    QAction *deleteAction = new QAction(QIcon(":/images/delete"),tr("&Delete"), this);
    deleteAction->setToolTip("delete Notepage");
    toolbar->addAction(deleteAction);

    QWidget *spacer=new QWidget(this);
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    toolbar->addWidget(spacer);

    QAction *exitAction = new QAction(QIcon(":/images/quit"),tr("&Exit"), this);
    exitAction->setToolTip("Exit");
    toolbar->addAction(exitAction);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

}
