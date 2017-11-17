#include "icon_widget.h"
#include <QPainter>

IconWidget::IconWidget(QWidget* parent, QSize base_size, QPixmap pixmap, const QString& room_name, int font_pixel_size, int index) : ScalableWidget(parent, base_size), m_room_name(room_name), m_font_pixel_size(font_pixel_size), m_index(index),m_pixmap(pixmap)
{

}

void IconWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QFont font = painter.font();
    font.setBold(true);
    font.setPixelSize(m_scale * m_font_pixel_size);
    painter.setFont(font);

    QPainterPath path;

    if (m_on)
    {
        path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
        painter.fillPath(path, Qt::blue);
    }

    QPainterPath path2;
    QRect r(0.06 * width(), 0.06 * height(), 0.89 * width(), 0.89 * height());
    path2.addRoundedRect(r, m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path2, m_background_color);

    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);

    QRect title_rect(0, 0.75f * height(), width(), 0.2f * height());
    painter.drawText(title_rect, Qt::AlignCenter, m_room_name);


    QRect icon_rect(0.35f * width(), 0.2f * height(), 0.4f * width(), 0.5f * height());
    QPixmap pixmap=m_pixmap;
    QPixmap scaled_pixmap = pixmap.scaled(pixmap.width() * m_width_scale * 0.7, pixmap.height() * m_height_scale*0.5 , Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawPixmap(icon_rect.center().x() - 0.5f * scaled_pixmap.width(), icon_rect.center().y() - 0.5f * scaled_pixmap.height(), scaled_pixmap);

    //painter.drawText(icon_rect, Qt::AlignCenter, "Icon");


}

void IconWidget::mouseReleaseEvent(QMouseEvent*)
{
    if (m_on)
        return;

    m_on = !m_on;
    update();
    emit clicked(m_index);
}

void IconWidget::setOn(bool on)
{
    m_on = on;

    update();
}

void IconWidget::setActive(bool on)
{
    m_active = on;

    if(m_active)
    {
        m_background_color=Qt::green;
    }
    else{
        m_background_color=Qt::gray;
    }

    update();
}
