#ifndef PLACEHOLDER_WIDGET_H
#define PLACEHOLDER_WIDGET_H

#include "scalable_widget.h"

class PlaceholderWidget : public ScalableWidget
{
    Q_OBJECT

    QColor m_background_color;
    QString m_title;
    int m_font_pixel_size;
    int m_index{0};
    int m_border_roudness{10};

public:
    explicit PlaceholderWidget(QWidget* parent, QSize base_size, QColor background_color, const QString& title, int font_pixel_size);

    void setIndex(int index);
    void setTitle(const QString& title);
    void setBorderRoundess(int border_roundess);
    void setBackgroundColor(QColor background_color);

signals:
    void clicked();
    void selected(int index);

protected:
    void paintEvent(QPaintEvent*);
    void mouseReleaseEvent(QMouseEvent*);
};

#endif
