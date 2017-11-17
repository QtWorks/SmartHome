#ifndef TEMPERATURE_OPTIONS_WIDGET_H
#define TEMPERATURE_OPTIONS_WIDGET_H

#include "scalable_widget.h"

class TemperatureOptionsWidget : public ScalableWidget
{
    Q_OBJECT

private slots:
    void temperatureClicked();
    void ventilatorOnClicked();
    void ventilatorOffClicked();

public:
    explicit TemperatureOptionsWidget(QWidget* parent, QSize base_size);

signals:
    void temperature();
    void ventilatorOn();
    void ventilatorOff();

protected:
    void paintEvent(QPaintEvent*);
};

#endif
