#include "../inc/maindrawer.h"

MyDrawWidget::MyDrawWidget(QWidget *parent) : QWidget(parent)
{

}


void MyDrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::white);
    double x1, y1, x2, y2;
    for (size_t i = 0; i < data.cnt_points; i++)
    {
        qDebug() << data.points[i].x << " " << data.points[i].y;
        painter.drawEllipse(QPointF(data.points[i].x + WIDTH_CANVAS / 2, data.points[i].y + HEIGHT_CANVAS / 2), 1, 1);
    }
    for (size_t i = 0; i < data.cnt_connections; i++)
    {
        x1 = data.points[data.connections[i].index_dot_1].x + WIDTH_CANVAS / 2;
        y1 = data.points[data.connections[i].index_dot_1].y + HEIGHT_CANVAS / 2;
        x2 = data.points[data.connections[i].index_dot_2].x + WIDTH_CANVAS / 2;
        y2 = data.points[data.connections[i].index_dot_2].y + HEIGHT_CANVAS / 2;
        painter.drawLine(x1, y1, x2, y2);
    }
}