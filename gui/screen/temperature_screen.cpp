#include "temperature_screen.h"
#include <QMessageBox>
#include <QDebug>

void TemperatureScreen::temperature()
{
    m_temp_opt_widget->setDisabled(true);
    m_temp_opt_widget->setDisabled(true);
    m_left_widget->setDisabled(true);

    m_thermometer->show();
}

void TemperatureScreen::ventilatorOn()
{
    QMessageBox message_box(QMessageBox::Information,
                                    "",
                                    "All ventilators turned on!",
                                    QMessageBox::Ok, (QWidget*)this,
                                    Qt::FramelessWindowHint);

    message_box.setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 20, 20); font: 16px; min-width: 180px; min-height: 40px;} QMessageBox { background-color: black; border: 2px solid rgb(80, 80, 80);} QLabel { color: rgb(255, 255, 255); font: 16px; text-align: justify; }");

    message_box.exec();

    TemperatureFloormapWidget* widget = dynamic_cast<TemperatureFloormapWidget*>(m_left_widget);
    widget->setGlobalVentilatorValue(true);

    update();
}

void TemperatureScreen::ventilatorOff()
{
    QMessageBox message_box(QMessageBox::Information,
                                    "",
                                    "All ventilators turned off!",
                                    QMessageBox::Ok, (QWidget*)this,
                                    Qt::FramelessWindowHint);

    message_box.setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 20, 20); font: 16px; min-width: 180px; min-height: 40px;} QMessageBox { background-color: black; border: 2px solid rgb(80, 80, 80);} QLabel { color: rgb(255, 255, 255); font: 16px; text-align: justify; }");

    message_box.exec();

    TemperatureFloormapWidget* widget = dynamic_cast<TemperatureFloormapWidget*>(m_left_widget);
    widget->setGlobalVentilatorValue(false);

    update();
}

void TemperatureScreen::ok()
{
    TemperatureFloormapWidget* widget = dynamic_cast<TemperatureFloormapWidget*>(m_left_widget);
    widget->setGlobalValue(m_thermometer->value());

    m_temp_opt_widget->setDisabled(false);
    m_temp_opt_widget->setDisabled(false);
    m_left_widget->setDisabled(false);

    m_thermometer->hide();
}

void TemperatureScreen::cancel()
{
    m_temp_opt_widget->setDisabled(false);
    m_temp_opt_widget->setDisabled(false);
    m_left_widget->setDisabled(false);

    m_thermometer->hide();
}

TemperatureScreen::TemperatureScreen(QWidget* parent) : LeftRightScreen(parent)
{
    m_left_widget = new TemperatureFloormapWidget(this, m_left_widget_size, QPixmap(":/Smart home/floormap_names.png"));

    m_title_widget->setTitle("Temperature Screen");

    m_temp_opt_widget = new TemperatureOptionsWidget(this, m_right_widget_size);
    m_right_widget->setBackgroundColor(Qt::black);

    connect(m_temp_opt_widget, SIGNAL(temperature()), this, SLOT(temperature()));
    connect(m_temp_opt_widget, SIGNAL(ventilatorOn()), this, SLOT(ventilatorOn()));
    connect(m_temp_opt_widget, SIGNAL(ventilatorOff()), this, SLOT(ventilatorOff()));

    m_thermometer = new ThermometerOverlayWidget(this);
    m_thermometer->move(125, 112);
    m_thermometer->hide();

    connect(m_thermometer, SIGNAL(ok()), this, SLOT(ok()));
    connect(m_thermometer, SIGNAL(cancel()), this, SLOT(cancel()));

    setupLayout();
}

void TemperatureScreen::setupLayout()
{
    LeftRightScreen::setupLayout();

    m_temp_opt_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_temp_opt_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);
}
