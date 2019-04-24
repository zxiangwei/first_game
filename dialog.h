#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <fstream>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

public:
    Ui::Dialog *ui;
    int score;
    //fstream f1;
    //fstream f2;
    //QFile file("D:\QT\last_homework\save.txt");
    //QFile ff2("D:\QT\last_homework\log.txt");
};

#endif // DIALOG_H
