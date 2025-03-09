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


class MyDrawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyDrawWidget(QWidget *parent = nullptr);
    dataset data;

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif