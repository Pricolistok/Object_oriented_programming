#ifndef MAINDRAWER_H__
#define MAINDRAWER_H__

#include <QWidget>
#include <QPainter>
#include <QPointF>
#include <QMainWindow>
#include <QPainterPath>

#define HEIGHT_CANVAS 600
#define WIDTH_CANVAS 1200


class MyDrawWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyDrawWidget(QWidget *parent = nullptr);


protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif