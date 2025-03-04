#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/process.h"
#include <QMessageBox>

void print_mess()
{
    QMessageBox message;
    message.setWindowTitle("Ошибка!");
    message.setText("FGHJK");
    message.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->setStyleSheet("background-color:black;");
    connect(ui->pushButton_restart, &QPushButton::clicked, this, [](){ print_all(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
