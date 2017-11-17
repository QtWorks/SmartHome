#ifndef RENEWABLE_ENERGY_OPTIONS_WIDGET_H
#define RENEWABLE_ENERGY_OPTIONS_WIDGET_H

#include "scalable_widget.h"

class RenewableEnergyOptionsWidget : public ScalableWidget
{
    Q_OBJECT
    int m_border_roudness{10};

public:
    explicit RenewableEnergyOptionsWidget(QWidget* parent, QSize base_size);
    void setBorderRoundess(int border_roundess);

protected:
    void paintEvent(QPaintEvent*);
};

#endif

