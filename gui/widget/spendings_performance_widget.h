#ifndef SPENDINGS_PERFORMANCE_WIDGET_H
#define SPENDINGS_PERFORMANCE_WIDGET_H

#include "scalable_widget.h"
#include "model/power.h"

class SpendingsPerformanceWidget : public ScalableWidget
{
    Q_OBJECT

    Power& m_power_state = Singleton<Power>::instance();

public:
    explicit SpendingsPerformanceWidget(QWidget* parent, QSize base_size);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
