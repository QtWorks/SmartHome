#ifndef LIGHTING_OPTIONS_WIDGET_H
#define LIGHTING_OPTIONS_WIDGET_H

#include "scalable_widget.h"

class LightingOptionsWidget : public ScalableWidget
{
    Q_OBJECT

private slots:
    void temperatureClicked();
    void ventilatorOnClicked();
    void ventilatorOffClicked();

public:
    explicit LightingOptionsWidget(QWidget* parent, QSize base_size);

signals:
    void lighting();
    void lightingOn();
    void lightingOff();

protected:
    void paintEvent(QPaintEvent*);
};

#endif
