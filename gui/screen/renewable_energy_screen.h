#ifndef RENEWABLE_ENERGY_SCREEN_H
#define RENEWABLE_ENERGY_SCREEN_H

#include "left_right_screen.h"
#include "gui/widget/renewable_energy_options_widget.h"
#include "qtsvgdialgauge.h"

class RenewableEnergyScreen : public LeftRightScreen
{
    Q_OBJECT
    RenewableEnergyOptionsWidget* m_ren_opt_widget{nullptr};

public:
    explicit RenewableEnergyScreen(QWidget* parent);

protected:
    void setupLayout();
};



#endif






