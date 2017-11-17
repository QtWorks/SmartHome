#ifndef NAVIGATION_CONTROLLER
#define NAVIGATION_CONTROLLER

#include <QStackedLayout>
#include <QVector>

enum class ContentType { TEMPERATURE, LIGHTING, RENEWABLE_ENERGY, GARDEN_WATERING, PARAMETER_TRENDS, VENTILATION, ALARM, WEATHER_FORECAST, SPENDINGS };

class NavigationController
{
    static NavigationController* m_instance;
    QStackedLayout* m_layout{nullptr};

    NavigationController();

    QVector<ContentType> m_content_screen_vector{ };

    QWidget* createContentScreen(QWidget* parent, ContentType content_type);
    QStackedLayout* createLayout(QWidget* parent);

public:
    static NavigationController& instance();
    QStackedLayout* getLayout(QWidget* parent);

    void navigate(int index);
    void navigateHome();
};

#endif
