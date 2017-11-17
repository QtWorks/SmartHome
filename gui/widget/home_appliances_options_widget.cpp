#include "home_appliances_options_widget.h"
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgslideswitch.h"
#include "qtsvgbutton.h"
#include <qlabel.h>
#include "gui/widget/power_widget.h"

QGroupBox *HomeAppliancesOptionsWidget::getOptions(int index)
{
    QGroupBox* beryl = new QGroupBox(tr(""), this);
    bool state = m_power_state.enabled(index);

    toplay->addWidget(beryl, 0, 0);

    QGridLayout* bgrid = new QGridLayout(beryl);

    QtSvgSlideSwitch* slide = new QtSvgSlideSwitch(beryl);
    m_slider_vector.push_back(slide);
    slide->updateSwitchPosition(state);
    slide->setChecked(state);
    slide->setMinimumSize(250, 90);
    slide->setSkin("Beryl");
    QLabel* label = new QLabel(tr((getName(index) + " State").toLatin1().data()), beryl);
    label->setAlignment(Qt::AlignHCenter);
    bgrid->addWidget(slide, 0, 0, Qt::AlignHCenter);
    bgrid->addWidget(label, 1, 0, Qt::AlignHCenter);
    int power = state * m_power_state.getPower(index);
    PowerWidget* power_widget = new PowerWidget(this, QSize(250, 250), power, 40);
    m_power_widget_vector.push_back(power_widget);
    power_widget->setMinimumSize(250, 250);
    bgrid->addWidget(power_widget, 3, 0, Qt::AlignHCenter);

    return beryl;
}

QGroupBox *HomeAppliancesOptionsWidget::getOptionsWithoutSwitch()
{
    // TODO: Refactor properly
    QGroupBox* beryl = new QGroupBox(tr(""), this);

    return beryl;
}

QString HomeAppliancesOptionsWidget::getName(int index)
{
    switch (index)
    {
        case 0:
            return "Router";

        case 1:
            return "TV";

        case 2:
            return "Stereo";

        case 3:
            return "TV";

        case 4:
            return "PC";

        case 5:
            return "Washer";

        case 6:
        case 7:
            return "Water Heater";

        case 8:
            return "Oven";

        case 9:
            return "Microwave";

        case 10:
            return "Washer";

        case 11:
            return "Fridge";

        case 12:
            return "TV";

        case 13:
            return "Stereo";

        case 14:
            return "TV";

        case 15:
            return "Stereo";
    }

    return "";
}

HomeAppliancesOptionsWidget::HomeAppliancesOptionsWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    toplay = new QGridLayout(this);

    for (int i = 0; i < m_switchable.size(); i++)
    {
        if (m_switchable[i])
        {
            m_beryl_vector.push_back(getOptions(i));
        }
        else
        {
            m_beryl_vector.push_back(getOptionsWithoutSwitch());
        }
    }

    for (int i = 0; i < m_slider_vector.size(); i++)
    {
        connect(m_slider_vector[i], SIGNAL(stateChanged(QtSvgSlideSwitch*,bool)), this, SLOT(switchChanged(QtSvgSlideSwitch*,bool)));
    }

    setVisible(0);
}

void HomeAppliancesOptionsWidget::paintEvent(QPaintEvent*)
{
    /*
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::red);
    */
}

void HomeAppliancesOptionsWidget::setVisible(int index)
{
    for (int i = 0; i < m_beryl_vector.size(); i++)
    {
        m_beryl_vector[i]->hide();
    }

    m_beryl_vector[index]->show();
    m_beryl_vector[index]->raise();

    m_index = index;
}

void HomeAppliancesOptionsWidget::switchChanged(QtSvgSlideSwitch*, bool state)
{
    m_power_state.setEnabled(m_index, state);
    int power = m_power_state.enabled(m_index) * m_power_state.getPower(m_index);
    m_power_widget_vector[m_index]->setPower(power);
}

void HomeAppliancesOptionsWidget::setState(int index, bool state)
{
    m_slider_vector[index]->setChecked(state);
    int power = m_power_state.enabled(index) * m_power_state.getPower(index);
    m_power_widget_vector[index]->setPower(power);
}
