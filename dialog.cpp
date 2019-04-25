#include "dialog.h"
#include "ui_dialog.h"

#include "end.h"
#include "ui_end.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>

#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <QDir>
using namespace std;

vector<int> sscore;

QFile ff1("D:\\QT\\last_homework\\save1.txt");
QFile ff2("D:\\QT\\last_homework\\log.txt");
QFile ff3("D:\\QT\\last_homework\\save2.txt");
int r=1;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    score=0;
    //f1.open("save.txt",ios::in|ios::out);//保存游戏
    //f2.open("log.txt",ios::in|ios::out);//记录分数
    //if(f1.eof())    this->close();
    //if(f2.eof())    this->close();
    QDir *folder = new QDir;
    //判断创建文件夹是否存在
    bool exist = folder->exists("D:\\QT\\last_homework");
    if(exist&&r==1)
    {
        QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹已经存在！"));
        r=0;
    }
    if(!exist){
        //创建文件夹
        bool ok = folder->mkdir("D:\\QT\\last_homework");
    }
        //判断是否成功
           /*if(ok)
           {
               QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建成功！"));
           }
           else
           {
               QMessageBox::warning(this,tr("创建文件夹"),tr("文件夹创建失败！"));
           }*/
}


Dialog::~Dialog()
{
    delete ui;
    //f1.close();
    //f2.close();
    //ff1.close();
    //ff2.close();
}

//游戏界面 取消 按钮
void Dialog::on_pushButton_3_clicked()
{
    class::end e;
    e.exec();
    this->close();
}

//游戏界面 确定 按钮
//1，3，7，8  左，右，分数，历史纪录

void Dialog::on_pushButton_clicked()
{
    Dialog d1;
    QString temp,temp0,temp1,temp2="right!",temp3="wrong!";
    temp0=ui->label->text();
    temp1=ui->label_3->text();
    temp=ui->lineEdit->text();

    //if(d1.exec()==QDialog::Accepted);

    int nn1=temp1.toInt();
    int nn2=temp0.toInt();
    int nn=temp.toInt();

    QString s;

    if(nn==(nn1+nn2))
    {
        ui->lineEdit_2->setText(temp2);
        score++;
        s.sprintf("%d",score);
        ui->label_7->setText(s);
    }
    else
    {
        ui->lineEdit_2->setText(temp3);
        score=0;
        s.sprintf("%d",score);
        ui->label_7->setText(s);
    }
    on_pushButton_2_clicked();
}

//游戏界面 换个题 按钮
//1，3，7，8  左，右，分数，历史纪录

void Dialog::on_pushButton_2_clicked()
{
    int left,right;
    srand(time(0));
    left=rand()%100000+1;
    right=rand()%100000+1;

    QString temp;
    temp.sprintf("%d",left);
    ui->label->setText(temp);

    temp.sprintf("%d",right);
    ui->label_3->setText(temp);

}

//存档
void Dialog::on_pushButton_4_clicked()
{
    QString s;
    s=ui->label_7->text();
    string temp;
    temp=s.toStdString();
    if(ff2.open(QFile::WriteOnly | QIODevice::Text |QFile::ReadOnly));
        QTextStream out2(&ff2);
        out2<<s<<endl;
    if (ff1.open(QFile::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out1(&ff1);
        out1<<s<<endl;
        ff1.close();
    }
    ff2.open(QFile::WriteOnly | QIODevice::Text |QFile::ReadOnly);
    while(!ff2.atEnd()){
        QString temp;
        char buffer[1024];
        ff2.readLine(buffer,1024);
        for(int i=0;i<1024;++i){
            temp+=buffer[i];
        }
        int nn=temp.toInt();
        sscore.push_back(nn);
        ff2.close();
    }
    QString temp0="0",temp1="0",temp2="0";
    ff3.open(QFile::WriteOnly | QFile::ReadOnly | QIODevice::Text | QIODevice::Truncate);
    QTextStream out3(&ff3);
    temp0=ui->label->text();
    temp1=ui->label_3->text();
    temp2=ui->lineEdit->text();
    out3<<temp0<<endl<<temp1<<endl<<temp2<<endl;
    ff3.close();
    //历史纪录有bug    vector 无法使用
    /*int nn2=max_element(sscore.begin(),sscore.end());
    QString ss;
    auto tempp=sscore[nn2];
    ss.sprintf("%d",tempp);
    ui->label_8->setText("1");
    */

    //QTextStream txtOutput1(&ff1);
    //QTextStream txtOutput2(&ff2);
    //txtOutput1<<s<<endl;
    //txtOutput2<<s<<endl;
    //c++写入文件失败
    //f1.write((char *)temp.c_str(),temp.size());
    //f1<<"temp"<<endl;
}

//读取上次存档
void Dialog::on_pushButton_5_clicked()
{
    QString temp0,temp,temp1,temp2;
    //ff3.open(QFile::ReadOnly);
    ff3.open(QFile::WriteOnly | QFile::ReadOnly | QIODevice::Text );
    QTextStream ss(&ff3);
    ss>>temp0;
    ss>>temp1;
    ss>>temp2;
    /*  char buffer[1024];
        ff3.readLine(buffer,1024);
        ui->label->setText(buffer);

        ff3.readLine(buffer,1024);
        ui->label_3->setText(buffer);

        ff3.readLine(buffer,1024);
        ui->lineEdit->setText(buffer);
        */
    ui->label->setText(temp0);
    ui->label_3->setText(temp1);
    ui->lineEdit->setText(temp2);
    /*
    temp0=ui->label->text();
    temp1=ui->label_3->text();
    temp=ui->lineEdit->text();
    */
}
