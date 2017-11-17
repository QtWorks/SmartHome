#include "temperature_floormap_widget.h"
#include <QPainter>

FloormapWidget::FloormapWidget(QWidget* parent, QSize base_size, QPixmap pixmap) : ScalableWidget(parent, base_size), m_pixmap(pixmap)
{

}

void FloormapWidget::paintEvent(QPaintEvent*)
{    
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPixmap pixmap = m_pixmap.scaled(m_pixmap.width() * m_width_scale, m_pixmap.height() * m_height_scale, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QRect pixmap_rect = QRect(QPoint(rect().center().x() - 0.5f * pixmap.width(), rect().center().y() - 0.4 * pixmap.height()), QSize(pixmap.width(), pixmap.height()));
    painter.drawPixmap(pixmap_rect, pixmap);
}



