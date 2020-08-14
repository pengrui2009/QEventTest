#include <QDebug>
#include <QLineEdit>
#include <QKeyEvent>
#include "mylineedit.h"

//MyLineEdit::MyLineEdit()
//{

//}

MyLineEdit::MyLineEdit(QWidget *parent) : QLineEdit(parent)
{

}

bool MyLineEdit::event(QEvent* e)
{
   if( e->type() == QEvent::KeyPress )
   {
       qDebug() << "MyLineEdit::event";
   }
   return QLineEdit::event(e);//调用默认事件处理函数
}

void MyLineEdit::keyPressEvent(QKeyEvent* e)//键盘按键事件
{
    qDebug() << "MyLineEdit::keyPressEvent";
    QLineEdit::keyPressEvent(e);
    e->ignore();//当前对象忽略处理此事件，所以父组件对象进行事件处理函数的调用
}
