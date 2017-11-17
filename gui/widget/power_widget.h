#ifndef POWER_WIDGET_H
#define POWER_WIDGET_H

#include "scalable_widget.h"

class PowerWidget : public ScalableWidget
{
    Q_OBJECT

    int m_power;
    int m_font_pixel_size;
    int m_border_roudness{10};

public:
    explicit PowerWidget(QWidget* parent, QSize base_size, int power, int font_pixel_size);

    void setPower(int power);

protected:
    void paintEvent(QPaintEvent*);
};

#endif
