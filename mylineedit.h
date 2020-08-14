#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QKeyEvent>

class MyLineEdit : public QLineEdit
{
public:
    MyLineEdit(QWidget *parent = 0);
protected:
    bool event(QEvent* e);
    void keyPressEvent(QKeyEvent* e);
};

#endif // MYLINEEDIT_H
