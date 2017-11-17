#include "weather_forecast_widget.h"
#include <QPainter>

WeatherForecastWidget::WeatherForecastWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{

}

void WeatherForecastWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void WeatherForecastWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, Qt::darkGray);

    QFont font;
    font.setPixelSize(20 * m_scale);
    painter.setFont(font);

    painter.setPen(Qt::white);

    QRect icon_rect(0.1f * width(), 0.1f * height(), 0.4f * width(), 0.4f * height());
    QRect temperature_rect(0.5f * width(), 0, 0.4f * width(), 0.5f * height());
    QRect city_rect(0.1 * width(), 0.5f * height(), 0.8 * width(), 0.5f * height());

    QPixmap pixmap(":/Smart home/weather_forecast.png");
    QPixmap scaled_pixmap = pixmap.scaled(pixmap.width() * m_width_scale, pixmap.height() * m_height_scale , Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(icon_rect.center().x() - 0.5f * scaled_pixmap.width(), icon_rect.center().y() - 0.5f * scaled_pixmap.height(), scaled_pixmap);

    painter.drawText(temperature_rect, Qt::AlignCenter, "20" + QString::fromUtf8("°") + "C");
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(city_rect, Qt::AlignCenter, "Sarajevo");
}
