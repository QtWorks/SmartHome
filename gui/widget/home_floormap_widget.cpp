#include "home_floormap_widget.h"
#include <QPainter>
#include <QMouseEvent>

HomeFloormapWidget::HomeFloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap) : AlarmFloormapWidget(parent, base_size, pixmap)
{

}

void HomeFloormapWidget::paintEvent(QPaintEvent*)
{
    AlarmFloormapWidget::paintEvent(nullptr);
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


        //painter.drawText(label_rect, Qt::AlignCenter, "18" + QString::fromUtf8("°") + "C");
    }
}

