#ifndef TEMPERATURE_SCREEN_H
#define TEMPERATURE_SCREEN_H

#include "left_right_screen.h"
#include "gui/widget/temperature_options_widget.h"

class TemperatureScreen : public LeftRightScreen
{
    Q_OBJECT

    TemperatureOptionsWidget* m_temp_opt_widget{nullptr};
    ThermometerOverlayWidget* m_thermometer{nullptr};

private slots:
    void temperature();
    void ventilatorOn();
    void ventilatorOff();
    void ok();
    void cancel();

public:
    explicit TemperatureScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
