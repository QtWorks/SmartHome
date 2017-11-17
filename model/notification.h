#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include "singleton.h"
#include <QDebug>

// level
// 0 - Information
// 1 - Warning
// 2 - Critical
// 3 - Alarm
// 4 - Dismiss
struct NotificationPrimitive
{
    int level;
    QString time;
    QString location;
    QString description;
    QString text;
};

class Notification : public QObject
{
    Q_OBJECT

    QTimer* m_update_timer;

    friend class Singleton<Notification>;

    int m_count{5};
    int m_index{0};

    QVector<NotificationPrimitive> m_notification_vector;

    Notification() : QObject(nullptr)
    {
        m_update_timer = new QTimer(this);
        m_update_timer->start(60000);

        connect(m_update_timer, SIGNAL(timeout()), this, SLOT(toggleUpdate()));

        int init_size = 4;
        for (int i = 0; i < init_size; i++)
        {
            m_notification_vector.push_front(getNotificationPrimitive(i, init_size - i - 1));
        }

        notificationUpdate();
    }

    NotificationPrimitive getNotificationPrimitive(int index, int minute_offset = 0) const;
    int getLevel(int index) const;
    QString getTime(int minute_offset = 0) const;
    QString getLocation(int index) const;
    QString getDescription(int index) const;
    QString getText(int index) const;

private slots:
    void toggleUpdate();

public:
    void remove(int index);
    void removeAll();
    int count();
    NotificationPrimitive get(int index);

signals:
    void notificationUpdate();
};

#endif
