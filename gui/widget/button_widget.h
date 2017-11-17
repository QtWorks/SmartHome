#ifndef BUTTON_WIDGET_H
#define BUTTON_WIDGET_H

#include "gui/widget/placeholder_widget.h"

class ButtonWidget : public PlaceholderWidget
{
    Q_OBJECT

    QColor m_background_color;
    QString m_title;
    int m_font_pixel_size;
    int m_index{0};
    int m_border_roudness{10};

public:
    explicit ButtonWidget(QWidget* parent, QSize base_size, QColor background_color, const QString& title, int font_pixel_size);



signals:
    void clicked();
    void selected(int index);

protected:
    void paintEvent(QPaintEvent*);
    void mouseReleaseEvent(QMouseEvent*);
};
#endif // BUTTON_H
