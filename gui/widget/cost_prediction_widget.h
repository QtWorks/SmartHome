#ifndef COST_PREDICTION_WIDGET_H
#define COST_PREDICTION_WIDGET_H

#include "scalable_widget.h"

class CostPredictionWidget : public ScalableWidget
{
    Q_OBJECT

    int m_border_roudness{10};

public:
    explicit CostPredictionWidget(QWidget* parent, QSize base_size);

    void setBorderRoundess(int border_roundess);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
