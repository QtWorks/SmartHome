#include "notification_screen.h"
#include <QPainter>
#include <QTableWidget>
#include <QHeaderView>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include "gui/widget/notification_icon_widget.h"
#include "gui/widget/notification_text_widget.h"
#include <QLabel>
#include "model/alarm.h"

void NotificationScreen::notificationClicked()
{
    emit returnFromNotification();
    setupLayout();
}

void NotificationScreen::helpClicked()
{
    emit goToHelp();
    setupLayout();
}

void NotificationScreen::cellClicked(int row, int column)
{
    // TODO: Size check
    if (column == 4)
    {
        m_notification_state.remove(row);
    }
}

void NotificationScreen::dismissAll()
{
    m_notification_state.removeAll();
}

void NotificationScreen::notificationUpdate()
{
    while (m_pTableWidget->rowCount() > 0)
    {
        m_pTableWidget->removeRow(0);
    }

    int count = m_notification_state.count();
    if (count <= 8)
        m_pTableWidget->setRowCount(8);
    else
        m_pTableWidget->setRowCount(count);

    bool navigateToAlarmScreen = false;
    for (int i = 0; i < count; i++)
    {
        auto notification = m_notification_state.get(i);
        if ((notification.level == 3) & (i == 0))
            navigateToAlarmScreen = true;

        NotificationIconWidget* icon_widget = new NotificationIconWidget(m_pTableWidget, QSize(50, 50), static_cast<NotificationEnum>(notification.level));
        NotificationTextWidget* time_widget = new NotificationTextWidget(m_pTableWidget, QSize(20, 20), notification.time, 8);
        NotificationTextWidget* location_widget = new NotificationTextWidget(m_pTableWidget, QSize(20, 20), notification.location, 8);
        NotificationTextWidget* description_widget = new NotificationTextWidget(m_pTableWidget, QSize(20, 20), notification.description, 8);
        NotificationIconWidget* dismiss_widget = new NotificationIconWidget(m_pTableWidget, QSize(50, 50), NotificationEnum::Dismiss);

        m_pTableWidget->setCellWidget(i, 0, icon_widget);
        m_pTableWidget->setCellWidget(i, 1, time_widget);
        m_pTableWidget->setCellWidget(i, 2, location_widget);
        m_pTableWidget->setCellWidget(i, 3, description_widget);
        m_pTableWidget->setCellWidget(i, 4, dismiss_widget);
    }

    if (m_alarm_state.alarmRaised() == false && navigateToAlarmScreen == true)
    {
        m_alarm_state.setAlarmRaised(true);
        m_alarm_state.setAlarm(1, true);
        emit navigateToScreen(7);
    }
}

int NotificationScreen::getColumWidth(int c) const
{
    switch (c)
    {
        case 0:
            return 60;

        case 1:
            return 80;

        case 2:
            return 160;

        case 3:
            return 420;

        case 4:
            return 60;
    }

    return 0;
}

NotificationScreen::NotificationScreen(QWidget* parent) : BaseScreen(parent)
{
    m_help_widget = new PlaceholderWidget(this, m_help_widget_size, Qt::darkBlue, "Help", 15);
    m_help_widget->setBorderRoundess(10);
    m_events_widget = new PlaceholderWidget(this, m_help_widget_size, Qt::darkBlue, "Back", 15);
    m_events_widget->setBorderRoundess(10);
    m_dismiss_widget = new PlaceholderWidget(this, m_help_widget_size, Qt::darkBlue, "Dismiss all", 15);
    m_dismiss_widget->setBorderRoundess(10);

    connect(m_events_widget, SIGNAL(clicked()), this, SLOT(notificationClicked()));
    connect(m_help_widget, SIGNAL(clicked()), this, SLOT(helpClicked()));
    connect(m_dismiss_widget, SIGNAL(clicked()), this, SLOT(dismissAll()));
    connect(&m_notification_state, SIGNAL(notificationUpdate()), this, SLOT(notificationUpdate()));

    setupLayout();

    m_pTableWidget = new QTableWidget(this);
    QStringList m_TableHeader;
    m_pTableWidget->setRowCount(8);
    m_pTableWidget->setColumnCount(5);
    m_TableHeader<<"Level"<<"Time"<<"Location"<<"Description"<<"Dismiss";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);

    connect(m_pTableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(cellClicked(int,int)));

    for (int c = 0; c < m_pTableWidget->horizontalHeader()->count(); ++c)
    {
        m_pTableWidget->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Fixed);
        m_pTableWidget->horizontalHeader()->resizeSection(c, getColumWidth(c));
    }

    m_pTableWidget->verticalHeader()->setDefaultSectionSize(52);

    m_pTableWidget->verticalHeader()->setVisible(false);
    m_pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_pTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    m_pTableWidget->setShowGrid(true);
    m_pTableWidget->setStyleSheet("QTableView {selection-background-color: red; background-color: rgb(128, 128, 128);}");
    m_pTableWidget->setGeometry(QRect(0, 0, 800, 441));

    notificationUpdate();
}

void NotificationScreen::setupLayout()
{
    m_help_widget->resize(m_help_widget_size.width() * m_width_scale, m_help_widget_size.height() * m_height_scale);
    m_help_widget->move(m_help_widget_pos.x() * m_width_scale, m_help_widget_pos.y() * m_height_scale);
    m_events_widget->resize(m_events_widget_size.width() * m_width_scale, m_events_widget_size.height() * m_height_scale);
    m_events_widget->move(m_events_widget_pos.x() * m_width_scale, m_events_widget_pos.y() * m_height_scale);
    m_dismiss_widget->resize(m_dismiss_widget_size.width() * m_width_scale, m_dismiss_widget_size.height() * m_height_scale);
    m_dismiss_widget->move(m_dismiss_widget_pos.x() * m_width_scale, m_dismiss_widget_pos.y() * m_height_scale);

    m_events_widget->raise();
}
