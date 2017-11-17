#include "lighting_screen.h"
#include <QDebug>
#include "gui/widget/lighting_floormap_widget.h"
#include <QMessageBox>

void LightingScreen::lighting()
{
    m_light_opt_widget->setDisabled(true);
    m_light_opt_widget->setDisabled(true);
    m_left_widget->setDisabled(true);

    m_lighting->show();
}

void LightingScreen::lightingOn()
{
    QMessageBox message_box(QMessageBox::Information,
                                    "",
                                    "All lights turned to 100%!",
                                    QMessageBox::Ok, (QWidget*)this,
                                    Qt::FramelessWindowHint);

    message_box.setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 20, 20); font: 16px; min-width: 180px; min-height: 40px;} QMessageBox { background-color: black; border: 2px solid rgb(80, 80, 80);} QLabel { color: rgb(255, 255, 255); font: 16px; text-align: justify; }");

    message_box.exec();

    LightingFloormapWidget* widget = dynamic_cast<LightingFloormapWidget*>(m_left_widget);
    widget->setGlobalValue(100);
}

void LightingScreen::lightingOff()
{
    QMessageBox message_box(QMessageBox::Information,
                                    "",
                                    "All lights turned to 0%!",
                                    QMessageBox::Ok, (QWidget*)this,
                                    Qt::FramelessWindowHint);

    message_box.setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 20, 20); font: 16px; min-width: 180px; min-height: 40px;} QMessageBox { background-color: black; border: 2px solid rgb(80, 80, 80);} QLabel { color: rgb(255, 255, 255); font: 16px; text-align: justify; }");

    message_box.exec();

    LightingFloormapWidget* widget = dynamic_cast<LightingFloormapWidget*>(m_left_widget);
    widget->setGlobalValue(0);
}

void LightingScreen::ok()
{
    LightingFloormapWidget*  widget = dynamic_cast<LightingFloormapWidget*>(m_left_widget);
    widget->setGlobalValue(m_lighting->value());

    m_light_opt_widget->setDisabled(false);
    m_light_opt_widget->setDisabled(false);
    m_left_widget->setDisabled(false);

    m_lighting->hide();
}

void LightingScreen::cancel()
{
    m_light_opt_widget->setDisabled(false);
    m_light_opt_widget->setDisabled(false);
    m_left_widget->setDisabled(false);

    m_lighting->hide();
}

LightingScreen::LightingScreen(QWidget* parent) : LeftRightScreen(parent)
{
    m_left_widget = new LightingFloormapWidget(this, m_left_widget_size, QPixmap(":/Smart home/floormap_names.png"));
    m_title_widget->setTitle("Lighting Screen");

    m_light_opt_widget = new LightingOptionsWidget(this, m_right_widget_size);
    m_right_widget->setBackgroundColor(Qt::black);

    connect(m_light_opt_widget, SIGNAL(lighting()), this, SLOT(lighting()));
    connect(m_light_opt_widget, SIGNAL(lightingOn()), this, SLOT(lightingOn()));
    connect(m_light_opt_widget, SIGNAL(lightingOff()), this, SLOT(lightingOff()));

    m_lighting = new LightingOverlayWidget(this);
    m_lighting->move(125, 112);
    m_lighting->hide();

    connect(m_lighting, SIGNAL(ok()), this, SLOT(ok()));
    connect(m_lighting, SIGNAL(cancel()), this, SLOT(cancel()));
}

void LightingScreen::setupLayout()
{
    LeftRightScreen::setupLayout();

    m_light_opt_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_light_opt_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);
}
