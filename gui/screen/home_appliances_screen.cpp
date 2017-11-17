#include "home_appliances_screen.h"
#include <QDebug>
#include <QGroupBox>
#include "qtsvgslideswitch.h"
#include "qtsvgbutton.h"
#include <qlabel.h>

QPixmap HomeAppliancesScreen::getPixmap(int index)
{
    switch (index)
    {
        case 0:
            return QPixmap(":/Smart home/router.png");

        case 1:
            return QPixmap(":/Smart home/TV.png");

        case 3:
            return QPixmap(":/Smart home/TV.png");

        case 2:
            return QPixmap(":/Smart home/sound.png");

        case 4:
            return QPixmap(":/Smart home/computer.png");

        case 5:
            return QPixmap(":/Smart home/wash.png");

        case 6:
            return QPixmap(":/Smart home/boiler1.png");

        case 7:
            return QPixmap(":/Smart home/boiler1.png");

        case 8:
            return QPixmap(":/Smart home/oven.png");

        case 9:
            return QPixmap(":/Smart home/microwave.png");

        case 10:
            return QPixmap(":/Smart home/wash.png");

        case 11:
            return QPixmap(":/Smart home/fridge.png");

        case 12:
            return QPixmap(":/Smart home/TV.png");

        case 13:
            return QPixmap(":/Smart home/sound.png");

        case 14:
            return QPixmap(":/Smart home/TV.png");

        case 15:
            return QPixmap(":/Smart home/sound.png");
    }

    return QPixmap("");;
}

QString HomeAppliancesScreen::getRoomName(int index) const
{
    switch (index)
    {
        case 0:
            return "Living room";

        case 1:
            return "Living room";

        case 2:
            return "Parent's Bedroom";

        case 3:
            return "Parent's Bedroom";

        case 4:
            return "Parent's Bedroom";

        case 5:
            return "Washroom";

        case 6:
            return "Washroom";

        case 7:
            return "Kitchen";

        case 8:
            return "Kitchen";

        case 9:
            return "Kitchen";

        case 10:
            return "Kitchen";

        case 11:
            return "Kitchen";

        case 12:
            return "Bob's Bedroom";

        case 13:
            return "Bob's Bedroom";

        case 14:
            return "Alice's Bedroom";

        case 15:
            return "Alice's Bedroom";
    }

    return "";
}

void HomeAppliancesScreen::iconClicked(int index)
{
    for (int i = 0; i < m_icon_widget_vector.size(); i++)
    {
        if (i != index)
            m_icon_widget_vector[i]->setOn(false);
    }

    m_home_app_opt_widget->setVisible(index);
}

void HomeAppliancesScreen::powerUpdate()
{
    for (int i = 0; i < m_row_count * m_column_count; i++)
    {
        m_icon_widget_vector[i]->setActive(m_power_state.enabled(i));
    }
}

void HomeAppliancesScreen::turnOffAll()
{
    for (int i = 0; i < m_row_count * m_column_count; i++)
    {
         m_power_state.setEnabled(i, false);
    }

    for (int i = 0; i < m_row_count * m_column_count; i++)
    {
        m_icon_widget_vector[i]->setActive(m_power_state.enabled(i));
        m_home_app_opt_widget->setState(i, m_power_state.enabled(i));
    }
}

HomeAppliancesScreen::HomeAppliancesScreen(QWidget* parent) : LeftRightScreen(parent)
{
    m_title_widget->setTitle("Home Appliances Screen");
    m_home_app_opt_widget = new HomeAppliancesOptionsWidget(this, m_right_widget_size);
    m_right_widget->setBackgroundColor(Qt::black);
    QVector<QPixmap *> pixmaps;
    pixmaps.push_back(new QPixmap(":/Smart home/boiler.png")) ;
    pixmaps.push_back(new QPixmap(":/Smart home/router.png")) ;

    m_dismiss_widget = new PlaceholderWidget(this, m_dismiss_widget_size, Qt::darkBlue, "Turn off all", 15);
    m_dismiss_widget->setBorderRoundess(10);
    connect(m_dismiss_widget, SIGNAL(clicked()), this, SLOT(turnOffAll()));

    for (int i = 2; i < m_row_count * m_column_count; i++)
    {
pixmaps.push_back(new QPixmap(":/Smart home/wash.png")) ;
    }


    for (int i = 0; i < m_row_count * m_column_count; i++)
    {
        IconWidget* icon_widget = new IconWidget(this, m_icon_widget_size, getPixmap(i),getRoomName(i), 11, i);
        connect(icon_widget, SIGNAL(clicked(int)), this, SLOT(iconClicked(int)));
        m_icon_widget_vector.push_back(icon_widget);
    }

    for (int i = 0; i < m_row_count * m_column_count; i++)
    {
        m_icon_widget_vector[i]->setActive(m_power_state.enabled(i));
    }

    connect(&m_power_state, SIGNAL(update()), this, SLOT(powerUpdate()));

    m_icon_widget_vector[0]->setOn(true);

    setupLayout();
}

void HomeAppliancesScreen::setupLayout()
{
    LeftRightScreen::setupLayout();

    for (auto icon_widget: m_icon_widget_vector)
    {
        icon_widget->resize(m_icon_widget_size.width() * m_width_scale, m_icon_widget_size.height() * m_height_scale);
    }

    for (int i = 0; i < m_row_count; i++)
    {
        for (int j = 0; j < m_column_count; j++)
        {
            qreal x = j * (m_icon_widget_size.width() + m_column_space) * m_width_scale;
            qreal y = m_title_widget->rect().bottomLeft().y() + i * (m_icon_widget_size.height() + m_row_space) * m_height_scale;

            m_icon_widget_vector[i * m_column_count + j]->move(x, y);
        }
    }

    m_home_app_opt_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_home_app_opt_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);

    m_dismiss_widget->resize(m_dismiss_widget_size.width() * m_width_scale, m_dismiss_widget_size.height() * m_height_scale);
    m_dismiss_widget->move(m_dismiss_widget_pos.x() * m_width_scale, m_dismiss_widget_pos.y() * m_height_scale);
}
