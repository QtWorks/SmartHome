#include "main_screen.h"

#include "home_screen.h"
#include "temperature_screen.h"
#include "lighting_screen.h"
#include "renewable_energy_screen.h"
#include "garden_watering_screen.h"
#include "spendings_screen.h"
#include "home_appliances_screen.h"
#include "alarm_screen.h"
#include "video_surveillance_screen.h"
#include "settings_screen.h"
#include "notification_screen.h"
#include "hhelp_text_screen.h"
#include <QDebug>

QPixmap MainScreen::getImage(int index)
{
    switch (index)
    {
        case 0:
            return QPixmap(":/Smart home/home.png");

        case 1:
            return QPixmap(":/Smart home/temperature.png");

        case 2:
            return QPixmap(":/Smart home/light.png");

        case 3:
            return QPixmap(":/Smart home/renewable_energy.png");

        case 4:
            return QPixmap(":/Smart home/gardening.png");

        case 5:
            return QPixmap(":/Smart home/energy_trends.png");

        case 6:
            return QPixmap(":/Smart home/home_appliance.png");

        case 7:
            return QPixmap(":/Smart home/alarm.png");

        case 8:
            return QPixmap(":/Smart home/camera.png");

        case 9:
            return QPixmap(":/Smart home/settings.png");
    }

    return QPixmap();
}

QString MainScreen::getTitle(int index)
{
    switch (index)
    {
        case 0:
            return "Home Screen Help";

        case 1:
            return "Temperature Screen Help";

        case 2:
            return "Lighting Screen Help";

        case 3:
            return "Renewable Energy Screen Help";

        case 4:
            return "Garden Watering Screen Help";

        case 5:
            return "Spendings Screen Help";

        case 6:
            return "Home Appliances Screen Help";

        case 7:
            return "Alarm Screen Help";

        case 8:
            return "Video Surveillance Screen Help";

        case 9:
            return "Profiles Screen Help";

        case 10:
            return "Notification Screen Help";
    }

    return "";
}

QString MainScreen::getFileName(int index)
{
    switch (index)
    {
        case 0:
            return "home_screen_help.txt";

        case 1:
            return "temperature_screen_help.txt";

        case 2:
            return "lighting_screen_help.txt";

        case 3:
            return "renewable_energy_screen_help.txt";

        case 4:
            return "garden_watering_screen_help.txt";

        case 5:
            return "spendings_screen_help.txt";

        case 6:
            return "home_appliances_screen_help.txt";

        case 7:
            return "alarm_screen_help.txt";

        case 8:
            return "video_surveillance_screen_help.txt";

        case 9:
            return "profiles_screen_help.txt";

        case 10:
            return "notification_screen_help.txt";
    }

    return "";
}

QString MainScreen::getText(int index)
{
    QString path = ":/help/" + getFileName(index);
    QString text = "";

    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        text = file.readAll();
    }

    return text;
}

void MainScreen::screenSelected(int index)
{
    if (m_screens_active == false)
    {
        m_screens_active = true;
        returnFromHelpSlot();
    }

    if (m_notification_visible)
    {
        m_notification_visible = false;
        returnFromNotificationSlot();
    }

    for (int i = 0; i < m_count; i++)
    {
        m_navigation_widget_vector.at(i)->setSelected(false);
    }

    m_navigation_widget_vector.at(index)->setSelected(true, Qt::white);
    m_screen_layout->setCurrentIndex(index);
    m_help_layout->setCurrentIndex(index);
}

void MainScreen::goToNotificationSlot()
{
    m_notification_visible = true;
    m_help_layout->setCurrentIndex(m_help_layout->count() - 1);
    setupLayout();
}

void MainScreen::goToHelpSlot()
{
    m_screens_active = false;
    setupLayout();
}

void MainScreen::returnFromNotificationSlot()
{
    m_notification_visible = false;
    m_help_layout->setCurrentIndex(m_screen_layout->currentIndex());
    setupLayout();
}

void MainScreen::returnFromHelpSlot()
{
    m_screens_active = true;
    setupLayout();
}

MainScreen::MainScreen(QWidget* parent) : BaseScreen(parent)
{
    m_navigation_background = new BackgroundWidget(this, m_navigation_background_size, Qt::darkGray);
    m_navigation_background->setBorderRoundess(10);

    for (int i = 0; i < m_count; i++)
    {
        NavigationWidget* navigation_widget = new NavigationWidget(this, m_navigation_widget_size, getImage(i));
        navigation_widget->setIndex(i);
        m_navigation_widget_vector.push_back(navigation_widget);
        connect(navigation_widget, SIGNAL(selected(int)), this, SLOT(screenSelected(int)));
    }

    m_navigation_widget_vector.at(0)->setSelected(true, Qt::white);

    m_screen = new QWidget(this);
    m_screen->resize(m_screen_size);
    m_screen_layout = new QStackedLayout(m_screen);
    m_screen_layout->addWidget(new HomeScreen(m_screen));
    m_screen_layout->addWidget(new TemperatureScreen(m_screen));
    m_screen_layout->addWidget(new LightingScreen(m_screen));
    m_screen_layout->addWidget(new RenewableEnergyScreen(m_screen));
    m_screen_layout->addWidget(new GardenWateringScreen(m_screen));
    m_screen_layout->addWidget(new SpendingsScreen(m_screen));
    m_screen_layout->addWidget(new HomeAppliancesScreen(m_screen));
    m_screen_layout->addWidget(new AlarmScreen(m_screen));
    m_screen_layout->addWidget(new VideoSurveillanceScreen(m_screen));
    m_screen_layout->addWidget(new SettingsScreen(m_screen));
    m_screen->setLayout(m_screen_layout);

    for (int i = 0; i < m_screen_layout->count(); i++)
    {
        auto base_screen = dynamic_cast<BaseScreen*>(m_screen_layout->widget(i));
        connect(base_screen, SIGNAL(goToNotification()), this, SLOT(goToNotificationSlot()));
        connect(base_screen, SIGNAL(goToHelp()), this, SLOT(goToHelpSlot()));
    }

    m_notification_screen = new NotificationScreen(this);
    connect(m_notification_screen, SIGNAL(goToHelp()), this, SLOT(goToHelpSlot()));
    connect(m_notification_screen, SIGNAL(navigateToScreen(int)), this, SLOT(screenSelected(int)));
    m_notification_screen->hide();

    connect(m_notification_screen, SIGNAL(returnFromNotification()), this, SLOT(returnFromNotificationSlot()));

    m_help_screen = new QWidget(this);
    m_help_screen->resize(m_help_screen_size);
    m_help_layout = new QStackedLayout(m_help_screen);

    for (int i = 0; i < m_screen_layout->count() + 1; i++)
    {
        QString title = getTitle(i);
        QString text = getText(i);
        HHelpScreen* hhelp_screen = new HHelpTextScreen(m_help_screen, title, text);
        connect(hhelp_screen, SIGNAL(returmFromHelp()), this, SLOT(returnFromHelpSlot()));
        m_help_layout->addWidget(hhelp_screen);
    }

    m_help_layout->setCurrentIndex(0);
    m_help_screen->setLayout(m_help_layout);

    setupLayout();
}

void MainScreen::setupLayout()
{
    m_navigation_background->resize(m_navigation_background_size.width() * m_width_scale, m_navigation_background_size.height() * m_height_scale);
    m_navigation_background->move(m_navigation_background_pos.x() * m_width_scale, m_navigation_background_pos.y() * m_height_scale);

    QSize navigation_widget_size(m_navigation_widget_size.width() * m_width_scale, m_navigation_widget_size.height() * m_height_scale);
    for (auto navigation_widget: m_navigation_widget_vector)
    {
        navigation_widget->resize(navigation_widget_size);
    }

    for (int i = 0; i < m_navigation_widget_vector.size(); i++)
    {
        qreal x = (m_navigation_background_pos.x() + 0.5f * m_navigation_background_size.width() - 0.5f * m_navigation_widget_size.width()) * m_width_scale + 0.5f;
        QPoint pos(x, (m_navigation_background_pos.y() + 0.5f * m_border_width + i * (m_navigation_widget_size.height() + 5.8f) + 2.5f) * m_height_scale);
        m_navigation_widget_vector[i]->move(pos);
    }

    m_screen->resize(m_screen_size.width() * m_width_scale, m_screen_size.height() * m_height_scale);
    m_screen->move(m_screen_pos.x() * m_width_scale, m_screen_pos.y() * m_height_scale);

    m_help_screen->resize(m_help_screen_size.width() * m_width_scale, m_help_screen_size.height() * m_height_scale);
    m_help_screen->move(m_help_screen_pos.x() * m_width_scale, m_help_screen_pos.y() * m_height_scale);

    m_notification_screen->resize(size());
    m_notification_screen->move(0, 0);

    if (m_notification_visible)
    {
        m_screen->hide();
        m_help_screen->hide();
        m_notification_screen->show();
    }
    else
    {
        m_screen->hide();
        m_help_screen->hide();
        m_notification_screen->hide();
    }

    if (m_screens_active == true)
    {
        m_screen->show();
        m_help_screen->hide();
        m_navigation_background->show();

        for (auto navigation_widget: m_navigation_widget_vector)
        {
            navigation_widget->show();
        }
    }
    else
    {
        m_screen->hide();
        m_help_screen->show();
        m_navigation_background->hide();

        for (auto navigation_widget: m_navigation_widget_vector)
        {
            navigation_widget->hide();
        }

        m_help_screen->raise();
    }
}
