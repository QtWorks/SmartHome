#ifndef NOTIFICATION_TEXT_WIDGET_H
#define NOTIFICATION_TEXT_WIDGET_H

#include "gui/widget/scalable_widget.h"

class NotificationTextWidget : public ScalableWidget
{
    Q_OBJECT
    QString m_text;
    int m_font_size{12};

public:
    explicit NotificationTextWidget(QWidget* parent, QSize base_size, const QString& text, int font_size = 12);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif
