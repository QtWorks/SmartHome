#include "spendings_screen.h"

SpendingsScreen::SpendingsScreen(QWidget* parent) : BaseContentScreen(parent)
{
    m_title_widget = new PlaceholderWidget(this, m_title_widget_size, Qt::black, "Spendings Screen", 30);
    m_power_now_widget = new QCustomPlot(this);
    QCustomPlot* customPlot = m_power_now_widget;

    // create empty bar chart objects:
    QCPBars *regenerative = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    QCPBars *unregenerative = new QCPBars(customPlot->xAxis, customPlot->yAxis);
    customPlot->addPlottable(regenerative);
    customPlot->addPlottable(unregenerative);

    // set names and colors:
    QPen pen;
    pen.setWidthF(1.2);
    pen.setColor(QColor(255, 131, 0));
    unregenerative->setName("Unregenerative Energy");
    pen.setColor(QColor(1, 92, 191));
    unregenerative->setPen(pen);
    unregenerative->setBrush(QColor(1, 92, 191, 50));
    regenerative->setName("Regenerative Energy");
    pen.setColor(QColor(150, 222, 0));
    regenerative->setPen(pen);
    regenerative->setBrush(QColor(150, 222, 0, 70));

    // stack bars ontop of each other:
    regenerative->moveAbove(unregenerative);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "January" << "February" << "March" << "April" << "May" << "June" << "July";
    customPlot->xAxis->setAutoTicks(false);
    customPlot->xAxis->setAutoTickLabels(false);
    customPlot->xAxis->setTickVector(ticks);
    customPlot->xAxis->setTickVectorLabels(labels);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTickCount(0);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->setRange(0, 8);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 5);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Power Consumption in\nKilowatts for last seven months");
    customPlot->yAxis->grid()->setSubGridVisible(true);
    QPen gridPen;
    gridPen.setStyle(Qt::SolidLine);
    gridPen.setColor(QColor(0, 0, 0, 25));
    customPlot->yAxis->grid()->setPen(gridPen);
    gridPen.setStyle(Qt::DotLine);
    customPlot->yAxis->grid()->setSubGridPen(gridPen);

    // Add data:
    QVector<double> unregenerativeData, regenerativeData;
    unregenerativeData << 0.40*5.8 << 0.15*11.2 << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.09*5.2 << 0.05*4.2;
    regenerativeData   << 0.09*5.8 << 0.08*10.5 << 0.09*5.5  << 0.14*5.5 << 0.12*5.2 << 0.17*4.2 << 0.15*11.2;
    unregenerative->setData(ticks, unregenerativeData);
    regenerative->setData(ticks, regenerativeData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 200));
    QPen legendPen;
    legendPen.setColor(QColor(130, 130, 130, 200));
    customPlot->legend->setBorderPen(legendPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

    m_performance_widget = new SpendingsPerformanceWidget(this, m_performance_widget_size);
    m_cost_prediction_widget = new CostPredictionWidget(this, m_performance_widget_size);

    setupLayout();
}

void SpendingsScreen::setupLayout()
{
    BaseContentScreen::setupLayout();

    m_title_widget->resize(m_title_widget_size.width() * m_width_scale, m_title_widget_size.height() * m_height_scale);
    m_power_now_widget->resize(m_power_now_widget_size.width() * m_width_scale, m_power_now_widget_size.height() * m_height_scale);
    m_performance_widget->resize(m_performance_widget_size.width() * m_width_scale, m_performance_widget_size.height() * m_height_scale);
    m_cost_prediction_widget->resize(m_cost_prediction_size.width() * m_width_scale, m_cost_prediction_size.height() * m_height_scale);

    m_title_widget->move(m_title_widget_pos.x() * m_width_scale, m_title_widget_pos.y() * m_height_scale);
    m_power_now_widget->move(m_power_now_widget_pos.x() * m_width_scale, m_power_now_widget_pos.y() * m_height_scale);
    m_performance_widget->move(m_performance_widget_pos.x() * m_width_scale, m_performance_widget_pos.y() * m_height_scale);
    m_cost_prediction_widget->move(m_cost_prediction_pos.x() * m_width_scale, m_cost_prediction_pos.y() * m_height_scale);
}
