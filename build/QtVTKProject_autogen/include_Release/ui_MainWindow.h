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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QLabel *label_2;
    QLabel *label_8;
    QPushButton *btnUndo;
    QVTKOpenGLNativeWidget *openGLWidget;
    QLineEdit *lineEdit_Scale;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineEdit_Xtranslate;
    QLabel *label_11;
    QLineEdit *lineEdit_Ytranslate;
    QLineEdit *lineEdit_Ztranslate;
    QLabel *label_12;
    QPushButton *btnTranslate;
    QLineEdit *lineEdit_Opacity;
    QPushButton *btnScale;
    QPushButton *btnRotate;
    QPushButton *btnOpacity;
    QPushButton *btnRedo;
    QPushButton *btnDelete;
    QPushButton *btnFlip;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QLabel *label_13;
    QLineEdit *lineEdit_Zrotate;
    QLineEdit *lineEdit_Yrotate;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineEdit_Xrotate;
    QLabel *label_16;
    QLabel *labelSavedLoadedMessage;
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
        comboBox3DObjects->setGeometry(QRect(820, 50, 251, 31));
        btnDraw = new QPushButton(centralwidget);
        btnDraw->setObjectName("btnDraw");
        btnDraw->setGeometry(QRect(820, 90, 251, 29));
        btnChooseColor = new QPushButton(centralwidget);
        btnChooseColor->setObjectName("btnChooseColor");
        btnChooseColor->setGeometry(QRect(820, 130, 251, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(820, 30, 141, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(820, 260, 101, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(820, 490, 101, 20));
        btnUndo = new QPushButton(centralwidget);
        btnUndo->setObjectName("btnUndo");
        btnUndo->setGeometry(QRect(820, 170, 121, 29));
        openGLWidget = new QVTKOpenGLNativeWidget(centralwidget);
        openGLWidget->setObjectName("openGLWidget");
        openGLWidget->setGeometry(QRect(10, 20, 791, 661));
        lineEdit_Scale = new QLineEdit(centralwidget);
        lineEdit_Scale->setObjectName("lineEdit_Scale");
        lineEdit_Scale->setGeometry(QRect(820, 280, 201, 28));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(820, 320, 101, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(820, 400, 20, 20));
        lineEdit_Xtranslate = new QLineEdit(centralwidget);
        lineEdit_Xtranslate->setObjectName("lineEdit_Xtranslate");
        lineEdit_Xtranslate->setGeometry(QRect(840, 400, 41, 28));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(890, 400, 20, 20));
        lineEdit_Ytranslate = new QLineEdit(centralwidget);
        lineEdit_Ytranslate->setObjectName("lineEdit_Ytranslate");
        lineEdit_Ytranslate->setGeometry(QRect(910, 400, 41, 28));
        lineEdit_Ztranslate = new QLineEdit(centralwidget);
        lineEdit_Ztranslate->setObjectName("lineEdit_Ztranslate");
        lineEdit_Ztranslate->setGeometry(QRect(980, 400, 41, 28));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(960, 400, 20, 20));
        btnTranslate = new QPushButton(centralwidget);
        btnTranslate->setObjectName("btnTranslate");
        btnTranslate->setGeometry(QRect(1030, 400, 41, 29));
        lineEdit_Opacity = new QLineEdit(centralwidget);
        lineEdit_Opacity->setObjectName("lineEdit_Opacity");
        lineEdit_Opacity->setGeometry(QRect(820, 510, 201, 28));
        btnScale = new QPushButton(centralwidget);
        btnScale->setObjectName("btnScale");
        btnScale->setGeometry(QRect(1030, 280, 41, 29));
        btnRotate = new QPushButton(centralwidget);
        btnRotate->setObjectName("btnRotate");
        btnRotate->setGeometry(QRect(1030, 340, 41, 29));
        btnOpacity = new QPushButton(centralwidget);
        btnOpacity->setObjectName("btnOpacity");
        btnOpacity->setGeometry(QRect(1030, 510, 41, 29));
        btnRedo = new QPushButton(centralwidget);
        btnRedo->setObjectName("btnRedo");
        btnRedo->setGeometry(QRect(950, 170, 121, 29));
        btnDelete = new QPushButton(centralwidget);
        btnDelete->setObjectName("btnDelete");
        btnDelete->setGeometry(QRect(820, 210, 251, 29));
        btnFlip = new QPushButton(centralwidget);
        btnFlip->setObjectName("btnFlip");
        btnFlip->setGeometry(QRect(820, 450, 251, 29));
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(820, 640, 121, 29));
        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName("btnLoad");
        btnLoad->setGeometry(QRect(950, 640, 121, 29));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(820, 380, 101, 20));
        lineEdit_Zrotate = new QLineEdit(centralwidget);
        lineEdit_Zrotate->setObjectName("lineEdit_Zrotate");
        lineEdit_Zrotate->setGeometry(QRect(980, 340, 41, 28));
        lineEdit_Yrotate = new QLineEdit(centralwidget);
        lineEdit_Yrotate->setObjectName("lineEdit_Yrotate");
        lineEdit_Yrotate->setGeometry(QRect(910, 340, 41, 28));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(960, 340, 20, 20));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(820, 340, 20, 20));
        lineEdit_Xrotate = new QLineEdit(centralwidget);
        lineEdit_Xrotate->setObjectName("lineEdit_Xrotate");
        lineEdit_Xrotate->setGeometry(QRect(840, 340, 41, 28));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(890, 340, 20, 20));
        labelSavedLoadedMessage = new QLabel(centralwidget);
        labelSavedLoadedMessage->setObjectName("labelSavedLoadedMessage");
        labelSavedLoadedMessage->setGeometry(QRect(820, 670, 101, 20));
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
        label_8->setText(QCoreApplication::translate("MainWindow", "Opacity", nullptr));
        btnUndo->setText(QCoreApplication::translate("MainWindow", "Undo Color", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        btnTranslate->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        btnScale->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        btnRotate->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        btnOpacity->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        btnRedo->setText(QCoreApplication::translate("MainWindow", "Redo Color", nullptr));
        btnDelete->setText(QCoreApplication::translate("MainWindow", "Delete Shape", nullptr));
        btnFlip->setText(QCoreApplication::translate("MainWindow", "Flip Shape", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        labelSavedLoadedMessage->setText(QString());
        menu3D_Painter_Test->setTitle(QCoreApplication::translate("MainWindow", "3D Painter Test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
