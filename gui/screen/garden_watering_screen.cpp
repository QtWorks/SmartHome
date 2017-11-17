#include "garden_watering_screen.h"
#include <QMessageBox>

void GardenWateringScreen::sprinklerOn()
{
    QMessageBox message_box(QMessageBox::Information,
                                    "",
                                    "All sprinklers turned on!",
                                    QMessageBox::Ok, (QWidget*)this,
                                    Qt::FramelessWindowHint);

    message_box.setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 20, 20); font: 16px; min-width: 180px; min-height: 40px;} QMessageBox { background-color: black; border: 2px solid rgb(80, 80, 80);} QLabel { color: rgb(255, 255, 255); font: 16px; text-align: justify; }");

    message_box.exec();

    GardeningWidget* widget = dynamic_cast<GardeningWidget*>(m_left_widget);
    widget->setGlobalSprinklerValue(true);

    update();
}

void GardenWateringScreen::sprinklerOff()
{
    QMessageBox message_box(QMessageBox::Information,
                                    "",
                                    "All sprinklers turned off!",
                                    QMessageBox::Ok, (QWidget*)this,
                                    Qt::FramelessWindowHint);

    message_box.setStyleSheet("QPushButton { color: rgb(255, 255, 255); background-color: rgb(20, 20, 20); font: 16px; min-width: 180px; min-height: 40px;} QMessageBox { background-color: black; border: 2px solid rgb(80, 80, 80);} QLabel { color: rgb(255, 255, 255); font: 16px; text-align: justify; }");

    message_box.exec();

    GardeningWidget* widget = dynamic_cast<GardeningWidget*>(m_left_widget);
    widget->setGlobalSprinklerValue(false);

    update();
}

GardenWateringScreen::GardenWateringScreen(QWidget* parent) : LeftRightScreen(parent)
{
    m_left_widget = new GardeningWidget(this, m_left_widget_size, QPixmap(":/Smart home/garden.jpg"));
    m_title_widget->setTitle("Garden Watering Screen");
    m_gard_opt_widget = new GardeningOptionsWidget(this, m_right_widget_size);
    m_right_widget->setBackgroundColor(Qt::black);

    connect(m_gard_opt_widget, SIGNAL(sprinklerOn()), this, SLOT(sprinklerOn()));
    connect(m_gard_opt_widget, SIGNAL(sprinklerOff()), this, SLOT(sprinklerOff()));

    setupLayout();
}
void GardenWateringScreen::setupLayout()
{
    LeftRightScreen::setupLayout();

    m_gard_opt_widget->resize(m_right_widget_size.width() * m_width_scale, m_right_widget_size.height() * m_height_scale);
    m_gard_opt_widget->move(m_right_widget_pos.x() * m_width_scale, m_right_widget_pos.y() * m_height_scale);
}
