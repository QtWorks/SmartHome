#include "renewable_energy_screen.h"
#include "qtsvgslideswitch.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>


RenewableEnergyScreen::RenewableEnergyScreen(QWidget* parent) : LeftRightScreen(parent)
{
    m_left_widget = new FloormapWidget(this, m_left_widget_size, QPixmap(":/Smart home/renewable_energy.jpg"));
    m_title_widget->setTitle("Renewable Energy Screen");
    m_ren_opt_widget = new RenewableEnergyOptionsWidget(this, m_right_widget_size);
    m_right_widget->setBackgroundColor(Qt::black);

    setupLayout();
}
void RenewableEnergyScreen::setupLayout()
{
    LeftRightScreen::setupLayout();

    m_ren_opt_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_ren_opt_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);
}
