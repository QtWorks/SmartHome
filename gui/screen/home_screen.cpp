#include "home_screen.h"

HomeScreen::HomeScreen(QWidget* parent) : LeftScreen(parent)
{
    m_left_widget = new HomeFloormapWidget(this, m_left_widget_size, QPixmap(":/Smart home/floormap_names.png"));

    m_title_widget->setTitle("Home Screen");

    m_weather_widget = new WeatherForecastWidget(this, m_weather_widget_size);
    m_clock_widget = new ClockWidget(this, m_clock_widget_size);
    m_notification_widget = new NotificationWidget(this, m_notification_widget_size);

    setupLayout();
}

void HomeScreen::setupLayout()
{
    LeftScreen::setupLayout();

    m_weather_widget->resize(m_weather_widget_size.width() * m_width_scale, m_weather_widget_size.height() * m_height_scale);
    m_clock_widget->resize(m_clock_widget_size.width() * m_width_scale, m_clock_widget_size.height() * m_height_scale);
    m_notification_widget->resize(m_notification_widget_size.width() * m_width_scale, m_notification_widget_size.height() * m_height_scale);

    m_weather_widget->move(m_weather_widget_pos.x() * m_width_scale, m_weather_widget_pos.y() * m_height_scale);
    m_clock_widget->move(m_clock_widget_pos.x() * m_width_scale, m_clock_widget_pos.y() * m_height_scale);
    m_notification_widget->move(m_notification_widget_pos.x() * m_width_scale, m_notification_widget_pos.y() * m_height_scale);
}
