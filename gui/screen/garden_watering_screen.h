#ifndef GARDEN_WATERING_SCREEN_H
#define GARDEN_WATERING_SCREEN_H

#include "left_right_screen.h"
#include "gui/widget/gardening_options_widget.h"

class GardenWateringScreen : public LeftRightScreen
{
    Q_OBJECT

    GardeningOptionsWidget* m_gard_opt_widget{nullptr};

private slots:
    void sprinklerOn();
    void sprinklerOff();

public:
    explicit GardenWateringScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
