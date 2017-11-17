
#include "navigation_widget.h"
#include <QPainter>


NavigationWidget::NavigationWidget(QWidget* parent, QSize base_size, QPixmap pixmap, bool is_selected) : ScalableWidget(parent, base_size), m_pixmap(pixmap), m_is_selected(is_selected)
{

}

void NavigationWidget::setIndex(int index)
{
    m_index = index;
}

void NavigationWidget::setSelected(bool is_selected, QColor color)
{
    m_is_selected=is_selected;
    m_color=color;
    update();
}

void NavigationWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if(m_is_selected)
    {
        QPainterPath path;
        path.addRoundedRect(rect(), m_scale, m_scale);
        painter.fillPath(path, m_color);
    }

    QPixmap pixmap = m_pixmap.scaled(m_pixmap.width() * m_scale, m_pixmap.height() * m_scale, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QRect pixmap_rect = QRect(QPoint(rect().center().x() - 0.5f * pixmap.width(), rect().center().y() - 0.5 * pixmap.height()), QSize(pixmap.width(), pixmap.height()));
    painter.drawPixmap(pixmap_rect, pixmap);
}

void NavigationWidget::mouseReleaseEvent(QMouseEvent*)
{
    emit selected(m_index);
    emit clicked();
}
