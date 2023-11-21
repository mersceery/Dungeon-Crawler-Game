/********************************************************************************
** Form generated from reading UI file 'startscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTSCREEN_H
#define UI_STARTSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartScreen
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *StartScreen)
    {
        if (StartScreen->objectName().isEmpty())
            StartScreen->setObjectName("StartScreen");
        StartScreen->resize(1200, 700);
        label = new QLabel(StartScreen);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, 0, 1200, 700));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label->setPixmap(QPixmap(QString::fromUtf8("../textures/startscreen.png")));
        label->setScaledContents(true);
        pushButton = new QPushButton(StartScreen);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(310, 470, 270, 200));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../textures/new_game_button.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(270, 200));
        pushButton_2 = new QPushButton(StartScreen);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(580, 470, 271, 101));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../textures2/LoadGame.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(300, 200));

        retranslateUi(StartScreen);

        QMetaObject::connectSlotsByName(StartScreen);
    } // setupUi

    void retranslateUi(QDialog *StartScreen)
    {
        StartScreen->setWindowTitle(QCoreApplication::translate("StartScreen", "Dialog", nullptr));
        label->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartScreen: public Ui_StartScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTSCREEN_H
