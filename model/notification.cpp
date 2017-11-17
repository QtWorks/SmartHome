#include "notification.h"
#include <QTime>

NotificationPrimitive Notification::getNotificationPrimitive(int index, int minute_offset) const
{
    NotificationPrimitive notification;

    notification.level = getLevel(index);
    notification.time = getTime(minute_offset);
    notification.location = getLocation(index);
    notification.description = getDescription(index);
    notification.text = getText(index);

    return notification;
}

int Notification::getLevel(int index) const
{
    switch (index)
    {
        case 0:
            return 0;

        case 1:
            return 0;

        case 2:
            return 1;

        case 3:
            return 1;

        case 4:
            return 3;

        case 5:
            return 3;
    }

    return 0;
}

QString Notification::getTime(int minute_offset) const
{
    QTime time = QTime::currentTime();
    time = time.addSecs(-minute_offset * 60);
    QString hh = QString("%1").arg(time.hour(), 2, 10, QChar('0'));
    QString mm = QString("%1").arg(time.minute(), 2, 10, QChar('0'));

    return hh + ":" + mm;
}

QString Notification::getLocation(int index) const
{
    switch (index)
    {
        case 0:
            return "Washroom";

        case 1:
            return "Kitchen";

        case 2:
            return "House";

        case 3:
            return "Outside";

        case 4:
            return "Living room";

        case 5:
            return "Kitchen";
    }

    return "";
}

QString Notification::getDescription(int index) const
{
    switch (index)
    {
        case 0:
            return "Your wash has finished";

        case 1:
            return "Water heater has finished";

        case 2:
            return "Energy spendings are too high for today";

        case 3:
            return "Outside temperature is high";

        case 4:
            return "Broken Window";

        case 5:
            return "Smoke detected";
    }

    return "";
}

QString Notification::getText(int index) const
{
    switch (index)
    {
        case 0:
            return "Your wash \n has finished";

        case 1:
            return "Water heater \n has finished";

        case 2:
            return "Energy spendings are \n too high for today";

        case 3:
            return "Outside temperature\n is high";

        case 4:
            return "Broken window \n in living-room";

        case 5:
            return "Smoke detected \n in kitchen";
    }

    return "";
}

void Notification::toggleUpdate()
{
    m_notification_vector.push_front(getNotificationPrimitive(m_index));
    m_index = (m_index + 1) % m_count;
    emit notificationUpdate();
}

void Notification::remove(int index)
{
    if ((index < 0) || (index > m_notification_vector.size() - 1))
        return;

    m_notification_vector.remove(index);
    emit notificationUpdate();
}

void Notification::removeAll()
{
    m_notification_vector.resize(0);
    emit notificationUpdate();
}

int Notification::count()
{
    return m_notification_vector.size();
}

NotificationPrimitive Notification::get(int index)
{
    return m_notification_vector[index];
}
