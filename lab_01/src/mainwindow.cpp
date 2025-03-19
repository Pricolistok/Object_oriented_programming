#include "inc/mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/main_func.h"
#include "inc/errors.h"
#include <QMessageBox>
#include <QString>
#include <string>

using namespace std;


void MainWindow::work_with_errors(int error_code)
{
    switch (error_code)
    {
        case ERROR_OPEN_FILE:
            display_error_message("Ошибка при открытии файла!");
            exit(ERROR_OPEN_FILE);
        case ERROR_LEN_DATA:
            display_error_message("Ошибка при считывании длины!");
            exit(ERROR_LEN_DATA);
        case ERROR_VALUE_IN_FILE:
            display_error_message("Ошибка при данных из файла!");
            exit(ERROR_VALUE_IN_FILE);
        case ERROR_ADD_MEMORY:
            display_error_message("Ошибка при выделении данных!");
            exit(ERROR_ADD_MEMORY);
        case OK:
            drawWidget->update();
            break;
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    int error_code;
    request_t request;
    request.command = RELOAD;
    request.filename = FILE_SOURCE;
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color:black;");
    drawWidget = new MyDrawWidget(ui->widget);
    drawWidget->setGeometry(0, 0, ui->widget->width(), ui->widget->height());
    drawWidget->show();
    this->setWindowIcon(QIcon("img/icon.png"));
    this->setWindowTitle("OOP lab_01 SP");
    drawWidget->data.dataPoints.points = NULL;
    drawWidget->data.dataConnections.connections = NULL;
    connect(ui->pushButton_transfer, &QPushButton::clicked, this, &MainWindow::read_data_from_transfer);
    connect(ui->pushButton_scale, &QPushButton::clicked, this, &MainWindow::read_data_from_scale);
    connect(ui->pushButton_rotate, &QPushButton::clicked, this, &MainWindow::read_data_from_rotate);
    connect(ui->pushButton_restart, &QPushButton::clicked, this, &MainWindow::restart_picture);
    error_code = transform_data(drawWidget->data, request);
    work_with_errors(error_code);
    request.command = DRAW;
    error_code = transform_data(drawWidget->data, request);
    work_with_errors(error_code);
    drawWidget->update();
}



void MainWindow::read_data_from_transfer()
{
    int error = 0;
    QString data_x = ui->lineEdit_transfer_X->text();
    QString data_y = ui->lineEdit_transfer_Y->text();
    QString data_z = ui->lineEdit_transfer_Z->text();
    double x_result, y_result, z_result;

    bool result = true;

    x_result = data_x.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе сдвига по X!");
    }

    y_result = data_y.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе сдвига по Y!");
    }

    z_result = data_z.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе сдвига по Z!");
    }
    if (error == 0)
        sender_data(x_result, y_result, z_result, TRANSFER);
}

void MainWindow::restart_picture()
{
    request_t request;
    int error_code = OK;
    request.filename = FILE_SOURCE;
    free(drawWidget->data.dataPoints.points);
    free(drawWidget->data.dataConnections.connections);
    request.command = RELOAD;
    drawWidget->data.dataPoints.points = NULL;
    drawWidget->data.dataConnections.connections = NULL;
    error_code = transform_data(drawWidget->data, request);
    work_with_errors(error_code);
    request.command = DRAW;
    error_code = transform_data(drawWidget->data, request);
    work_with_errors(error_code);
    drawWidget->update();
}


void MainWindow::read_data_from_scale()
{
    int error = 0;
    QString data_x = ui->lineEdit_scale_X->text();
    QString data_y = ui->lineEdit_scale_Y->text();
    QString data_z = ui->lineEdit_scale_Z->text();
    double x_result, y_result, z_result;
    bool result = true;

    x_result = data_x.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе коэффициента увеличения по X!");
    }

    y_result = data_y.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе коэффициента увеличения по Y!");
    }

    z_result = data_z.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе коэффициента увеличения по Z!");
    }

    if (error == 0)
        sender_data(x_result, y_result, z_result, SCALE);
}


void MainWindow::read_data_from_rotate()
{
    int error = 0;
    QString data_x = ui->lineEdit_rotate_X->text();
    QString data_y = ui->lineEdit_rotate_Y->text();
    QString data_z = ui->lineEdit_rotate_Z->text();
    double x_result, y_result, z_result;
    bool result = true;

    x_result = data_x.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе поворота по X!");
    }

    y_result = data_y.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе поворота по Y!");
    }

    z_result = data_z.toDouble(&result);
    if (!result)
    {
        error = 1;
        display_error_message("Ошибка при вводе поворота по Z!");
    }

    if (error == 0)
        sender_data(x_result, y_result, z_result, ROTATE);
}


void MainWindow::sender_data(double data_x, double data_y, double data_z, const command mode_reset)
{
    int error_code = OK;
    request_t request;
    request.filename = FILE_SOURCE;
    switch (mode_reset)
    {
        case TRANSFER:
            request.transferParam.dx = data_x;
            request.transferParam.dy = data_y;
            request.transferParam.dz = data_z;
            request.command = TRANSFER;
            break;

        case SCALE:
            request.scaleParam.kx = data_x;
            request.scaleParam.ky = data_y;
            request.scaleParam.kz = data_z;
            request.command = SCALE;
            break;

        case ROTATE:
            request.rotateParam.angle_x = data_x;
            request.rotateParam.angle_y = data_y;
            request.rotateParam.angle_z = data_z;
            request.command = ROTATE;
            break;
        default:
            break;
    }
    error_code = transform_data(drawWidget->data, request);
    work_with_errors(error_code);
    request.command = DRAW;
    error_code = transform_data(drawWidget->data, request);
    work_with_errors(error_code);
}


void display_error_message(const char text[LEN_TEXT_ERROR_MESSAGE])
{
    QMessageBox message;
    message.setWindowTitle("Ошибка!");
    message.setText(text);
    message.exec();
}


MainWindow::~MainWindow()
{
    request_t request;
    request.command = FREE;
    transform_data(drawWidget->data, request);
    delete ui;
}
