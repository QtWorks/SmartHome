#ifndef HOME_SCREEN_H
#define HOME_SCREEN_H

#include "left_screen.h"
#include "gui/widget/weather_forecast_widget.h"
#include "gui/widget/clock_widget.h"
#include "gui/widget/notification_widget.h"

class HomeScreen : public LeftScreen
{
    WeatherForecastWidget* m_weather_widget{nullptr};
    ClockWidget* m_clock_widget{nullptr};
    NotificationWidget* m_notification_widget{nullptr};

    QSize m_weather_widget_size{228, 100};
    QSize m_clock_widget_size{228, 110};
    QSize m_notification_widget_size{228, 222};

    QPoint m_weather_widget_pos{500, 2};
    QPoint m_clock_widget_pos{500, 105};
    QPoint m_notification_widget_pos{500, 218};

public:
    explicit HomeScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
