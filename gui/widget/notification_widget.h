#ifndef NOTIFICATION_WIDGET_H
#define NOTIFICATION_WIDGET_H

#include "scalable_widget.h"
#include "notification_info_widget.h"
#include "model/notification.h"

class NotificationWidget : public ScalableWidget
{
    Q_OBJECT

    Notification& m_notification_state = Singleton<Notification>::instance();
    NotificationInfoWidget* m_notificiation_info;
    int m_current{0};
    int m_border_roudness{10};
    int m_display_size{5};

    QVector<QPixmap> m_icon{ QPixmap(":/Smart home/green-icon.png"),
                             QPixmap(":/Smart home/warning.png"),
                             QPixmap(":/Smart home/alarm_note.png"),
                             QPixmap(":/Smart home/alarm_note.png"),
                             QPixmap()
                            };

    void updateNotificationInfo();

private slots:
    void notificationUpdate();

public:
    explicit NotificationWidget(QWidget* parent, QSize base_size);

    void setBorderRoundess(int border_roundess);

protected:
    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
    void mouseReleaseEvent(QMouseEvent* event);
};

#endif
