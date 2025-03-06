#include "../inc/maindrawer.h"

MyDrawWidget::MyDrawWidget(QWidget *parent) : QWidget(parent)
{

}


void MyDrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::white);
    painter.drawEllipse(QPointF(WIDTH_CANVAS / 2, HEIGHT_CANVAS / 2), 1, 1);
}