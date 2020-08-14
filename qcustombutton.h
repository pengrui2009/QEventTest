#ifndef QCUSTOMBUTTON_H
#define QCUSTOMBUTTON_H
#include <QPushButton>
#include <QWidget>
#include <QEvent>

class QCustomButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QCustomButton(QWidget *parent = 0);

protected:
//    void paintEvent(QPaintEvent *);
    bool event(QEvent *e);
    void mousePressEvent(QMouseEvent *e);
signals:

public slots:
};

#endif // QCUSTOMBUTTON_H
