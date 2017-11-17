#ifndef ICON_WIDGET_H
#define ICON_WIDGET_H

#include "scalable_widget.h"
//#include <QPixmap>

class IconWidget : public ScalableWidget
{
    Q_OBJECT

    QColor m_background_color = Qt::gray;
    QString m_room_name{"hrkljus"};
    int m_font_pixel_size;
    int m_border_roudness{10};
    int m_index;
    QPixmap m_pixmap;
    bool m_on = false;
    bool m_active = false;

public:
    explicit IconWidget(QWidget* parent, QSize base_size, QPixmap pixmap, const QString& room_name, int font_pixel_size, int index);
    void setOn(bool on);
    void setActive(bool on);

signals:
    void clicked(int);

protected:
    void paintEvent(QPaintEvent*);
    void mouseReleaseEvent(QMouseEvent*);
};

#endif
