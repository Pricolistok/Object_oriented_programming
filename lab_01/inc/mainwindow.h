#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maindrawer.h"
#include "../inc/consts.h"
#include "../inc/struct.h"

//#define FILE_SOURCE "data/data_cube.txt"
//#define FILE_SOURCE "data/data_pyramid.txt"
#define FILE_SOURCE "data/data_cat.txt"

#define LEN_TEXT_ERROR_MESSAGE 150

void display_error_message(const char text[LEN_TEXT_ERROR_MESSAGE]);

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    dataset data_all;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void work_with_errors(int error_code);
    void read_data_from_transfer();
    void read_data_from_scale();
    void read_data_from_rotate();
    void restart_picture();
    void sender_data(double data_x, double data_y, double data_z, command mode_reset);

private:
    Ui::MainWindow *ui;
    MyDrawWidget *drawWidget;
};
#endif
