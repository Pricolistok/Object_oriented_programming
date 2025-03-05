#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
//#include "inc/process.h"
#include "inc/work_with_data.h"
#include <QMessageBox>
#include <string>

using namespace std;

void display_error_message(const char text[LEN_TEXT_ERROR_MESSAGE])
{
    QMessageBox message;
    message.setWindowTitle("Ошибка!");
    message.setText(text);
    message.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color:black;");
    connect(ui->pushButton_transfer, &QPushButton::clicked, this, &MainWindow::read_data_from_transfer);
}


void MainWindow::read_data_from_transfer()
{
    string data_x = ui->lineEdit_transfer_X->text().toStdString();
    string data_y = ui->lineEdit_transfer_Y->text().toStdString();
    string data_z = ui->lineEdit_transfer_Z->text().toStdString();
    const char *data;
    size_t len_data;
    bool result;

    data = data_x.c_str();
    len_data = data_x.length();
    result = validate_nums(data, len_data);

    if (!result)
        display_error_message("Ошибка при вводе сдвига по X!");

    data = data_y.c_str();
    len_data = data_x.length();
    result = validate_nums(data, len_data);

    if (!result)
        display_error_message("Ошибка при вводе сдвига по Y!");

    data = data_z.c_str();
    len_data = data_x.length();
    result = validate_nums(data, len_data);

    if (!result)
        display_error_message("Ошибка при вводе сдвига по Z!");


}


MainWindow::~MainWindow()
{
    delete ui;
}
