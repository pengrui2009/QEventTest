#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QEvent>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        qDebug() << "MainWindow event";
        //将QEvent对象转换为真正的QKeyEvent对象
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if (keyEvent->key() == Qt::Key_Tab)
        {
            qDebug() << "You press tab.";
            return true;
        }

    }
    //按照原来的流程来进行事件的分发
    return QMainWindow::event(e);
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "MainWindow mousePressEvent";
}

void MainWindow::keyPressEvent(QKeyEvent* e)
{
    qDebug() << "MainWindow::keyPressEvent";
    QMainWindow::keyPressEvent(e);
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    bool result = true;

    if (watched == ui->lineEdit)
    {
        if (event->type() == QEvent::KeyPress)
        {
            qDebug() << "MainWindow eventFilter";
            return false;
        }
    }

    return false;
}
