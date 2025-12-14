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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *customPlot;
    QPushButton *scatterDiagramBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot2;
    QPushButton *lineChartBtn;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QCustomPlot *customPlot3;
    QWidget *btnWaterFallWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startWaterfall;
    QPushButton *stopWaterfall;
    QPushButton *clearWaterfall;
    QWidget *btnWaterFallWidget2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *rate;
    QLabel *label;
    QPushButton *setWaterfallUpdateRate;
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
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        customPlot = new QCustomPlot(layoutWidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));

        verticalLayout->addWidget(customPlot);

        scatterDiagramBtn = new QPushButton(layoutWidget);
        scatterDiagramBtn->setObjectName(QString::fromUtf8("scatterDiagramBtn"));
        scatterDiagramBtn->setMinimumSize(QSize(100, 20));

        verticalLayout->addWidget(scatterDiagramBtn);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        customPlot2 = new QCustomPlot(layoutWidget1);
        customPlot2->setObjectName(QString::fromUtf8("customPlot2"));

        verticalLayout_2->addWidget(customPlot2);

        lineChartBtn = new QPushButton(layoutWidget1);
        lineChartBtn->setObjectName(QString::fromUtf8("lineChartBtn"));
        lineChartBtn->setMinimumSize(QSize(100, 20));

        verticalLayout_2->addWidget(lineChartBtn);

        splitter->addWidget(layoutWidget1);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        customPlot3 = new QCustomPlot(widget);
        customPlot3->setObjectName(QString::fromUtf8("customPlot3"));
        customPlot3->setMinimumSize(QSize(200, 0));

        verticalLayout_3->addWidget(customPlot3);

        btnWaterFallWidget = new QWidget(widget);
        btnWaterFallWidget->setObjectName(QString::fromUtf8("btnWaterFallWidget"));
        btnWaterFallWidget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(btnWaterFallWidget);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startWaterfall = new QPushButton(btnWaterFallWidget);
        startWaterfall->setObjectName(QString::fromUtf8("startWaterfall"));
        startWaterfall->setMinimumSize(QSize(100, 20));

        horizontalLayout->addWidget(startWaterfall);

        stopWaterfall = new QPushButton(btnWaterFallWidget);
        stopWaterfall->setObjectName(QString::fromUtf8("stopWaterfall"));
        stopWaterfall->setMinimumSize(QSize(100, 20));

        horizontalLayout->addWidget(stopWaterfall);

        clearWaterfall = new QPushButton(btnWaterFallWidget);
        clearWaterfall->setObjectName(QString::fromUtf8("clearWaterfall"));
        clearWaterfall->setMinimumSize(QSize(100, 20));

        horizontalLayout->addWidget(clearWaterfall);


        verticalLayout_3->addWidget(btnWaterFallWidget);

        btnWaterFallWidget2 = new QWidget(widget);
        btnWaterFallWidget2->setObjectName(QString::fromUtf8("btnWaterFallWidget2"));
        btnWaterFallWidget2->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_2 = new QHBoxLayout(btnWaterFallWidget2);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        rate = new QSpinBox(btnWaterFallWidget2);
        rate->setObjectName(QString::fromUtf8("rate"));
        rate->setMinimumSize(QSize(100, 20));
        rate->setMaximumSize(QSize(100, 16777215));
        rate->setMinimum(1);
        rate->setMaximum(100);
        rate->setStepType(QAbstractSpinBox::DefaultStepType);

        horizontalLayout_2->addWidget(rate);

        label = new QLabel(btnWaterFallWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(20, 16777215));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        setWaterfallUpdateRate = new QPushButton(btnWaterFallWidget2);
        setWaterfallUpdateRate->setObjectName(QString::fromUtf8("setWaterfallUpdateRate"));
        setWaterfallUpdateRate->setMinimumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(setWaterfallUpdateRate);


        verticalLayout_3->addWidget(btnWaterFallWidget2);

        splitter->addWidget(widget);

        verticalLayout_4->addWidget(splitter);

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
        startWaterfall->setText(QApplication::translate("MainWindow", "startWaterfall", nullptr));
        stopWaterfall->setText(QApplication::translate("MainWindow", "stopWaterfall", nullptr));
        clearWaterfall->setText(QApplication::translate("MainWindow", "clearWaterfall", nullptr));
        label->setText(QApplication::translate("MainWindow", "ms", nullptr));
        setWaterfallUpdateRate->setText(QApplication::translate("MainWindow", "setWaterfallUpdateRate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
