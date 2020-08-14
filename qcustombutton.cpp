#include <QDebug>
#include "qcustombutton.h"
#include <QPainter>

#include <QKeyEvent>

QCustomButton::QCustomButton(QWidget *parent) : QPushButton(parent)
{

}

//void QCustomButton::paintEvent(QPaintEvent *)
//{
//    QPainter painter(this);
//    int radius = 50;

//    painter.save();
//    painter.setPen(Qt::NoPen);
//    painter.setBrush(Qt::yellow);
//    painter.drawEllipse(-radius, -radius, radius * 2, radius * 2);
//    painter.restore();
//}

bool QCustomButton::event(QEvent *e)
{
    if (e->type() == QEvent::KeyPress)
    {
        //将QEvent对象转换为真正的QKeyEvent对象
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(e);
        if (keyEvent->key() == Qt::Key_Tab)
        {
            qDebug() << "QCustomButton You press tab.";
            return true;
        }
    }
    //按照原来的流程来进行事件的分发
//    return QWidget::event(e);
    return false;
}

void QCustomButton::mousePressEvent(QMouseEvent *e)
{

    qDebug() << "QCustomButton mousePressEvent";

}
