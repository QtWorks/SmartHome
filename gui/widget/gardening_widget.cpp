#include "gardening_widget.h"
#include <QPainter>
#include <QMouseEvent>


GardeningWidget::GardeningWidget(QWidget* parent, QSize base_size, QPixmap pixmap) : ScalableWidget(parent, base_size), m_pixmap(pixmap)
{
}

void GardeningWidget::setGlobalSprinklerValue(bool value)
{
    for (int i = 0; i < m_sprinkler.sprinklerStateSize(); i++)
    {
        m_sprinkler.setSprinklerState(i, value);
    }

    update();
}

void GardeningWidget::paintEvent(QPaintEvent*)
{

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPixmap pixmap = m_pixmap.scaled(m_pixmap.width() * m_width_scale, m_pixmap.height() * m_height_scale, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QRect pixmap_rect = QRect(QPoint(rect().center().x() - 0.5f * pixmap.width(), rect().center().y() - 0.4 * pixmap.height()), QSize(pixmap.width(), pixmap.height()));
    painter.drawPixmap(pixmap_rect, pixmap);

    QPixmap sprink_on(":/Smart home/sprinkler1.png");
    QPixmap sprink_off(":/Smart home/sprinkler2.png");

    for (int i = 0; i < m_sprinkler_map.size(); i++)
    {
        QPoint top_left(m_sprinkler_map[i].x() * m_width_scale, m_sprinkler_map[i].y() * m_height_scale);
        QSize size(m_icon_size.width() * m_width_scale, m_icon_size.height() * m_height_scale);

        QRect icon_rect(top_left, size);

        if (m_sprinkler.sprinklerState(i) == true)
        {
            painter.drawPixmap(icon_rect, sprink_on);
        }
        else
        {
            painter.drawPixmap(icon_rect, sprink_off);
        }
    }
}

void GardeningWidget::mousePressEvent(QMouseEvent* event)
{

    for (int i = 0; i < m_sprinkler_map.size(); i++)
    {
        QPoint top_left(m_sprinkler_map[i].x() * m_width_scale, m_sprinkler_map[i].y() * m_height_scale);
        QSize size(m_icon_size.width() * m_width_scale, m_icon_size.height() * m_height_scale);

        QRect icon_rect(top_left, size);
        if (icon_rect.contains(event->x(), event->y()))
        {
            m_sprinkler.setSprinklerState(i, !m_sprinkler.sprinklerState(i));
            update();
            break;
        }
    }
}



