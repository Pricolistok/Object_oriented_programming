#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maindrawer.h"

#define LEN_TEXT_ERROR_MESSAGE 150
#define LEN_DATA 100

typedef enum mode_reset_data
{
    TRANSFER,
    SCALE,
    ROTATE
} mode_reset_data;

void display_error_message(const char text[LEN_TEXT_ERROR_MESSAGE]);
void sender_data(double data_x, double data_y, double data_z, mode_reset_data mode_reset);

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void read_data_from_transfer();
    void read_data_from_scale();
    void read_data_from_rotate();

private:
    Ui::MainWindow *ui;
    MyDrawWidget *drawWidget;
};
#endif
