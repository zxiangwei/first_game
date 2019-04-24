#include "end.h"
#include "ui_end.h"

#include "dialog.h"
#include "ui_dialog.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

end::end(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::end)
{
    ui->setupUi(this);
}

end::~end()
{
    delete ui;
}
//再玩一次
void end::on_pushButton_clicked()
{
    Dialog d;
    d.exec();
    this->close();
}

//不玩了
void end::on_pushButton_2_clicked()
{
    this->close();
}
