#ifndef LIGHTING_SCREEN_H
#define LIGHTING_SCREEN_H

#include "left_right_screen.h"
#include "gui/widget/lighting_options_widget.h"
#include "gui/widget/lighting_overlay_widget.h"

class LightingScreen : public LeftRightScreen
{
    Q_OBJECT

    LightingOptionsWidget* m_light_opt_widget{nullptr};
    LightingOverlayWidget* m_lighting{nullptr};

private slots:
    void lighting();
    void lightingOn();
    void lightingOff();
    void ok();
    void cancel();

public:
    explicit LightingScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
