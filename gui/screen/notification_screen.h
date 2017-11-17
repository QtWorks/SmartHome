#ifndef NOTIFICATION_SCREEN_H
#define NOTIFICATION_SCREEN_H

#include "base_screen.h"
#include "model/notification.h"
#include "gui/widget/placeholder_widget.h"
#include <QTableWidget>
#include "model/alarm.h"

class NotificationScreen : public BaseScreen
{
    Q_OBJECT

    Notification& m_notification_state = Singleton<Notification>::instance();
    QTableWidget* m_pTableWidget;
    Alarm& m_alarm_state = Singleton<Alarm>::instance();
    bool m_previous_state{false};

public slots:
    void notificationClicked();
    void helpClicked();
    void cellClicked(int row, int column);
    void dismissAll();
    void notificationUpdate();

protected:
    PlaceholderWidget* m_help_widget;
    PlaceholderWidget* m_events_widget;
    PlaceholderWidget* m_dismiss_widget;

    QSize m_help_widget_size{228, 35};
    QPoint m_help_widget_pos{570, 443};

    QSize m_events_widget_size{228, 35};
    QPoint m_events_widget_pos{335, 443};

    QSize m_dismiss_widget_size{228, 35};
    QPoint m_dismiss_widget_pos{100, 443};

    int getColumWidth(int c) const;

public:
    explicit NotificationScreen(QWidget* parent);
    virtual void setupLayout();

signals:
    void navigateToScreen(int index);
};

#endif
