/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *start_button;
    QPushButton *reset_button;
    QPushButton *pause_button;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *goal_spin_box;
    QSpinBox *seed_spin_box;
    QSpinBox *size_spin_box;
    QLabel *label_3;
    QLabel *controlLabel;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_7;
    QPushButton *right_button;
    QPushButton *left_button;
    QPushButton *down_button;
    QPushButton *up_button;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLCDNumber *lcd_number_min;
    QLCDNumber *lcd_number_sec;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *noti_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(868, 664);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        start_button = new QPushButton(centralwidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(380, 10, 61, 28));
        reset_button = new QPushButton(centralwidget);
        reset_button->setObjectName(QString::fromUtf8("reset_button"));
        reset_button->setGeometry(QRect(380, 40, 61, 28));
        pause_button = new QPushButton(centralwidget);
        pause_button->setObjectName(QString::fromUtf8("pause_button"));
        pause_button->setGeometry(QRect(380, 70, 61, 28));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 10, 331, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        goal_spin_box = new QSpinBox(gridLayoutWidget);
        goal_spin_box->setObjectName(QString::fromUtf8("goal_spin_box"));

        gridLayout->addWidget(goal_spin_box, 1, 1, 1, 1);

        seed_spin_box = new QSpinBox(gridLayoutWidget);
        seed_spin_box->setObjectName(QString::fromUtf8("seed_spin_box"));

        gridLayout->addWidget(seed_spin_box, 0, 1, 1, 1);

        size_spin_box = new QSpinBox(gridLayoutWidget);
        size_spin_box->setObjectName(QString::fromUtf8("size_spin_box"));

        gridLayout->addWidget(size_spin_box, 2, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        controlLabel = new QLabel(centralwidget);
        controlLabel->setObjectName(QString::fromUtf8("controlLabel"));
        controlLabel->setGeometry(QRect(640, 200, 151, 20));
        controlLabel->setStyleSheet(QString::fromUtf8("color: rgb(245, 121, 0);\n"
"font: 75 11pt \"Comic Sans MS\";"));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(620, 230, 201, 141));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        right_button = new QPushButton(gridLayoutWidget_3);
        right_button->setObjectName(QString::fromUtf8("right_button"));
        right_button->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(52, 101, 164);"));

        gridLayout_7->addWidget(right_button, 1, 2, 1, 1);

        left_button = new QPushButton(gridLayoutWidget_3);
        left_button->setObjectName(QString::fromUtf8("left_button"));
        left_button->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(52, 101, 164);"));

        gridLayout_7->addWidget(left_button, 1, 0, 1, 1);

        down_button = new QPushButton(gridLayoutWidget_3);
        down_button->setObjectName(QString::fromUtf8("down_button"));
        down_button->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);\n"
"color: rgb(238, 238, 236);"));

        gridLayout_7->addWidget(down_button, 2, 1, 1, 1);

        up_button = new QPushButton(gridLayoutWidget_3);
        up_button->setObjectName(QString::fromUtf8("up_button"));
        up_button->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(52, 101, 164);"));

        gridLayout_7->addWidget(up_button, 0, 1, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(470, 10, 171, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lcd_number_min = new QLCDNumber(gridLayoutWidget_2);
        lcd_number_min->setObjectName(QString::fromUtf8("lcd_number_min"));
        lcd_number_min->setStyleSheet(QString::fromUtf8("background-color: rgb(114, 159, 207);\n"
"color: rgb(238, 238, 236);"));

        gridLayout_2->addWidget(lcd_number_min, 0, 0, 1, 1);

        lcd_number_sec = new QLCDNumber(gridLayoutWidget_2);
        lcd_number_sec->setObjectName(QString::fromUtf8("lcd_number_sec"));
        lcd_number_sec->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 101, 164);\n"
"color: rgb(238, 238, 236);"));

        gridLayout_2->addWidget(lcd_number_sec, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        noti_label = new QLabel(centralwidget);
        noti_label->setObjectName(QString::fromUtf8("noti_label"));
        noti_label->setGeometry(QRect(40, 120, 561, 20));
        noti_label->setStyleSheet(QString::fromUtf8("font: 75 11pt \"Comic Sans MS\";\n"
"color: rgb(237, 212, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 868, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        start_button->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        reset_button->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        pause_button->setText(QCoreApplication::translate("MainWindow", "Pause/ Resume", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Give a seed value or an empty line:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Give a goal value or an empty line:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Size of the game grid:", nullptr));
        controlLabel->setText(QCoreApplication::translate("MainWindow", "CONTROL BUTTONS", nullptr));
        right_button->setText(QCoreApplication::translate("MainWindow", "RIGHT", nullptr));
        left_button->setText(QCoreApplication::translate("MainWindow", "LEFT", nullptr));
        down_button->setText(QCoreApplication::translate("MainWindow", "DOWN", nullptr));
        up_button->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "seconds", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "minutes", nullptr));
        noti_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
