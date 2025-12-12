/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QPushButton *scatterDiagramBtn;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot2;
    QPushButton *lineChartBtn;
    QCustomPlot *customPlot3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 573);
        MainWindow->setStyleSheet(QString::fromUtf8("#customPlot,#customPlot2,#customPlot3\n"
"{\n"
"border:2px solid;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(widget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        verticalLayout->addWidget(customPlot);

        scatterDiagramBtn = new QPushButton(widget);
        scatterDiagramBtn->setObjectName(QString::fromUtf8("scatterDiagramBtn"));

        verticalLayout->addWidget(scatterDiagramBtn);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        customPlot2 = new QCustomPlot(widget1);
        customPlot2->setObjectName(QString::fromUtf8("customPlot2"));

        verticalLayout_2->addWidget(customPlot2);

        lineChartBtn = new QPushButton(widget1);
        lineChartBtn->setObjectName(QString::fromUtf8("lineChartBtn"));

        verticalLayout_2->addWidget(lineChartBtn);

        splitter->addWidget(widget1);
        customPlot3 = new QCustomPlot(splitter);
        customPlot3->setObjectName(QString::fromUtf8("customPlot3"));
        customPlot3->setMinimumSize(QSize(200, 0));
        splitter->addWidget(customPlot3);

        verticalLayout_3->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        scatterDiagramBtn->setText(QApplication::translate("MainWindow", "scatterDiagramBtn", nullptr));
        lineChartBtn->setText(QApplication::translate("MainWindow", "lineChartBtn", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
