#include "temperature_floormap_widget.h"
#include <QPainter>
#include <QMouseEvent>

void TemperatureFloormapWidget::ok()
{
    m_temperature.setTemperature(m_index, m_overlay->value());
    m_overlay->hide();
    update();
}

void TemperatureFloormapWidget::cancel()
{
    m_overlay->hide();
}

TemperatureFloormapWidget::TemperatureFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap) : FloormapWidget(parent, base_size, pixmap)
{
    m_overlay = new ThermometerOverlayWidget(this);
    m_overlay->move(125, 110);
    m_overlay->hide();

    connect(m_overlay, SIGNAL(ok()), this, SLOT(ok()));
    connect(m_overlay, SIGNAL(cancel()), this, SLOT(cancel()));
}

void TemperatureFloormapWidget::setGlobalValue(qreal value)
{
    for (int i = 0; i < m_temperature.temperatureSize(); i++)
    {
        m_temperature.setTemperature(i, value);
    }

    update();
}

void TemperatureFloormapWidget::setGlobalVentilatorValue(bool value)
{
    for (int i = 0; i < m_temperature.ventilationStateSize(); i++)
    {
        m_temperature.setVentilationState(i, value);
    }

    update();
}

void TemperatureFloormapWidget::paintEvent(QPaintEvent*)
{
    FloormapWidget::paintEvent(nullptr);

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPixmap icon(":/Smart home/temperature.png");

    for (int i = 0; i < m_icon_map.size(); i++)
    {
        QPoint top_left(m_icon_map[i].x() * m_width_scale, m_icon_map[i].y() * m_height_scale);
        QSize size(m_icon_size.width() * m_width_scale, m_icon_size.height() * m_height_scale);

        QRect icon_rect(top_left, size);
        painter.drawPixmap(icon_rect, icon);

        QFont font = painter.font();
        font.setPixelSize(10 * m_scale);
        painter.setFont(font);

        QPoint label_top_left(top_left.x() - 0.75f * size.width(), top_left.y());
        QRect label_rect(label_top_left, size);

        painter.drawText(label_rect, Qt::AlignCenter, QString::number(m_temperature.temperature(i), 'f', 1) + QString::fromUtf8("°") + "C");
    }

    QPixmap vent_on(":/Smart home/ventilation.png");
    QPixmap vent_off(":/Smart home/no_ventilation.png");

    for (int i = 0; i < m_ventilation_map.size(); i++)
    {
        QPoint top_left(m_ventilation_map[i].x() * m_width_scale, m_ventilation_map[i].y() * m_height_scale);
        QSize size(m_icon_size.width() * m_width_scale, m_icon_size.height() * m_height_scale);

        QRect icon_rect(top_left, size);

        if (m_temperature.ventilationState(i) == true)
        {
            painter.drawPixmap(icon_rect, vent_on);
        }
        else
        {
            painter.drawPixmap(icon_rect, vent_off);
        }
    }
}

void TemperatureFloormapWidget::mousePressEvent(QMouseEvent* event)
{
    if (m_overlay->isVisible() == true)
        return;

    for (int i = 0; i < m_icon_map.size(); i++)
    {
        QPoint top_left(m_icon_map[i].x() * m_width_scale, m_icon_map[i].y() * m_height_scale);
        QSize size(m_icon_size.width() * m_width_scale, m_icon_size.height() * m_height_scale);

        QRect icon_rect(top_left, size);

        if (icon_rect.contains(event->x(), event->y()))
        {
            m_overlay->setValue((m_temperature.temperature(i) - 18) * 30);
            m_overlay->show();
            m_index = i;
            return;
        }
    }

    for (int i = 0; i < m_ventilation_map.size(); i++)
    {
        QPoint top_left(m_ventilation_map[i].x() * m_width_scale, m_ventilation_map[i].y() * m_height_scale);
        QSize size(m_icon_size.width() * m_width_scale, m_icon_size.height() * m_height_scale);

        QRect icon_rect(top_left, size);
        if (icon_rect.contains(event->x(), event->y()))
        {
            m_temperature.setVentilationState(i, !m_temperature.ventilationState(i));
            update();
            break;
        }
    }
}


