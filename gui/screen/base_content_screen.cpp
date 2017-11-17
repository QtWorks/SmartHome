#include "base_content_screen.h"

void BaseContentScreen::notificationClicked()
{
    emit goToNotification();
    setupLayout();
}

void BaseContentScreen::helpClicked()
{
    emit goToHelp();
    setupLayout();
}

BaseContentScreen::BaseContentScreen(QWidget* parent) : BaseScreen(parent)
{
    m_help_widget = new PlaceholderWidget(this, m_help_widget_size, Qt::darkBlue, "Help", 15);
    m_help_widget->setBorderRoundess(10);
    m_events_widget = new PlaceholderWidget(this, m_help_widget_size, Qt::darkBlue, "Notification list", 15);
    m_events_widget->setBorderRoundess(10);

    connect(m_events_widget, SIGNAL(clicked()), this, SLOT(notificationClicked()));
    connect(m_help_widget, SIGNAL(clicked()), this, SLOT(helpClicked()));

    setupLayout();
}

void BaseContentScreen::setupLayout()
{
    m_help_widget->resize(m_help_widget_size.width() * m_width_scale, m_help_widget_size.height() * m_height_scale);
    m_help_widget->move(m_help_widget_pos.x() * m_width_scale, m_help_widget_pos.y() * m_height_scale);
    m_events_widget->resize(m_events_widget_size.width() * m_width_scale, m_events_widget_size.height() * m_height_scale);
    m_events_widget->move(m_events_widget_pos.x() * m_width_scale, m_events_widget_pos.y() * m_height_scale);

    m_events_widget->raise();
}
