#include <QtGui>
#include "notewindow.h"
#include "notepage.h"

NoteWindow::NoteWindow(QWidget *parent):QMainWindow(parent)
{
    createToolbar();
    readSettings();

    notepage = new NotePage(this);
    setCentralWidget(notepage);
    setWindowIcon(QIcon(":/images/appIcon"));
    setWindowTitle("My Note");
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
void NoteWindow::readSettings()
{
    QSettings settings("OSS", "MyNote");
    restoreGeometry(settings.value("geometry").toByteArray());
}
void NoteWindow::writeSettings()
{
    QSettings settings("OSS", "MyNote");
    settings.setValue("geometry", saveGeometry());
}
void NoteWindow::closeEvent(QCloseEvent *event)
{
    writeSettings();
}
