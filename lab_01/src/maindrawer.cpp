#include "../inc/maindrawer.h"

MyDrawWidget::MyDrawWidget(QWidget *parent) : QWidget(parent)
{

}


void MyDrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::white);
    for (size_t i = 0; i < data.cnt_points; i++)
    {
        qDebug() << data.points[i].x << " " << data.points[i].y;
        painter.drawEllipse(QPointF(data.points[i].x + WIDTH_CANVAS / 2, data.points[i].y + HEIGHT_CANVAS / 2), 1, 1);
    }
}