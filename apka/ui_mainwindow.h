/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *edit_led_amount;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *edit_led_size;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *edit_brush_size;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QLineEdit *edit_gap_size;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *save_Button;
    QPushButton *load_Button;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSlider *GreenSlider;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSlider *RedSlider;
    QLabel *label_3;
    QSlider *BlueSlider;
    QLabel *color_label;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(979, 699);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../INNE/R\303\263\305\274ne/L.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(300, 20, 671, 631));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(32, 32, 251, 261));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        edit_led_amount = new QLineEdit(layoutWidget);
        edit_led_amount->setObjectName(QStringLiteral("edit_led_amount"));

        horizontalLayout->addWidget(edit_led_amount);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        edit_led_size = new QLineEdit(layoutWidget);
        edit_led_size->setObjectName(QStringLiteral("edit_led_size"));

        horizontalLayout_2->addWidget(edit_led_size);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        edit_brush_size = new QLineEdit(layoutWidget);
        edit_brush_size->setObjectName(QStringLiteral("edit_brush_size"));

        horizontalLayout_3->addWidget(edit_brush_size);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        edit_gap_size = new QLineEdit(layoutWidget);
        edit_gap_size->setObjectName(QStringLiteral("edit_gap_size"));

        horizontalLayout_4->addWidget(edit_gap_size);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        verticalLayout_3->addWidget(pushButton_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        save_Button = new QPushButton(layoutWidget);
        save_Button->setObjectName(QStringLiteral("save_Button"));

        horizontalLayout_5->addWidget(save_Button);

        load_Button = new QPushButton(layoutWidget);
        load_Button->setObjectName(QStringLiteral("load_Button"));

        horizontalLayout_5->addWidget(load_Button);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 310, 251, 84));
        gridLayout_4 = new QGridLayout(layoutWidget1);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        GreenSlider = new QSlider(layoutWidget1);
        GreenSlider->setObjectName(QStringLiteral("GreenSlider"));
        GreenSlider->setMaximum(255);
        GreenSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(GreenSlider, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        RedSlider = new QSlider(layoutWidget1);
        RedSlider->setObjectName(QStringLiteral("RedSlider"));
        RedSlider->setMaximum(255);
        RedSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(RedSlider, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        BlueSlider = new QSlider(layoutWidget1);
        BlueSlider->setObjectName(QStringLiteral("BlueSlider"));
        BlueSlider->setMaximum(255);
        BlueSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(BlueSlider, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 1, 0, 1, 1);

        color_label = new QLabel(centralWidget);
        color_label->setObjectName(QStringLiteral("color_label"));
        color_label->setGeometry(QRect(36, 402, 241, 31));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 979, 21));
        MainWindow->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(edit_led_amount);
        label_6->setBuddy(edit_led_size);
        label_7->setBuddy(edit_brush_size);
        label_8->setBuddy(edit_gap_size);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "connect", 0));
        pushButton->setText(QApplication::translate("MainWindow", "write", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "clear", 0));
        label_5->setText(QApplication::translate("MainWindow", "Led amount", 0));
        edit_led_amount->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Led size", 0));
        label_7->setText(QApplication::translate("MainWindow", "Brush size", 0));
        label_8->setText(QApplication::translate("MainWindow", "Gap size", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "change", 0));
        save_Button->setText(QApplication::translate("MainWindow", "save", 0));
        load_Button->setText(QApplication::translate("MainWindow", "load", 0));
        label_2->setText(QApplication::translate("MainWindow", "G", 0));
        label->setText(QApplication::translate("MainWindow", "R", 0));
        label_3->setText(QApplication::translate("MainWindow", "B", 0));
        color_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
