#include "lighting_floormap_widget.h"
#include <QPainter>
#include <QMouseEvent>

void LightingFloormapWidget::ok()
{
    m_value_map[m_index] = m_overlay->value();
    m_overlay->hide();

    update();
}

void LightingFloormapWidget::cancel()
{
    m_overlay->hide();
}

LightingFloormapWidget::LightingFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap) : FloormapWidget(parent, base_size, pixmap)
{
    m_overlay = new LightingOverlayWidget(this);
    m_overlay->move(135, 145);
    m_overlay->hide();

    connect(m_overlay, SIGNAL(ok()), this, SLOT(ok()));
    connect(m_overlay, SIGNAL(cancel()), this, SLOT(cancel()));
}

void LightingFloormapWidget::setGlobalValue(int value)
{
    for (int i = 0; i < m_value_map.size(); i++)
    {
        m_value_map[i] = value;
    }

    update();
}

void LightingFloormapWidget::paintEvent(QPaintEvent*)
{
    FloormapWidget::paintEvent(nullptr);

    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPixmap icon(":/Smart home/light.png");

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

        painter.drawText(label_rect, Qt::AlignCenter, QString::number(m_value_map[i]) + "%");
    }
}

void LightingFloormapWidget::mousePressEvent(QMouseEvent* event)
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
            m_overlay->setValue(m_value_map[i]);
            m_overlay->show();
            m_index = i;
            return;
        }
    }
}



