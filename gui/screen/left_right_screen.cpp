#include "left_right_screen.h"

LeftRightScreen::LeftRightScreen(QWidget* parent) : LeftScreen(parent)
{
    m_right_widget = new PlaceholderWidget(this, m_right_widget_size, Qt::red, "Options", 15);
    m_right_widget->setBorderRoundess(10);

    setupLayout();
}

void LeftRightScreen::setupLayout()
{
    LeftScreen::setupLayout();

    m_right_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_right_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);
}
