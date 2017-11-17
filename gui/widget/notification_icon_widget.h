#ifndef NOTIFICATION_ICON_WIDGET_H
#define NOTIFICATION_ICON_WIDGET_H

#include <QTimer>
#include "gui/widget/scalable_widget.h"

enum NotificationEnum
{
    Information,
    Warning,
    Critical,
    Alarm,
    Dismiss
};

class NotificationIconWidget : public ScalableWidget
{
    Q_OBJECT

    NotificationEnum m_type;
    QTimer* m_blink_timer;
    bool m_toggled{true};

    QPixmap getIcon(NotificationEnum) const;

private slots:
    void toggleBlink();

public:
    explicit NotificationIconWidget(QWidget* parent, QSize base_size, NotificationEnum type);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *);
};

#endif
