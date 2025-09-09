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
    int pos = str.size()-1;
    if (str[pos] != "+" && str[pos] != "-" && str[pos] != "*" && str[pos] != "/" && str[pos] != "."){
        int indexZnaka;
        int indexBeginNumber;
        int indexEndNumber;
        QString sNumber1;
        QString sNumber2;
        QString sResult;
        double dNumber1;
        double dNumber2;
        double dResult;
        QString Tempbufstr;
        while (bufstr.contains("+") || bufstr.contains("-") || bufstr.contains("*") || bufstr.contains("/")) {
            if (bufstr.contains("*") || bufstr.contains("/")){
                for (int i=0; i<bufstr.size(); ++i){
                    if (bufstr[i] == "*" || bufstr[i] == "/"){
                        indexZnaka = i;
                        break;
                    }
                }
                for (int i=indexZnaka-1; i>=0; --i){
                    if (i == 0) indexBeginNumber = 0;
                    else if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexBeginNumber = i+1;
                        break;
                    }
                }
                for (int i=indexBeginNumber; i<indexZnaka; ++i){
                    sNumber1 += bufstr[i];
                }
                for (int i=indexZnaka+1; i<bufstr.size(); ++i){
                    if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexEndNumber = i-1;
                        break;
                    }
                    else{
                        sNumber2 += bufstr[i];
                        if (i == bufstr.size()-1) indexEndNumber = bufstr.size()-1;
                    }
                }
                dNumber1 = sNumber1.toDouble();
                dNumber2 = sNumber2.toDouble();
                if (bufstr[indexZnaka] == "*"){
                    dResult = dNumber1 * dNumber2;
                }
                else{
                    if (dNumber2 == 0){
                        str = "Error на ноль делить нельзя";
                        bufstr.clear();
                        break;
                    }
                    else {
                        dResult = dNumber1 / dNumber2;
                    }
                }
                sResult = QString::number(dResult);
                for (int i=0; i<indexBeginNumber; ++i){
                    Tempbufstr += bufstr[i];
                }
                Tempbufstr += sResult;
                for (int i=indexEndNumber+1; i<bufstr.size(); ++i){
                    Tempbufstr += bufstr[i];
                }
                bufstr = Tempbufstr;
                Tempbufstr.clear();
                sNumber1.clear();
                sNumber2.clear();
            }
            else if (bufstr.contains("+") || bufstr.contains("-")){
                for (int i=0; i<bufstr.size(); ++i){
                    if (bufstr[i] == "+" || bufstr[i] == "-"){
                        indexZnaka = i;
                        break;
                    }
                }
                for (int i=indexZnaka-1; i>=0; --i){
                    if (i == 0) indexBeginNumber = 0;
                    else if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexBeginNumber = i+1;
                        break;
                    }
                }
                for (int i=indexBeginNumber; i<indexZnaka; ++i){
                    sNumber1 += bufstr[i];
                }
                for (int i=indexZnaka+1; i<bufstr.size(); ++i){
                    if (bufstr[i] == "+" || bufstr[i] == "-" || bufstr[i] == "*" || bufstr[i] == "/"){
                        indexEndNumber = i-1;
                        break;
                    }
                    else{
                        sNumber2 += bufstr[i];
                        if (i == bufstr.size()-1) indexEndNumber = bufstr.size()-1;
                    }
                }
                dNumber1 = sNumber1.toDouble();
                dNumber2 = sNumber2.toDouble();
                if (bufstr[indexZnaka] == "+"){
                    dResult = dNumber1 + dNumber2;
                }
                else{
                    dResult = dNumber1 - dNumber2;
                }
                sResult = QString::number(dResult);
                for (int i=0; i<indexBeginNumber; ++i){
                    Tempbufstr += bufstr[i];
                }
                Tempbufstr += sResult;
                for (int i=indexEndNumber+1; i<bufstr.size(); ++i){
                    Tempbufstr += bufstr[i];
                }
                bufstr = Tempbufstr;
                Tempbufstr.clear();
                sNumber1.clear();
                sNumber2.clear();
            }
        }
        str += "=" + bufstr;
        ui->Screen->setText(str);
    }
}


