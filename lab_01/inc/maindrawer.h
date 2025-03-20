#ifndef MAINDRAWER_H__
#define MAINDRAWER_H__

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QMainWindow>
#include <QPainterPath>
#include "../inc/struct.h"

#define HEIGHT_CANVAS 600
#define WIDTH_CANVAS 1200
#define PADDING_X 600
#define PADDING_Y 300

class MyDrawWidget : public QWidget
{
    Q_OBJECT

public:
    double get_x(size_t i);
    double get_y(size_t i);
    explicit MyDrawWidget(QWidget *parent = nullptr);
    dataset_projection_t data;

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif