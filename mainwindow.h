#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "CustomBars.h"

namespace Ui {
class MainWindow;
}





class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initDemo1();
    void initDemo2();
    void initDemo3();
    void createSpectrumWaterfall();
public slots:
    void on_scatterDiagramBtn_clicked();
private slots:
    void on_lineChartBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer=nullptr,*timer2=nullptr;
    double i=0,j=0;
};

#endif // MAINWINDOW_H
