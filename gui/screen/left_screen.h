#ifndef LEFT_SCREEN_H
#define LEFT_SCREEN_H

#include "base_content_screen.h"
#include "gui/widget/floormap_widget.h"
#include "gui/widget/alarm_floormap_widget.h"
#include "gui/widget/temperature_floormap_widget.h"
#include "gui/widget/lighting_floormap_widget.h"
#include "gui/widget/home_floormap_widget.h"
#include "gui/widget/gardening_widget.h"

class LeftScreen : public BaseContentScreen
{
    Q_OBJECT

protected:
    QWidget* m_left_widget{nullptr};
    PlaceholderWidget* m_title_widget{nullptr};

    QSize m_left_widget_size{491, 476};
    QSize m_title_widget_size{400, 60};

    QPoint m_left_widget_pos{0, 2};
    QPoint m_title_widget_pos{30, 10};

    explicit LeftScreen(QWidget* parent);

    void setupLayout();
};

#endif
