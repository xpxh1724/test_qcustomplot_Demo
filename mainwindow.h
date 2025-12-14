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
    // 初始化瀑布图函数
    void initWaterfall();
    // 创建动态频谱瀑布图
    void createDynamicSpectrumWaterfall();
    // 生成频谱数据（模拟函数）
    void generateSpectrumData();
    // 开始瀑布图
    void startWaterfall();
    // 停止瀑布图
    void stopWaterfall();
    // 清空瀑布图
    void clearWaterfall();
    // 调整更新速率
    void setWaterfallUpdateRate(int ms);
private slots:
    void on_scatterDiagramBtn_clicked();
    void on_lineChartBtn_clicked();
    // 更新瀑布图数据（定时器调用的槽函数）
    void updateWaterfall();
private:
    Ui::MainWindow *ui;
    QTimer *timer=nullptr,*timer2=nullptr;
    double i=0,j=0;

    // 动态频谱瀑布图类成员变量声明
    QTimer *waterfallTimer;         // 定时器用于动态更新
    int waterfallTimeIndex;          // 当前时间索引
    const int WATERFALL_NX = 500;    // 频率点数
    const int WATERFALL_NY = 200;    // 时间点数
    QCPColorMap *waterfallColorMap;  // 颜色映射图指针
    QVector<double> currentSpectrum; // 当前频谱数据
    double waterfallTime;            // 时间计数
    int waterfallRate=50;            //瀑布图更新速率ms
};

#endif // MAINWINDOW_H
