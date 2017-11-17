#ifndef WEATHER_FORECAST_WIDGET_H
#define WEATHER_FORECAST_WIDGET_H

#include "scalable_widget.h"

class WeatherForecastWidget : public ScalableWidget
{
    Q_OBJECT

    int m_border_roudness{10};

public:
    explicit WeatherForecastWidget(QWidget* parent, QSize base_size);

    void setBorderRoundess(int border_roundess);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
