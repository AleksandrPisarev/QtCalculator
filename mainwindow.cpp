#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->B0, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B1, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B2, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B3, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B4, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B5, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B6, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B7, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B8, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->B9, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->Plus, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->Minus, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->Multiplay, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->Divide, SIGNAL(clicked()), this, SLOT(getDigit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDigit()
{
    QPushButton* btn = (QPushButton*)sender();
    QString str = ui->Screen->text();
    if (ui->Screen->text() == "0"){
        if (btn == ui->Plus || btn == ui->Minus || btn == ui->Multiplay || btn == ui->Divide || btn == ui->GetResult){
            str += btn->text();
            ui->Screen->setText(str);
        }
        else {
            str = btn->text();
            ui->Screen->setText(str);
        }
    }

    else {
        if (btn == ui->Plus || btn == ui->Minus || btn == ui->Multiplay || btn == ui->Divide){
            int pos = str.size()-1;
            if (str[pos] != "+" && str[pos] != "-" && str[pos] != "*" && str[pos] != "/" && str[pos] != "."){
                str += btn->text();
                ui->Screen->setText(str);
            }
        }
        else {
            str += btn->text();
            ui->Screen->setText(str);
        }
    }
}

void MainWindow::on_Point_clicked()
{
    QString str = ui->Screen->text();
    int pos = str.size()-1;
    QString number;
    if (str[pos] != "+" && str[pos] != "-" && str[pos] != "*" && str[pos] != "/" && str[pos] != "."){
        for (int i=str.size()-1; i>=0; --i){
            if (str[i] == "+" || str[i] == "-" || str[i] == "*" || str[i] == "/"){
                break;
            }
            else number += str[i];
        }
        if (!number.contains(".")){
            str += ".";
            ui->Screen->setText(str);
        }
    }
}

void MainWindow::on_Clear_clicked()
{
     ui->Screen->setText("0");
}


void MainWindow::on_GetResult_clicked()
{
    QString str = ui->Screen->text();
    QString bufstr = str;
    //int pos = str.size()-1;
    //if (str[pos] != "+" && str[pos] != "-" && str[pos] != "*" && str[pos] != "/" && str[pos] == "."){
        int indexAction;
        QString number1;
        QString number2;
        int indexBegin;
        int indexEnd;
        double first;
        double second;
        double result;
        QString value;
        QString buf_str;
        while (bufstr.contains("+") || bufstr.contains("-") || bufstr.contains("*") || bufstr.contains("/")) {
            if (bufstr.contains("*") || bufstr.contains("/")){
                for (int i=0; i<bufstr.size(); ++i){
                    if (bufstr[i] == "*" || bufstr[i] == "/"){
                        indexAction = i;
                        break;
                    }
                }
                for (int i=indexAction-1; i>=0; --i){
                    if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexBegin = i+1;
                        break;
                    }
                    else {
                       number1 += bufstr[i];
                       if (i == 0) indexBegin = 0;
                    }
                }
                for (int i=indexAction+1; i<bufstr.size(); ++i){
                    if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexEnd = i-1;
                        break;
                    }
                    else{
                        number2 += bufstr[i];
                        if (i == bufstr.size()-1) indexEnd = bufstr.size()-1;
                    }
                }
                first = number1.toDouble();
                second = number2.toDouble();
                if (bufstr[indexAction] == "*"){
                    result = first * second;
                }
                else{
                    result = first / second;
                }
                value = QString::number(result);
                for (int i=0; i<indexBegin; ++i){
                    buf_str += bufstr[i];
                }
                buf_str += value;
                for (int i=indexEnd+1; i<bufstr.size(); ++i){
                    buf_str += bufstr[i];
                }
                bufstr = buf_str;
            }
            else if (bufstr.contains("+") || bufstr.contains("-")){
                for (int i=0; i<bufstr.size(); ++i){
                    if (bufstr[i] == "+" || bufstr[i] == "-"){
                        indexAction = i;
                        break;
                    }
                }
                for (int i=indexAction-1; i>=0; --i){
                    if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexBegin = i+1;
                        break;
                    }
                    else{
                        number1 += bufstr[i];
                        if (i == 0) indexBegin = 0;
                    }
                }
                for (int i=indexAction+1; i<bufstr.size(); ++i){
                    if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexEnd = i-1;
                        break;
                    }
                    else{
                        number2 += bufstr[i];
                        if (i == bufstr.size()-1) indexEnd = bufstr.size()-1;
                    }
                }
                first = number1.toDouble();
                second = number2.toDouble();
                if (bufstr[indexAction] == "+"){
                    result = first + second;
                }
                else{
                    result = first - second;
                }
                value = QString::number(result);
                for (int i=0; i<indexBegin; ++i){
                    buf_str += bufstr[i];
                }
                buf_str += value;
                for (int i=indexEnd+1; i<bufstr.size(); ++i){
                    buf_str += bufstr[i];
                }
                bufstr = buf_str;
            }
        }
    //}
    str += "=" + bufstr;
    ui->Screen->setText(str);
}


