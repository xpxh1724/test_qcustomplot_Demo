#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createSpectrumWaterfall();
    initDemo1();
    initDemo2();
//    initDemo3();
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

    timer->start(1);
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

    // 设置graph0为不平滑的折线图
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue, 1));
    ui->customPlot2->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot2->graph(0)->setScatterStyle(QCPScatterStyle::ssNone);
    // 填充会使折线下方有颜色
    ui->customPlot2->graph(0)->setBrush(QBrush(QColor("green")));

    // 设置graph1为带数据点的不平滑折线图
    ui->customPlot2->graph(1)->setPen(QPen(Qt::red, 1, Qt::DotLine));
    ui->customPlot2->graph(1)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot2->graph(1)->setScatterStyle(QCPScatterStyle::ssCustom);


    connect(timer2,&QTimer::timeout,this,[=]{
        if(i >= 10){
            ui->customPlot2->xAxis->setRange(i,10,Qt::AlignRight);//横坐标动起来的关键
        }
        //加数据
        j = qSin(i);
        ui->customPlot2->graph(0)->addData(i,j);
        ui->customPlot2->graph(1)->addData(i+0.7,j+2);

        //重绘
        ui->customPlot2->replot();
        i+=0.1;
    });

    timer2->start(2);
}
//瀑布图
void MainWindow::createSpectrumWaterfall()
{
    ui->customPlot3->plotLayout()->clear();

    // 创建主图和颜色标尺
    QCPAxisRect *axisRect = new QCPAxisRect(ui->customPlot3);
    axisRect->setupFullAxesBox(true);

    QCPColorMap *colorMap = new QCPColorMap(axisRect->axis(QCPAxis::atBottom),
                                            axisRect->axis(QCPAxis::atLeft));

    // 设置数据范围
    int nx = 500;  // 频率点数
    int ny = 200;  // 时间点数
    colorMap->data()->setSize(nx, ny);
    colorMap->data()->setRange(QCPRange(0, 1000), QCPRange(0, ny));  // 0-1000Hz

    // 生成频谱数据（示例）
    for (int xIndex = 0; xIndex < nx; ++xIndex) {
        for (int yIndex = 0; yIndex < ny; ++yIndex) {
            double frequency = 1000.0 * xIndex / nx;
            double time = yIndex;

            // 模拟信号：基波 + 谐波
            double value = qSin(frequency * 0.01 * time) *
                    qExp(-frequency/500.0) *
                    (1 + 0.5 * qSin(time * 0.1));

            colorMap->data()->setCell(xIndex, yIndex, value);
        }
    }

    // 设置颜色
    QCPColorGradient gradient;
    gradient.setColorInterpolation(QCPColorGradient::ciRGB);
    gradient.setColorStopAt(0, Qt::black);
    gradient.setColorStopAt(0.33, Qt::blue);
    gradient.setColorStopAt(0.66, Qt::green);
    gradient.setColorStopAt(1, Qt::red);
    colorMap->setGradient(gradient);

    // 添加颜色标尺
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot3);
    ui->customPlot3->plotLayout()->addElement(0, 1, colorScale);
    colorScale->setType(QCPAxis::atRight);
    colorMap->setColorScale(colorScale);
    colorScale->axis()->setLabel("幅度");

    // 设置标签
    axisRect->axis(QCPAxis::atBottom)->setLabel("频率 (Hz)");
    axisRect->axis(QCPAxis::atLeft)->setLabel("时间");

    ui->customPlot3->plotLayout()->addElement(0, 0, axisRect);
    ui->customPlot3->rescaleAxes();
    ui->customPlot3->replot();
}
