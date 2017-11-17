#ifndef NAVIGATION_WIDGET_H
#define NAVIGATION_WIDGET_H

#include "scalable_widget.h"

class NavigationWidget : public ScalableWidget
{
    Q_OBJECT

    QPixmap m_pixmap;
    QColor m_color;
    bool m_is_selected;
    int m_index{0};

public:
    explicit NavigationWidget(QWidget* parent, QSize base_size, QPixmap pixmap = QPixmap(), bool is_selected = false);

    void setIndex(int index);
    void setSelected(bool is_selected, QColor color = QColor());
    void setBorderRoundess(int border_roundess);

signals:
    void clicked();
    void selected(int index);

protected:
    void paintEvent(QPaintEvent*);
    void mouseReleaseEvent(QMouseEvent*);
};

#endif

