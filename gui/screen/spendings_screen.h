#ifndef SPENDINGS_SCREEN_H
#define SPENDINGS_SCREEN_H

#include "base_content_screen.h"
#include "gui/widget/qcustomplot.h"
#include "gui/widget/spendings_performance_widget.h"
#include "gui/widget/cost_prediction_widget.h"

class SpendingsScreen : public BaseContentScreen
{
    Q_OBJECT

    PlaceholderWidget* m_title_widget{nullptr};
    QCustomPlot* m_power_now_widget;
    SpendingsPerformanceWidget* m_performance_widget;
    CostPredictionWidget* m_cost_prediction_widget;

    QSize m_title_widget_size{400, 60};
    QSize m_power_now_widget_size{495, 340};
    QSize m_performance_widget_size{227, 168};
    QSize m_cost_prediction_size{227, 168};

    QPoint m_title_widget_pos{27, 10};
    QPoint m_power_now_widget_pos{0, 100};
    QPoint m_performance_widget_pos{500, 100};
    QPoint m_cost_prediction_pos{500, 272};

public:
    explicit SpendingsScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
