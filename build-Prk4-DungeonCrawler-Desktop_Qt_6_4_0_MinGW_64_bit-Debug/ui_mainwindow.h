/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *widget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *widget_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QWidget *widget_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QProgressBar *progressBar;
    QLabel *HPLabel;
    QLabel *StaminaLabel;
    QLabel *StrengthLabel;
    QLabel *StaWertLabel;
    QLabel *StreWertLabel;
    QPushButton *SaveButton;
    QLabel *winLabel;
    QLabel *loseLabel;
    QPushButton *exitButton;
    QLabel *label_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(0, 0, 1200, 700));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(20, 90, 800, 500));
        widget->setAutoFillBackground(false);
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 1202, 702));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(890, 280, 291, 231));
        widget_2->setAutoFillBackground(false);
        gridLayoutWidget_2 = new QWidget(widget_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(20, 20, 251, 191));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 1200, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label->setPixmap(QPixmap(QString::fromUtf8("../textures/bloody_frame.png")));
        label->setScaledContents(true);
        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(880, 110, 300, 151));
        widget_3->setAutoFillBackground(false);
        gridLayoutWidget_3 = new QWidget(widget_3);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(0, 0, 301, 101));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(gridLayoutWidget_3);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        gridLayout_3->addWidget(progressBar, 0, 1, 1, 1);

        HPLabel = new QLabel(gridLayoutWidget_3);
        HPLabel->setObjectName("HPLabel");
        HPLabel->setEnabled(true);

        gridLayout_3->addWidget(HPLabel, 0, 0, 1, 1);

        StaminaLabel = new QLabel(gridLayoutWidget_3);
        StaminaLabel->setObjectName("StaminaLabel");

        gridLayout_3->addWidget(StaminaLabel, 1, 0, 1, 1);

        StrengthLabel = new QLabel(gridLayoutWidget_3);
        StrengthLabel->setObjectName("StrengthLabel");

        gridLayout_3->addWidget(StrengthLabel, 2, 0, 1, 1);

        StaWertLabel = new QLabel(gridLayoutWidget_3);
        StaWertLabel->setObjectName("StaWertLabel");

        gridLayout_3->addWidget(StaWertLabel, 1, 1, 1, 1);

        StreWertLabel = new QLabel(gridLayoutWidget_3);
        StreWertLabel->setObjectName("StreWertLabel");

        gridLayout_3->addWidget(StreWertLabel, 2, 1, 1, 1);

        SaveButton = new QPushButton(groupBox);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setGeometry(QRect(930, 530, 181, 61));
        SaveButton->setAutoFillBackground(false);
        SaveButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("textures/Save-Button-PNG-Cutout.png"), QSize(), QIcon::Normal, QIcon::Off);
        SaveButton->setIcon(icon);
        winLabel = new QLabel(groupBox);
        winLabel->setObjectName("winLabel");
        winLabel->setGeometry(QRect(0, 0, 1201, 661));
        loseLabel = new QLabel(groupBox);
        loseLabel->setObjectName("loseLabel");
        loseLabel->setGeometry(QRect(0, 0, 1201, 671));
        exitButton = new QPushButton(groupBox);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(980, 220, 121, 41));
        label->raise();
        widget->raise();
        widget_2->raise();
        widget_3->raise();
        SaveButton->raise();
        winLabel->raise();
        loseLabel->raise();
        exitButton->raise();
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 1200, 700));
        MainWindow->setCentralWidget(centralwidget);
        label_2->raise();
        groupBox->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QString());
        HPLabel->setText(QCoreApplication::translate("MainWindow", "HP", nullptr));
        StaminaLabel->setText(QCoreApplication::translate("MainWindow", "Stamina", nullptr));
        StrengthLabel->setText(QCoreApplication::translate("MainWindow", "Strength", nullptr));
        StaWertLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        StreWertLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        SaveButton->setText(QString());
        winLabel->setText(QString());
        loseLabel->setText(QString());
        exitButton->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
