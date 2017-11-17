#include "alarm_screen.h"

void AlarmScreen::valueChange(QKeyEvent* event)
{
    if ((event->key() != Qt::Key_Cancel) && (event->key() != Qt::Key_Backspace) && (event->key() != Qt::Key_Enter))
    {
        QString new_char = event->text();
        m_buffer.append(new_char);
        m_keyboard->slotSetText(m_buffer);
    }

    if (event->key() == Qt::Key_Backspace)
    {
        m_buffer.remove(m_buffer.length() - 1, 1);
        m_keyboard->slotSetText(m_buffer);
    }

    if (event->key() == Qt::Key_Enter)
    {
        if (m_buffer == "123456")
        {
            emit logged();
        }

        m_keyboard->hide();
        m_keyboard->slotSetText("");
        m_buffer = "";
    }

    if (event->key() == Qt::Key_Cancel)
    {
        m_keyboard->slotSetText("");
        m_buffer = "";
    }
}

void AlarmScreen::passwordClicked()
{
    m_keyboard->raise();
    m_keyboard->show();
    m_keyboard->raise();
    m_keyboard->show();
}

AlarmScreen::AlarmScreen(QWidget* parent) : LeftRightScreen(parent)
{
    m_left_widget = new AlarmFloormapWidget(this, m_left_widget_size, QPixmap(":/Smart home/floormap_names.png"));
    m_alarm_opt_widget = new AlarmOptionsWidget(this, m_right_widget_size);
    m_right_widget->setBackgroundColor(Qt::black);

    m_alarm_opt_widget->setState(m_alarm_state.soundOn());

    m_title_widget->setTitle("Alarm Screen");

    m_keyboard = new QVirtualKeyboard(parent);
    m_keyboard->slotSwitchLayout();
    m_keyboard->setFixedSize(730, 480);
    m_keyboard->move(0, 0);
    m_keyboard->hide();

    connect(m_keyboard, SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(valueChange(QKeyEvent*)));
    connect(m_alarm_opt_widget, SIGNAL(passwordClicked()), this, SLOT(passwordClicked()));
    connect(this, SIGNAL(logged()), m_alarm_opt_widget, SLOT(logged()));
}

void AlarmScreen::setupLayout()
{
    LeftRightScreen::setupLayout();

    m_alarm_opt_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_alarm_opt_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);
}

void AlarmScreen::leaveEvent(QEvent *)
{
    m_keyboard->hide();
}
