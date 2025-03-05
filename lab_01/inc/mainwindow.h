#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define LEN_TEXT_ERROR_MESSAGE 150
#define LEN_DATA 100

void display_error_message(char text[]);

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
