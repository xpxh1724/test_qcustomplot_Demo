#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    createSpectrumWaterfall();
    initDemo1();
    initDemo2();
    //    initDemo3();
    initWaterfall();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDemo1()
{
    /*************************************初始化坐标轴配置***********************************/
    // 为坐标轴添加标签
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis2->setVisible(true);//设置顶部轴线可见
    ui->customPlot->yAxis2->setVisible(true);//设置右部轴线可见
    //当修改左和底坐标轴时,使之与右和上坐标轴也跟着变化()
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);//设置拖动、缩放、选择
}

void MainWindow::initDemo2()
{
    ui->customPlot2->xAxis->setLabel("x");
    ui->customPlot2->yAxis->setLabel("y");
    ui->customPlot2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);//设置拖动、缩放、选择
}

void MainWindow::initDemo3()
{
    ui->customPlot3->legend->setVisible(true);

    //创建条形图对象:
    CustomBars *newFossil = new CustomBars(ui->customPlot3->xAxis, ui->customPlot3->yAxis);
    newFossil->setAntialiased(false);
    //设置名称和颜色:
    newFossil->setName("网络节点等级");
    newFossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    newFossil->setBrush(QColor(111, 9, 176));

    //准备标签:
    QVector<double> newTicks;
    QVector<QString> newLabels;
    for(int i=1;i<=64;i++){
        newTicks.append(i);
        newLabels.append(QString("ID:%1").arg(i));
    }
    QSharedPointer<QCPAxisTickerText> newTextTicker(new QCPAxisTickerText);
    newTextTicker->addTicks(newTicks, newLabels);


    //加入数据:
    QVector<double> newFossilData;
    for (int i = 0; i < 64; ++i) {
        newFossilData.append(5 );
    }
    newFossil->setData(newTicks, newFossilData);

    //    //创建条形图对象:
    //    CustomBars *newNuclear = new CustomBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    //    newNuclear->setAntialiased(false);

    //    //设置名称和颜色:
    //    newNuclear->setName("信号状态");
    //    newNuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    //    newNuclear->setBrush(QColor(250, 170, 20));

    //创建底部轴矩形的条形图:
    QCPAxisRect *volumeAxisRect = new QCPAxisRect(ui->customPlot3);
    ui->customPlot3->plotLayout()->addElement(1, 0, volumeAxisRect);
    volumeAxisRect->setMaximumSize(QSize(QWIDGETSIZE_MAX, 100));
    volumeAxisRect->axis(QCPAxis::atBottom)->setLayer("axes");
    volumeAxisRect->axis(QCPAxis::atBottom)->grid()->setLayer("grid");
    //使底部和主轴更近:
    ui->customPlot3->plotLayout()->setRowSpacing(0);
    volumeAxisRect->setAutoMargins(QCP::msLeft|QCP::msRight|QCP::msBottom);
    volumeAxisRect->setMargins(QMargins(0, 0, 0, 0));
    //创建两个条形图,正(绿),负(红):
    CustomBars *newRegen = new CustomBars(volumeAxisRect->axis(QCPAxis::atBottom), volumeAxisRect->axis(QCPAxis::atLeft));
    newRegen->setAntialiased(false);
    //设置名称和颜色:
    newRegen->setName("信号能量");
    newRegen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    newRegen->setBrush(QColor(0, 168, 140));
    ui->customPlot3->setAutoAddPlottableToLegend(false);

    //加入数据:
    QVector<double> newRegenData;
    for (int i = 0; i < 64; ++i) {
        newRegenData.append(10);
    }
    newRegen->setData(newTicks, newRegenData);

    //连接主轴和下轴x范围:
    connect(ui->customPlot3->xAxis, SIGNAL(rangeChanged(QCPRange)), volumeAxisRect->axis(QCPAxis::atBottom), SLOT(setRange(QCPRange)));
    connect(volumeAxisRect->axis(QCPAxis::atBottom), SIGNAL(rangeChanged(QCPRange)), ui->customPlot3->xAxis, SLOT(setRange(QCPRange)));
    //配置主轴和下轴矩形的轴:

    volumeAxisRect->axis(QCPAxis::atBottom)->setTicker(newTextTicker);
    volumeAxisRect->axis(QCPAxis::atBottom)->setTickLabelRotation(15);
    ui->customPlot3->xAxis->setBasePen(Qt::NoPen);
    ui->customPlot3->xAxis->setTickLabels(false);
    ui->customPlot3->xAxis->setTicks(false); // only want vertical grid in main axis rect, so hide xAxis backbone, ticks, and labels
    ui->customPlot3->xAxis->setTicker(newTextTicker);
    ui->customPlot3->rescaleAxes();
    ui->customPlot3->xAxis->scaleRange(1.025, ui->customPlot3->xAxis->range().center());
    ui->customPlot3->yAxis->scaleRange(1.1, ui->customPlot3->yAxis->range().center());

    //使轴矩形左侧对齐:
    QCPMarginGroup *newGroup = new QCPMarginGroup(ui->customPlot3);
    ui->customPlot3->axisRect()->setMarginGroup(QCP::msLeft|QCP::msRight, newGroup);
    volumeAxisRect->setMarginGroup(QCP::msLeft|QCP::msRight, newGroup);
    ui->customPlot3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);//设置拖动、缩放、选择
}


/*************************************散点槽函数*****************************************/
void MainWindow::on_scatterDiagramBtn_clicked()
{
    if(timer && timer->isActive()){//判断上一次定时器是否存在
        //释放定时器对象
        delete timer;
    }
    timer = new QTimer;

    //设置xy轴范围
    ui->customPlot->xAxis->setRange(-1.5,1.5);
    ui->customPlot->yAxis->setRange(-1.5,1.5);

    //动态显示
    connect(timer,&QTimer::timeout,this,[=]{
        //清除之前绘制的图像
        ui->customPlot->clearGraphs();
        //创建图像(默认曲线)
        ui->customPlot->addGraph();
        //图像设置
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc));//设置散点形状
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);//去除点之间的连线
        //添加数据
        double a,b,r;
        QVector<double> x,y;
        for(int i = 0;i<4048;i++){
            do{
                a = QRandomGenerator::global()->generateDouble() * 2 - 1;
                b = QRandomGenerator::global()->generateDouble() * 2 - 1;
                r = sqrt(pow(a,2) + pow(b,2));
            }while(r > 1);
            x.append(a);
            y.append(b);
        }
        ui->customPlot->graph(0)->addData(x,y);
        //重绘
        ui->customPlot->replot();
    });

    timer->start(5);
}


void MainWindow::on_lineChartBtn_clicked()
{
    i = 0,j = 0;//写成static double i,j后会造成每次进入该槽函数，起始位置是上一次的点位
    if(timer2&& timer2->isActive()){
        //释放定时器对象
        delete timer2;
    }
    timer2 = new QTimer; // 将指针重新设置新对象
    //设置xy轴范围
    ui->customPlot2->xAxis->setRange(0,10);
    ui->customPlot2->yAxis->setRange(-2,2);
    //清除上一次图像
    ui->customPlot2->clearGraphs();
    //创建图像
    ui->customPlot2->addGraph();
    ui->customPlot2->addGraph();
    ui->customPlot2->addGraph();

    // 设置graph0为不平滑的折线图
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue, 1));
    ui->customPlot2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot2->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // 填充会使折线下方有颜色
    //    ui->customPlot2->graph(0)->setBrush(QBrush(QColor("green")));

    // 设置graph1为带数据点的不平滑折线图
    ui->customPlot2->graph(1)->setPen(QPen(Qt::red, 1));
    ui->customPlot2->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot2->graph(1)->setScatterStyle(QCPScatterStyle::ssNone);

    ui->customPlot2->graph(2)->setPen(QPen(Qt::green, 1));
    ui->customPlot2->graph(2)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot2->graph(2)->setScatterStyle(QCPScatterStyle::ssNone);

    connect(timer2,&QTimer::timeout,this,[=]{
        if(i >= 10){
            ui->customPlot2->xAxis->setRange(i,10,Qt::AlignRight);//横坐标动起来的关键
        }
        //加数据
        j = qSin(i);
        ui->customPlot2->graph(0)->addData(i,j);
        ui->customPlot2->graph(1)->addData(i+0.4,j+1);
        ui->customPlot2->graph(2)->addData(i+0.7,j+2);

        //重绘
        ui->customPlot2->replot();
        i+=0.1;
    });

    timer2->start(2);
}
// 创建频谱瀑布图
void MainWindow::createSpectrumWaterfall()
{
    // 1. 清除customPlot3上原有的所有绘图布局
    ui->customPlot3->plotLayout()->clear();

    // 2. 创建坐标轴矩形区域，作为主绘图区
    QCPAxisRect *axisRect = new QCPAxisRect(ui->customPlot3);
    axisRect->setupFullAxesBox(true);  // 设置完整的坐标轴边框（四个边都有轴）

    // 3. 创建颜色映射图（ColorMap），这是瀑布图的核心
    QCPColorMap *colorMap = new QCPColorMap(axisRect->axis(QCPAxis::atBottom),
                                            axisRect->axis(QCPAxis::atLeft));

    // 4. 设置数据范围
    int nx = 500;  // x轴方向：频率点数（分辨率）
    int ny = 200;  // y轴方向：时间点数（时间深度）
    colorMap->data()->setSize(nx, ny);  // 设置数据矩阵大小
    // 设置数据范围：x轴(频率): 0-1000Hz，y轴(时间): 0-200（时间单位）
    colorMap->data()->setRange(QCPRange(0, 1000), QCPRange(0, ny));

    // 5. 生成频谱数据（示例数据）
    for (int xIndex = 0; xIndex < nx; ++xIndex) {
        for (int yIndex = 0; yIndex < ny; ++yIndex) {
            // 计算当前点的频率值（0-1000Hz范围）
            double frequency = 1000.0 * xIndex / nx;
            // 时间值
            double time = yIndex;

            // 模拟一个频谱信号，包含：
            // - 正弦波成分（随时间变化的信号）
            // - 指数衰减（模拟高频衰减）
            // - 随时间变化的幅度调制
            double value = qSin(frequency * 0.01 * time) *
                    qExp(-frequency/500.0) *
                    (1 + 0.5 * qSin(time * 0.1));

            // 将计算出的值设置到颜色图的数据矩阵中
            colorMap->data()->setCell(xIndex, yIndex, value);
        }
    }

    // 6. 设置颜色梯度
    QCPColorGradient gradient;
    gradient.setColorInterpolation(QCPColorGradient::ciRGB);  // 使用RGB颜色插值
    // 设置颜色关键点：
    gradient.setColorStopAt(0, Qt::black);    // 最小值：黑色
    gradient.setColorStopAt(0.33, Qt::blue);  // 33%位置：蓝色
    gradient.setColorStopAt(0.66, Qt::green); // 66%位置：绿色
    gradient.setColorStopAt(1, Qt::red);      // 最大值：红色
    colorMap->setGradient(gradient);  // 应用颜色梯度到颜色图

    // 7. 添加颜色标尺（右侧的色条）
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot3);
    ui->customPlot3->plotLayout()->addElement(0, 1, colorScale);  // 添加到布局（0行1列）
    colorScale->setType(QCPAxis::atRight);  // 设置为右侧垂直标尺
    colorMap->setColorScale(colorScale);    // 关联颜色图和颜色标尺
    colorScale->axis()->setLabel("幅度");   // 设置标尺标签

    // 8. 设置主坐标轴标签
    axisRect->axis(QCPAxis::atBottom)->setLabel("频率 (Hz)");  // x轴标签
    axisRect->axis(QCPAxis::atLeft)->setLabel("时间");        // y轴标签

    // 9. 将坐标轴矩形添加到布局（0行0列）
    ui->customPlot3->plotLayout()->addElement(0, 0, axisRect);

    // 10. 自动调整坐标轴范围以适应数据
    ui->customPlot3->rescaleAxes();

    // 11. 重新绘制整个图形
    ui->customPlot3->replot();
}
// 初始化瀑布图函数
void MainWindow::initWaterfall()
{
    waterfallTimer = new QTimer(this);
    waterfallTimeIndex = 0;
    waterfallTime = 0.0;
    currentSpectrum.resize(WATERFALL_NX);

    // 连接定时器信号
    connect(waterfallTimer, &QTimer::timeout, this, &MainWindow::updateWaterfall);
    createDynamicSpectrumWaterfall();//创建瀑布图
    //开始瀑布
    connect(ui->startWaterfall,&QPushButton::clicked,this,&MainWindow::startWaterfall);
    //停止瀑布
    connect(ui->stopWaterfall,&QPushButton::clicked,this,&MainWindow::stopWaterfall);
    //清除瀑布
    connect(ui->clearWaterfall,&QPushButton::clicked,this,&MainWindow::clearWaterfall);
    //设置速率
    connect(ui->setWaterfallUpdateRate,&QPushButton::clicked,this,[=]{
        int Rate = ui->rate->value();
        this->setWaterfallUpdateRate(Rate);
    });
    ui->customPlot3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);//设置拖动、缩放、选择


}
// 创建动态频谱瀑布图
void MainWindow::createDynamicSpectrumWaterfall()
{
    ui->customPlot3->plotLayout()->clear();

    // 创建主图和颜色标尺
    QCPAxisRect *axisRect = new QCPAxisRect(ui->customPlot3);
    axisRect->setupFullAxesBox(true);

    waterfallColorMap = new QCPColorMap(axisRect->axis(QCPAxis::atBottom),
                                        axisRect->axis(QCPAxis::atLeft));

    // 设置数据范围
    waterfallColorMap->data()->setSize(WATERFALL_NX, WATERFALL_NY);
    waterfallColorMap->data()->setRange(QCPRange(0, 1000), QCPRange(0, WATERFALL_NY));
    // 初始化数据（全部为零）
    for (int xIndex = 0; xIndex < WATERFALL_NX; ++xIndex) {
        for (int yIndex = 0; yIndex < WATERFALL_NY; ++yIndex) {
            waterfallColorMap->data()->setCell(xIndex, yIndex, 0);
        }
    }

    // 设置颜色梯度（使用更丰富的颜色）
    QCPColorGradient gradient;
    gradient.setColorInterpolation(QCPColorGradient::ciRGB);
    gradient.setColorStopAt(0.0, QColor(0, 0, 0));       // 黑色
    gradient.setColorStopAt(0.2, QColor(0, 0, 100));     // 深蓝
    gradient.setColorStopAt(0.4, QColor(0, 100, 255));   // 浅蓝
    gradient.setColorStopAt(0.6, QColor(0, 255, 0));     // 绿色
    gradient.setColorStopAt(0.8, QColor(255, 255, 0));   // 黄色
    gradient.setColorStopAt(1.0, QColor(255, 0, 0));     // 红色
    waterfallColorMap->setGradient(gradient);

    // 设置颜色映射范围
    waterfallColorMap->setDataRange(QCPRange(-1.0, 2.0));

    // 添加颜色标尺
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot3);
    ui->customPlot3->plotLayout()->addElement(0, 1, colorScale);
    colorScale->setType(QCPAxis::atRight);
    waterfallColorMap->setColorScale(colorScale);
    colorScale->axis()->setLabel("幅度 (dB)");

    // 设置坐标轴标签
    axisRect->axis(QCPAxis::atBottom)->setLabel("频率 (Hz)");
    axisRect->axis(QCPAxis::atLeft)->setLabel("时间 (帧)");

    // 设置标题
    axisRect->axis(QCPAxis::atTop)->setLabel("实时频谱瀑布图");
    axisRect->axis(QCPAxis::atTop)->setVisible(true);

    // 将坐标轴矩形添加到布局
    ui->customPlot3->plotLayout()->addElement(0, 0, axisRect);
    ui->customPlot3->rescaleAxes();
    ui->customPlot3->replot();

    // 启动定时器（每50ms更新一次，约20FPS）
    waterfallTimer->start(waterfallRate);
}
// 更新瀑布图数据（定时器调用的槽函数）
void MainWindow::updateWaterfall()
{
    // 更新时间
    waterfallTime += 0.05;  // 每次更新增加0.05秒
    waterfallTimeIndex = (waterfallTimeIndex + 1) % WATERFALL_NY;

    // 生成新的频谱数据（模拟实时频谱）
    generateSpectrumData();

    // 将数据滚动显示（新数据在最上方）
    // 方法：将整个数据矩阵向下移动一行，然后在顶部插入新数据
    for (int yIndex = WATERFALL_NY - 1; yIndex > 0; --yIndex) {
        for (int xIndex = 0; xIndex < WATERFALL_NX; ++xIndex) {
            double value = waterfallColorMap->data()->cell(xIndex, yIndex - 1);
            waterfallColorMap->data()->setCell(xIndex, yIndex, value);
        }
    }

    // 在顶部插入新的频谱数据
    for (int xIndex = 0; xIndex < WATERFALL_NX; ++xIndex) {
        waterfallColorMap->data()->setCell(xIndex, 0, currentSpectrum[xIndex]);
    }

    // 更新颜色映射图
    waterfallColorMap->data()->setRange(QCPRange(0, 1000), QCPRange(0, WATERFALL_NY));

    // 重新绘制
    ui->customPlot3->replot(QCustomPlot::rpQueuedReplot);
}
// 生成频谱数据（模拟函数）
void MainWindow::generateSpectrumData()
{
    double frequencyStep = 1000.0 / WATERFALL_NX;

    for (int i = 0; i < WATERFALL_NX; ++i) {
        double frequency = i * frequencyStep;

        // 模拟多种信号成分

        // 1. 基波信号（随时间变化）
        double baseSignal = sin(2 * M_PI * 100 * waterfallTime) * 0.5;

        // 2. 谐波信号
        double harmonic1 = 0.3 * sin(2 * M_PI * 200 * waterfallTime);
        double harmonic2 = 0.2 * sin(2 * M_PI * 300 * waterfallTime);

        // 3. 噪声信号（随机成分）
        double noise = (qrand() % 100) / 100.0 * 0.1;

        // 4. 扫频信号（随时间扫描频率）
        double sweepFreq = 50 + 900 * abs(sin(waterfallTime * 0.2));
        double sweepSignal = 0.4 * sin(2 * M_PI * sweepFreq * waterfallTime);

        // 5. 突发信号（偶尔出现的信号）
        double burstSignal = 0;
        if (fmod(waterfallTime, 3.0) < 0.1) {  // 每3秒出现0.1秒
            burstSignal = 0.6 * sin(2 * M_PI * 400 * waterfallTime);
        }

        // 6. 频率响应（模拟带通特性）
        double freqResponse = exp(-pow((frequency - 500), 2) / (2 * pow(200, 2)));

        // 组合所有信号成分
        double totalSignal = baseSignal + harmonic1 + harmonic2 + sweepSignal + burstSignal;

        // 应用频率响应并加入噪声
        double value = totalSignal * freqResponse + noise;

        // 添加幅度调制
        value *= (1 + 0.3 * sin(waterfallTime * 0.5));

        currentSpectrum[i] = value;
    }
}
// 控制函数（可以添加到按钮或菜单）
void MainWindow::startWaterfall()
{
    if (!waterfallTimer->isActive()) {
        waterfallTimer->start(50);
        qDebug() << "瀑布图开始更新";
    }
}

void MainWindow::stopWaterfall()
{
    if (waterfallTimer->isActive()) {
        waterfallTimer->stop();
        qDebug() << "瀑布图停止更新";
    }
}

void MainWindow::clearWaterfall()
{
    waterfallTimeIndex = 0;
    waterfallTime = 0.0;

    // 清空数据
    for (int xIndex = 0; xIndex < WATERFALL_NX; ++xIndex) {
        for (int yIndex = 0; yIndex < WATERFALL_NY; ++yIndex) {
            waterfallColorMap->data()->setCell(xIndex, yIndex, 0);
        }
    }

    ui->customPlot3->replot();
    qDebug() << "瀑布图已清空";
}

// 调整更新速率
void MainWindow::setWaterfallUpdateRate(int ms)
{
    waterfallRate = ms;
    if (waterfallTimer->isActive()) {
        waterfallTimer->stop();
        waterfallTimer->start(waterfallRate);
    }
    qDebug() << "瀑布图更新速率设置为:" << ms << "ms";
}
