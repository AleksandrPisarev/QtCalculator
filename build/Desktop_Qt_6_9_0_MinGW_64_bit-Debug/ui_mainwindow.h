/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *body;
    QLabel *Screen;
    QPushButton *B1;
    QPushButton *B2;
    QPushButton *B3;
    QPushButton *B4;
    QPushButton *B5;
    QPushButton *B6;
    QPushButton *B9;
    QPushButton *B0;
    QPushButton *Point;
    QPushButton *Minus;
    QPushButton *Plus;
    QPushButton *GetResult;
    QPushButton *B7;
    QPushButton *B8;
    QPushButton *Multiplay;
    QPushButton *Divide;
    QPushButton *Clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1208, 670);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        body = new QLabel(centralwidget);
        body->setObjectName("body");
        body->setGeometry(QRect(430, 40, 301, 501));
        body->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 27, 27);"));
        Screen = new QLabel(centralwidget);
        Screen->setObjectName("Screen");
        Screen->setGeometry(QRect(440, 60, 281, 41));
        QFont font;
        font.setPointSize(12);
        Screen->setFont(font);
        Screen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        B1 = new QPushButton(centralwidget);
        B1->setObjectName("B1");
        B1->setGeometry(QRect(440, 140, 75, 24));
        B2 = new QPushButton(centralwidget);
        B2->setObjectName("B2");
        B2->setGeometry(QRect(530, 140, 75, 24));
        B3 = new QPushButton(centralwidget);
        B3->setObjectName("B3");
        B3->setGeometry(QRect(620, 140, 75, 24));
        B4 = new QPushButton(centralwidget);
        B4->setObjectName("B4");
        B4->setGeometry(QRect(440, 180, 75, 24));
        B5 = new QPushButton(centralwidget);
        B5->setObjectName("B5");
        B5->setGeometry(QRect(530, 180, 75, 24));
        B6 = new QPushButton(centralwidget);
        B6->setObjectName("B6");
        B6->setGeometry(QRect(620, 180, 75, 24));
        B9 = new QPushButton(centralwidget);
        B9->setObjectName("B9");
        B9->setGeometry(QRect(620, 220, 75, 24));
        B0 = new QPushButton(centralwidget);
        B0->setObjectName("B0");
        B0->setGeometry(QRect(440, 260, 75, 24));
        Point = new QPushButton(centralwidget);
        Point->setObjectName("Point");
        Point->setGeometry(QRect(530, 260, 75, 24));
        Minus = new QPushButton(centralwidget);
        Minus->setObjectName("Minus");
        Minus->setGeometry(QRect(440, 320, 75, 24));
        Plus = new QPushButton(centralwidget);
        Plus->setObjectName("Plus");
        Plus->setGeometry(QRect(530, 320, 75, 24));
        GetResult = new QPushButton(centralwidget);
        GetResult->setObjectName("GetResult");
        GetResult->setGeometry(QRect(620, 360, 75, 24));
        B7 = new QPushButton(centralwidget);
        B7->setObjectName("B7");
        B7->setGeometry(QRect(440, 220, 75, 24));
        B8 = new QPushButton(centralwidget);
        B8->setObjectName("B8");
        B8->setGeometry(QRect(530, 220, 75, 24));
        Multiplay = new QPushButton(centralwidget);
        Multiplay->setObjectName("Multiplay");
        Multiplay->setGeometry(QRect(620, 320, 75, 24));
        Divide = new QPushButton(centralwidget);
        Divide->setObjectName("Divide");
        Divide->setGeometry(QRect(440, 360, 75, 24));
        Clear = new QPushButton(centralwidget);
        Clear->setObjectName("Clear");
        Clear->setGeometry(QRect(620, 260, 75, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1208, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        body->setText(QString());
        Screen->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        B2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        B3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        B4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        B5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        B6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        B9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        B0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Point->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        Minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        GetResult->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        B7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        B8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Multiplay->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        Divide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        Clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
