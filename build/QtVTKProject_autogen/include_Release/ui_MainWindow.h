/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "qvtkopenglnativewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action3D_Painter;
    QWidget *centralwidget;
    QComboBox *comboBox3DObjects;
    QPushButton *btnDraw;
    QPushButton *btnChooseColor;
    QLabel *label;
    QTextBrowser *textBrowser_Scale;
    QLabel *label_2;
    QTextBrowser *textBrowser_Flip;
    QLabel *label_3;
    QTextBrowser *textBrowser_Rotate;
    QLabel *label_4;
    QTextBrowser *textBrowser_xTranslate;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextBrowser *textBrowser_yTranslate;
    QLabel *label_8;
    QTextBrowser *textBrowser_Opacity;
    QPushButton *btnReDraw;
    QVTKOpenGLNativeWidget *openGLWidget;
    QMenuBar *menubar;
    QMenu *menu3D_Painter_Test;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1081, 748);
        action3D_Painter = new QAction(MainWindow);
        action3D_Painter->setObjectName("action3D_Painter");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBox3DObjects = new QComboBox(centralwidget);
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->addItem(QString());
        comboBox3DObjects->setObjectName("comboBox3DObjects");
        comboBox3DObjects->setGeometry(QRect(840, 80, 231, 28));
        btnDraw = new QPushButton(centralwidget);
        btnDraw->setObjectName("btnDraw");
        btnDraw->setGeometry(QRect(892, 170, 121, 29));
        btnChooseColor = new QPushButton(centralwidget);
        btnChooseColor->setObjectName("btnChooseColor");
        btnChooseColor->setGeometry(QRect(890, 130, 121, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(840, 50, 141, 20));
        textBrowser_Scale = new QTextBrowser(centralwidget);
        textBrowser_Scale->setObjectName("textBrowser_Scale");
        textBrowser_Scale->setGeometry(QRect(840, 300, 221, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(840, 280, 101, 20));
        textBrowser_Flip = new QTextBrowser(centralwidget);
        textBrowser_Flip->setObjectName("textBrowser_Flip");
        textBrowser_Flip->setGeometry(QRect(840, 360, 221, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(840, 340, 101, 20));
        textBrowser_Rotate = new QTextBrowser(centralwidget);
        textBrowser_Rotate->setObjectName("textBrowser_Rotate");
        textBrowser_Rotate->setGeometry(QRect(840, 420, 221, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(840, 400, 101, 20));
        textBrowser_xTranslate = new QTextBrowser(centralwidget);
        textBrowser_xTranslate->setObjectName("textBrowser_xTranslate");
        textBrowser_xTranslate->setGeometry(QRect(880, 490, 51, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(840, 460, 101, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(860, 490, 21, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(960, 490, 21, 20));
        textBrowser_yTranslate = new QTextBrowser(centralwidget);
        textBrowser_yTranslate->setObjectName("textBrowser_yTranslate");
        textBrowser_yTranslate->setGeometry(QRect(980, 490, 51, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(840, 540, 101, 20));
        textBrowser_Opacity = new QTextBrowser(centralwidget);
        textBrowser_Opacity->setObjectName("textBrowser_Opacity");
        textBrowser_Opacity->setGeometry(QRect(840, 560, 221, 31));
        btnReDraw = new QPushButton(centralwidget);
        btnReDraw->setObjectName("btnReDraw");
        btnReDraw->setGeometry(QRect(890, 620, 121, 29));
        openGLWidget = new QVTKOpenGLNativeWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(10, 20, 791, 661));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1081, 25));
        menu3D_Painter_Test = new QMenu(menubar);
        menu3D_Painter_Test->setObjectName("menu3D_Painter_Test");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu3D_Painter_Test->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action3D_Painter->setText(QCoreApplication::translate("MainWindow", "3D Painter", nullptr));
        comboBox3DObjects->setItemText(0, QCoreApplication::translate("MainWindow", "Sphere", nullptr));
        comboBox3DObjects->setItemText(1, QCoreApplication::translate("MainWindow", "Cube", nullptr));
        comboBox3DObjects->setItemText(2, QCoreApplication::translate("MainWindow", "Himisphere", nullptr));
        comboBox3DObjects->setItemText(3, QCoreApplication::translate("MainWindow", "Cone", nullptr));
        comboBox3DObjects->setItemText(4, QCoreApplication::translate("MainWindow", "Pyramid", nullptr));
        comboBox3DObjects->setItemText(5, QCoreApplication::translate("MainWindow", "Cylinder", nullptr));
        comboBox3DObjects->setItemText(6, QCoreApplication::translate("MainWindow", "Tube", nullptr));
        comboBox3DObjects->setItemText(7, QCoreApplication::translate("MainWindow", "Doughnut", nullptr));
        comboBox3DObjects->setItemText(8, QCoreApplication::translate("MainWindow", "CurvedCylinder", nullptr));

        btnDraw->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        btnChooseColor->setText(QCoreApplication::translate("MainWindow", "Choose Color", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Choose 3D Object", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Flip", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Opacity", nullptr));
        btnReDraw->setText(QCoreApplication::translate("MainWindow", "Apply Changes", nullptr));
        menu3D_Painter_Test->setTitle(QCoreApplication::translate("MainWindow", "3D Painter Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
