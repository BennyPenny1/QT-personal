/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_1;
    QPushButton *btn_2;
    QPushButton *btn_3;
    QPushButton *btn_4;
    QPushButton *btn_5;
    QPushButton *btn_8;
    QPushButton *btn_6;
    QPushButton *btn_7;
    QPushButton *btn_9;
    QPushButton *btn_0;
    QPushButton *btn_C;
    QPushButton *btn_back;
    QPushButton *btn_plus;
    QPushButton *btn_minus;
    QPushButton *btn_mult;
    QPushButton *btn_div;
    QPushButton *btn_dot;
    QPushButton *btn_neg;
    QPushButton *btn_equal;
    QTextEdit *display_text;
    QLabel *calc_back;
    QPushButton *btn_CE;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(530, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName("btn_1");
        btn_1->setGeometry(QRect(180, 230, 41, 31));
        btn_1->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName("btn_2");
        btn_2->setGeometry(QRect(220, 230, 41, 31));
        btn_2->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName("btn_3");
        btn_3->setGeometry(QRect(260, 230, 41, 31));
        btn_3->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName("btn_4");
        btn_4->setGeometry(QRect(180, 260, 41, 31));
        btn_4->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_5 = new QPushButton(centralwidget);
        btn_5->setObjectName("btn_5");
        btn_5->setGeometry(QRect(220, 260, 41, 31));
        btn_5->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_8 = new QPushButton(centralwidget);
        btn_8->setObjectName("btn_8");
        btn_8->setGeometry(QRect(220, 290, 41, 31));
        btn_8->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_6 = new QPushButton(centralwidget);
        btn_6->setObjectName("btn_6");
        btn_6->setGeometry(QRect(260, 260, 41, 31));
        btn_6->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_7 = new QPushButton(centralwidget);
        btn_7->setObjectName("btn_7");
        btn_7->setGeometry(QRect(180, 290, 41, 31));
        btn_7->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_9 = new QPushButton(centralwidget);
        btn_9->setObjectName("btn_9");
        btn_9->setGeometry(QRect(260, 290, 41, 31));
        btn_9->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_0 = new QPushButton(centralwidget);
        btn_0->setObjectName("btn_0");
        btn_0->setGeometry(QRect(220, 320, 41, 31));
        btn_0->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_C = new QPushButton(centralwidget);
        btn_C->setObjectName("btn_C");
        btn_C->setGeometry(QRect(180, 200, 41, 31));
        btn_C->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_back = new QPushButton(centralwidget);
        btn_back->setObjectName("btn_back");
        btn_back->setGeometry(QRect(260, 200, 41, 31));
        btn_back->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: #1d1d1d;\n"
"color: red;"));
        btn_plus = new QPushButton(centralwidget);
        btn_plus->setObjectName("btn_plus");
        btn_plus->setGeometry(QRect(300, 200, 41, 31));
        btn_plus->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_minus = new QPushButton(centralwidget);
        btn_minus->setObjectName("btn_minus");
        btn_minus->setGeometry(QRect(300, 230, 41, 31));
        btn_minus->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_mult = new QPushButton(centralwidget);
        btn_mult->setObjectName("btn_mult");
        btn_mult->setGeometry(QRect(300, 260, 41, 31));
        btn_mult->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_div = new QPushButton(centralwidget);
        btn_div->setObjectName("btn_div");
        btn_div->setGeometry(QRect(300, 290, 41, 31));
        btn_div->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_dot = new QPushButton(centralwidget);
        btn_dot->setObjectName("btn_dot");
        btn_dot->setGeometry(QRect(180, 320, 41, 31));
        btn_dot->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_neg = new QPushButton(centralwidget);
        btn_neg->setObjectName("btn_neg");
        btn_neg->setGeometry(QRect(260, 320, 41, 31));
        btn_neg->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        btn_equal = new QPushButton(centralwidget);
        btn_equal->setObjectName("btn_equal");
        btn_equal->setGeometry(QRect(300, 320, 41, 31));
        btn_equal->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"border: #d1d1d1;\n"
"color: #ff5b00;"));
        display_text = new QTextEdit(centralwidget);
        display_text->setObjectName("display_text");
        display_text->setGeometry(QRect(180, 100, 161, 121));
        display_text->setStyleSheet(QString::fromUtf8("background-color: #1d1d1d;\n"
"border: 0px;\n"
"color: white;"));
        calc_back = new QLabel(centralwidget);
        calc_back->setObjectName("calc_back");
        calc_back->setGeometry(QRect(170, 90, 181, 271));
        calc_back->setStyleSheet(QString::fromUtf8("background-color: #1d1d1d;\n"
""));
        btn_CE = new QPushButton(centralwidget);
        btn_CE->setObjectName("btn_CE");
        btn_CE->setGeometry(QRect(220, 200, 41, 31));
        btn_CE->setStyleSheet(QString::fromUtf8("background-color: #ffffff;\n"
"color: #1d1d1d;"));
        MainWindow->setCentralWidget(centralwidget);
        calc_back->raise();
        display_text->raise();
        btn_1->raise();
        btn_2->raise();
        btn_3->raise();
        btn_4->raise();
        btn_5->raise();
        btn_8->raise();
        btn_6->raise();
        btn_7->raise();
        btn_9->raise();
        btn_0->raise();
        btn_C->raise();
        btn_back->raise();
        btn_plus->raise();
        btn_minus->raise();
        btn_mult->raise();
        btn_div->raise();
        btn_dot->raise();
        btn_neg->raise();
        btn_equal->raise();
        btn_CE->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 530, 21));
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
        btn_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_C->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btn_back->setText(QCoreApplication::translate("MainWindow", "<-", nullptr));
        btn_plus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_minus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn_mult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btn_div->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btn_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btn_neg->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        btn_equal->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        display_text->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        calc_back->setText(QString());
        btn_CE->setText(QCoreApplication::translate("MainWindow", "CE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
