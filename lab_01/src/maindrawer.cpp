#include "../inc/maindrawer.h"

MyDrawWidget::MyDrawWidget(QWidget *parent) : QWidget(parent)
{

}

double MyDrawWidget::get_x(size_t i)
{
    return data.dataPoints.points[i].x + PADDING_X;
}

double MyDrawWidget::get_y(size_t i)
{
    return data.dataPoints.points[i].y + PADDING_Y;
}

void MyDrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setPen(Qt::white);
    connection_t conn;
    double x1, y1, x2, y2;
    for (size_t i = 0; i < data.dataPoints.cnt_points; i++)
        painter.drawEllipse(QPointF(get_x(i), get_y(i)), 1, 1);

    for (size_t i = 0; i < data.dataConnections.cnt_connections; i++)
    {
        conn = data.dataConnections.connections[i];
        x1 = get_x(conn.index_dot_1);
        y1 = get_y(conn.index_dot_1);
        x2 = get_x(conn.index_dot_2);;
        y2 = get_y(conn.index_dot_2);;
        painter.drawLine(x1, y1, x2, y2);
    }
}