#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"
#include "ui_dialog.h"

#include "end.h"
#include "ui_end.h"

#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string.h>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//开始界面 开始按钮
void MainWindow::on_pushButton_clicked()
{
    Dialog d;
    d.exec();
    this->close();
}
