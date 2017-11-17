#include "alarm_options_widget.h"
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgslideswitch.h"
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <QDebug>

AlarmOptionsWidget::AlarmOptionsWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    QGridLayout* toplay = new QGridLayout(this);

    QGroupBox* beryl = new QGroupBox(tr(""), this);

    toplay->addWidget(beryl, 0, 0);
    button = new QtSvgButton(beryl);
    button->setSkin("BerylSquare");
    connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    //QLabel* label = new QLabel(tr("Set global brightness"), beryl);
   // label->setAlignment(Qt::AlignHCenter);


    QGridLayout* bgrid = new QGridLayout(beryl);

    m_slide = new QtSvgSlideSwitch(beryl);
    m_slide->setMinimumSize(250, 90);
    m_slide->setSkin("Beryl");
    QLabel* label = new QLabel(tr("Sound Alarm"), beryl);
    label->setAlignment(Qt::AlignHCenter);
    bgrid->addWidget(m_slide, 0, 0, Qt::AlignHCenter);
    bgrid->addWidget(label, 1, 0, Qt::AlignHCenter);
    bgrid->addWidget(button, 2, 0, Qt::AlignHCenter);
    label = new QLabel(tr("Turn off"), beryl);
    label->setAlignment(Qt::AlignHCenter);
    bgrid->addWidget(label, 3, 0, Qt::AlignHCenter);

    connect(m_slide, SIGNAL(stateChanged(QtSvgSlideSwitch*,bool)), this, SLOT(switchChanged(QtSvgSlideSwitch*,bool)));
    m_alarm = new QSound(":/Smart home/alarm.wav");
    m_alarm->setLoops(10000);
    button->setEnabled(false);
}

void AlarmOptionsWidget::setState(bool state)
{
    m_slide->setChecked(state);
}

void AlarmOptionsWidget::paintEvent(QPaintEvent*)
{
    /*
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::red);
    */
}

void AlarmOptionsWidget::switchChanged(QtSvgSlideSwitch*, bool state)
{
    m_alarm_state.setSoundOn(state);
}

void AlarmOptionsWidget::buttonClicked()
{
    emit passwordClicked();
}

void AlarmOptionsWidget::logged()
{
    m_alarm->stop();
    m_alarm_state.setAlarm(1, false);
    m_alarm_state.setAlarmRaised(false);
    button->setEnabled(false);
}

void AlarmOptionsWidget::showEvent(QShowEvent*)
{
    bool alarm = false;

    for (int i = 0; i < m_alarm_state.count(); i++)
    {
        if (m_alarm_state.alarm(i) == true)
        {
            alarm = true;
            break;
        }
    }

    if (alarm && m_alarm_state.soundOn())
    {
        m_alarm->play();
        button->setEnabled(true);
    }
}
