#include "left_screen.h"

LeftScreen::LeftScreen(QWidget* parent) : BaseContentScreen(parent)
{
    m_title_widget = new PlaceholderWidget(this, m_title_widget_size, Qt::black, "", 30);

    setupLayout();
}

void LeftScreen::setupLayout()
{
    BaseContentScreen::setupLayout();

    if (m_left_widget != nullptr)
    {
        m_left_widget->resize(m_left_widget_size.width() * m_width_scale, m_left_widget_size.height() * m_height_scale);
        m_left_widget->move(m_left_widget_pos.x() * m_width_scale, m_left_widget_pos.y() * m_height_scale);
    }

    m_title_widget->resize(m_title_widget_size.width() * m_width_scale, m_title_widget_size.height() * m_height_scale);
    m_title_widget->move(m_title_widget_pos.x() * m_width_scale, m_title_widget_pos.y() * m_height_scale);
}

