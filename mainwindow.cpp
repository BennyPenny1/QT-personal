#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string equation;

void MainWindow::on_btn_clear_clicked()
{
    if (equation == "")
    {
        ui->text_display->clear();
    }
    else
    {
        equation = "";
        ui->text_display->setPlainText("");
    }


}

