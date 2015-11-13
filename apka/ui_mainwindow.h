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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
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
    QGridLayout *gridLayout_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *save_Button;
    QPushButton *load_Button;
    QFrame *frame1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLineEdit *edit_led_size;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLineEdit *edit_brush_size;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QPushButton *lowerButton;
    QPushButton *upperButton;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QSlider *GreenSlider;
    QGridLayout *gridLayout_3;
    QSlider *RedSlider;
    QLabel *label_3;
    QLabel *label;
    QSlider *BlueSlider;
    QLabel *color_label;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 680));
        MainWindow->setMaximumSize(QSize(1000, 700));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/icon/kolonia.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(320, 20, 651, 631));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));

        gridLayout_2->addLayout(gridLayout_5, 0, 0, 1, 1);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 301, 501));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame = new QFrame(layoutWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("SansSerif"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout_7->addWidget(label_5);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_7->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_7);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setMaximum(120);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setFont(font);

        verticalLayout->addWidget(pushButton_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        save_Button = new QPushButton(frame);
        save_Button->setObjectName(QStringLiteral("save_Button"));
        save_Button->setFont(font);

        horizontalLayout_5->addWidget(save_Button);

        load_Button = new QPushButton(frame);
        load_Button->setObjectName(QStringLiteral("load_Button"));
        load_Button->setFont(font);

        horizontalLayout_5->addWidget(load_Button);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_4->addWidget(frame);

        frame1 = new QFrame(layoutWidget);
        frame1->setObjectName(QStringLiteral("frame1"));
        frame1->setFrameShape(QFrame::StyledPanel);
        verticalLayout_2 = new QVBoxLayout(frame1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(frame1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout_2->addWidget(label_6);

        edit_led_size = new QLineEdit(frame1);
        edit_led_size->setObjectName(QStringLiteral("edit_led_size"));

        horizontalLayout_2->addWidget(edit_led_size);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(frame1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_3->addWidget(label_7);

        edit_brush_size = new QLineEdit(frame1);
        edit_brush_size->setObjectName(QStringLiteral("edit_brush_size"));

        horizontalLayout_3->addWidget(edit_brush_size);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(frame1);
        label_4->setObjectName(QStringLiteral("label_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);
        label_4->setFont(font);

        horizontalLayout_6->addWidget(label_4);

        lowerButton = new QPushButton(frame1);
        lowerButton->setObjectName(QStringLiteral("lowerButton"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lowerButton->sizePolicy().hasHeightForWidth());
        lowerButton->setSizePolicy(sizePolicy4);
        QFont font1;
        font1.setFamily(QStringLiteral("SansSerif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lowerButton->setFont(font1);
        lowerButton->setAutoRepeat(true);

        horizontalLayout_6->addWidget(lowerButton);

        upperButton = new QPushButton(frame1);
        upperButton->setObjectName(QStringLiteral("upperButton"));
        sizePolicy4.setHeightForWidth(upperButton->sizePolicy().hasHeightForWidth());
        upperButton->setSizePolicy(sizePolicy4);
        upperButton->setFont(font1);
        upperButton->setAutoRepeat(true);

        horizontalLayout_6->addWidget(upperButton);


        verticalLayout_2->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(frame1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        frame2 = new QFrame(layoutWidget);
        frame2->setObjectName(QStringLiteral("frame2"));
        frame2->setFrameShape(QFrame::StyledPanel);
        gridLayout_4 = new QGridLayout(frame2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(frame2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        GreenSlider = new QSlider(frame2);
        GreenSlider->setObjectName(QStringLiteral("GreenSlider"));
        GreenSlider->setMaximum(255);
        GreenSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(GreenSlider, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        RedSlider = new QSlider(frame2);
        RedSlider->setObjectName(QStringLiteral("RedSlider"));
        RedSlider->setMaximum(255);
        RedSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(RedSlider, 0, 1, 1, 1);

        label_3 = new QLabel(frame2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        label = new QLabel(frame2);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        BlueSlider = new QSlider(frame2);
        BlueSlider->setObjectName(QStringLiteral("BlueSlider"));
        BlueSlider->setMaximum(255);
        BlueSlider->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(BlueSlider, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 2, 0, 1, 1);

        color_label = new QLabel(frame2);
        color_label->setObjectName(QStringLiteral("color_label"));
        sizePolicy.setHeightForWidth(color_label->sizePolicy().hasHeightForWidth());
        color_label->setSizePolicy(sizePolicy);
        color_label->setMinimumSize(QSize(270, 30));
        color_label->setFrameShape(QFrame::StyledPanel);

        gridLayout_4->addWidget(color_label, 0, 0, 1, 1);


        verticalLayout_5->addWidget(frame2);

        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        gridLayoutWidget->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        MainWindow->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "CONNECT", 0));
        label_5->setText(QApplication::translate("MainWindow", "PORT COM", 0));
        pushButton->setText(QApplication::translate("MainWindow", "WRITE", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        save_Button->setText(QApplication::translate("MainWindow", "SAVE", 0));
        load_Button->setText(QApplication::translate("MainWindow", "LOAD", 0));
        label_6->setText(QApplication::translate("MainWindow", "LED SIZE", 0));
        label_7->setText(QApplication::translate("MainWindow", "BRUSH SIZE", 0));
        label_4->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">ROTATIO<span style=\" font-size:10pt;\">N</span></p></body></html>", 0));
        lowerButton->setText(QApplication::translate("MainWindow", "-", 0));
        upperButton->setText(QApplication::translate("MainWindow", "+", 0));
        label_2->setText(QApplication::translate("MainWindow", "G", 0));
        label_3->setText(QApplication::translate("MainWindow", "B", 0));
        label->setText(QApplication::translate("MainWindow", "R", 0));
        color_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
