#include "navigation_controller.h"

#include "screen/home_screen.h"
#include "screen/temperature_screen.h"
#include "screen/lighting_screen.h"
#include "screen/renewable_energy_screen.h"
#include "screen/garden_watering_screen.h"
#include "screen/parameter_trends_screen.h"
#include "screen/ventilation_screen.h"
#include "screen/alarm_screen.h"
#include "screen/weather_forecast_screen.h"
#include "screen/spendings_screen.h"

NavigationController* NavigationController::m_instance{nullptr};

NavigationController::NavigationController()
{

}

QWidget* NavigationController::createContentScreen(QWidget* parent, ContentType content_type)
{
    switch (content_type)
    {
        case ContentType::TEMPERATURE:
            return new TemperatureScreen(parent);

        case ContentType::LIGHTING:
            return new LightingScreen(parent);

        case ContentType::RENEWABLE_ENERGY:
            return new RenewableEnergyScreen(parent);

        case ContentType::GARDEN_WATERING:
            return new GardenWateringScreen(parent);

        case ContentType::PARAMETER_TRENDS:
            return new ParameterTrendsScreen(parent);

        case ContentType::VENTILATION:
            return new VentilationScreen(parent);

        case ContentType::ALARM:
            return new AlarmScreen(parent);

        case ContentType::WEATHER_FORECAST:
            return new WeatherForecastScreen(parent);

        case ContentType::SPENDINGS:
            return new SpendingsScreen(parent);
    }

    return nullptr;
}

QStackedLayout* NavigationController::createLayout(QWidget* parent)
{
    QStackedLayout* layout = new QStackedLayout();

    layout->addWidget(new HomeScreen(parent));

    for (auto content_type: m_content_screen_vector)
    {
        QWidget* content_screen = createContentScreen(parent, content_type);
        layout->addWidget(content_screen);
    }

    return layout;
}

NavigationController& NavigationController::instance()
{
    if (m_instance == nullptr)
    {
        m_instance = new NavigationController();
    }

    return *m_instance;
}

QStackedLayout* NavigationController::getLayout(QWidget* parent)
{
    if (m_layout == nullptr)
    {
        m_layout = createLayout(parent);
    }

    return m_layout;
}

void NavigationController::navigate(int index)
{
    // Offset due to Home screen
    m_layout->setCurrentIndex(index + 1);
}

void NavigationController::navigateHome()
{
    m_layout->setCurrentIndex(0);
}
