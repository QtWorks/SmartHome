#include "renewable_energy_options_widget.h"
#include <QPainter>
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <qpushbutton.h>


RenewableEnergyOptionsWidget::RenewableEnergyOptionsWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{

}

void RenewableEnergyOptionsWidget::setBorderRoundess(int border_roundess)
{
    m_border_roudness = border_roundess;
}

void RenewableEnergyOptionsWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPainterPath path;

    QFont font;
    font.setPixelSize(15 * m_scale);
    painter.setFont(font);

    painter.setPen(Qt::white);

    QRect solar_electricity_rect(0.05f * width(), 0.05f * height(), 0.9f * width(), 0.25f * height());
    QRect solar_water_heating_rect(0.05f * width(), 0.375f * height(), 0.9f * width(), 0.25f * height());
    QRect wind_power_rect(0.05f * width(), 0.7f * height(), 0.9f * width(), 0.25f * height());

    QRect solar_electricity_icon_rect(0.01f * solar_electricity_rect.width() + solar_electricity_rect.topLeft().x(), 0.1f * solar_electricity_rect.height() + solar_electricity_rect.topLeft().y(), 0.3f * solar_electricity_rect.width(), 0.15f * solar_electricity_rect.height());
    QRect solar_water_heating_icon_rect(0.0f * solar_water_heating_rect.width() + solar_water_heating_rect.topLeft().x(), 0.1f * solar_water_heating_rect.height() + solar_water_heating_rect.topLeft().y(), 0.3f * solar_water_heating_rect.width(), 0.15f * solar_water_heating_rect.height());
    QRect wind_power_icon_rect(0.01f * wind_power_rect.width() + wind_power_rect.topLeft().x(), 0.1f * wind_power_rect.height() + wind_power_rect.topLeft().y(), 0.3f * wind_power_rect.width(), 0.15f * wind_power_rect.height());

    QRect solar_electricity_text_rect(0.1f * solar_electricity_rect.width() + solar_electricity_rect.topLeft().x(), 0.05f * solar_electricity_rect.height() + solar_electricity_rect.topLeft().y(), 0.9f * solar_electricity_rect.width(), 0.4f * solar_electricity_rect.height());
    QRect solar_water_heating_text_rect(0.1f * solar_water_heating_rect.width() + solar_water_heating_rect.topLeft().x(), 0.05f * solar_water_heating_rect.height() + solar_water_heating_rect.topLeft().y(), 0.9f * solar_water_heating_rect.width(), 0.4f * solar_water_heating_rect.height());
    QRect wind_power_text_rect(0.1f * wind_power_rect.width() + wind_power_rect.topLeft().x(), 0.05f * wind_power_rect.height() + wind_power_rect.topLeft().y(), 0.9f * wind_power_rect.width(), 0.4f * wind_power_rect.height());

    QRect solar_electricity_value_rect(0.05f * solar_electricity_rect.width() + solar_electricity_rect.topLeft().x(), 0.45f * solar_electricity_rect.height() + solar_electricity_rect.topLeft().y(), 0.9f * solar_electricity_rect.width(), 0.45f * solar_electricity_rect.height());
    QRect solar_water_heating_value_rect(0.05f * solar_water_heating_rect.width() + solar_water_heating_rect.topLeft().x(), 0.45f * solar_water_heating_rect.height() + solar_water_heating_rect.topLeft().y(), 0.9f * solar_water_heating_rect.width(), 0.45f * solar_water_heating_rect.height());
    QRect wind_power_value_rect(0.05f * wind_power_rect.width() + wind_power_rect.topLeft().x(), 0.45f * wind_power_rect.height() + wind_power_rect.topLeft().y(), 0.9f * wind_power_rect.width(), 0.45f * wind_power_rect.height());

    path.addRoundedRect(solar_electricity_rect, 10.0, 10.0);
    painter.fillPath(path, Qt::white);
    painter.drawPath(path);

    path.addRoundedRect(solar_water_heating_rect, 10.0, 10.0);
    painter.fillPath(path, Qt::white);
    painter.drawPath(path);

    path.addRoundedRect(wind_power_rect, 10.0, 10.0);
    painter.fillPath(path, Qt::white);
    painter.drawPath(path);

    painter.setPen(Qt::black);

    painter.drawText(solar_electricity_text_rect, Qt::AlignCenter, "Solar \n Electricity Production");
    painter.drawText(solar_water_heating_text_rect, Qt::AlignCenter, "Solar Water\n Heating Production");
    painter.drawText(wind_power_text_rect, Qt::AlignCenter, "Wind \n Power Production");

    font.setPixelSize(20 * m_scale);
    font.setBold(true);
    painter.setFont(font);
    painter.drawText(solar_electricity_value_rect, Qt::AlignCenter, "20 kW/h");
    painter.drawText(solar_water_heating_value_rect, Qt::AlignCenter, "10 kW/h");
    painter.drawText(wind_power_value_rect, Qt::AlignCenter, "8 kW/h");

    QPixmap pixmap(":/Smart home/solar.png");
    QPixmap scaled_pixmap = pixmap.scaled(pixmap.width() * m_width_scale, pixmap.height() * m_height_scale , Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(solar_electricity_icon_rect.center().x() - 0.5f * scaled_pixmap.width(), solar_electricity_icon_rect.center().y() - 0.5f * scaled_pixmap.height(), scaled_pixmap);

    pixmap = QPixmap(":/Smart home/solar_water.jpg");
    scaled_pixmap = pixmap.scaled(pixmap.width() * m_width_scale, pixmap.height() * m_height_scale , Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(solar_water_heating_icon_rect.center().x() - 0.5f * scaled_pixmap.width(), solar_water_heating_icon_rect.center().y() - 0.5f * scaled_pixmap.height(), scaled_pixmap);

    pixmap = QPixmap(":/Smart home/wind.jpg");
    scaled_pixmap = pixmap.scaled(pixmap.width() * m_width_scale, pixmap.height() * m_height_scale , Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(wind_power_icon_rect.center().x() - 0.5f * scaled_pixmap.width(), wind_power_icon_rect.center().y() - 0.5f * scaled_pixmap.height(), scaled_pixmap);



}
