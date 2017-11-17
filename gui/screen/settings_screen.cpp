#include "settings_screen.h"
#include <QTabWidget>
#include <QProxyStyle>
#include <QBoxLayout>
#include <QTabBar>
#include <QMessageBox>

class HackTabWidget : public QTabWidget
{
public:
    using QTabWidget::tabBar;
};

SettingsScreen::SettingsScreen(QWidget* parent) : LeftScreen(parent)
{

    m_title_widget->setTitle("Profiles Screen");

    // Left widget alignment options
    // m_left_widget_pos = QPoint(0, 72);
    // m_left_widget_size = QSize(728, 368);
    m_left_widget_pos = QPoint(0, 102);
    m_left_widget_size = QSize(728, 338);

    PlaceholderWidget* widget = new PlaceholderWidget(this, QSize(728, 52), QColor(75, 75, 75), "", 20);
    widget->move(m_left_widget_pos);

    m_left_widget = new QWidget(this);

    m_tab_widget = new QTabWidget(m_left_widget);
    m_tab_widget->setStyle(new QProxyStyle());
    static_cast<HackTabWidget*>(m_tab_widget)->tabBar()->setFocusPolicy(Qt::NoFocus);
    QBoxLayout* layout = new QVBoxLayout(m_left_widget);
    int t;
    layout->getContentsMargins(0, &t, 0, 0);
    layout->setContentsMargins(0, t, 0, 0);
    layout->addWidget(m_tab_widget);

    m_active_prof_widget = new ActiveProfileWidget(this, m_tab_widget_size);
    m_workday_prof_widget  = new WorkdayProfileWidget(this, m_tab_widget_size);
    m_weekend_prof_widget  = new WeekendProfileWidget(this, m_tab_widget_size);
    m_vacation_prof_widget = new VacationProfileWidget(this, m_tab_widget_size);
    m_tab_widget->addTab(m_active_prof_widget, tr("Profile"));
    m_tab_widget->addTab(m_workday_prof_widget, tr("Workday"));
    m_tab_widget->addTab(m_weekend_prof_widget, tr("Weekend"));
    m_tab_widget->addTab(m_vacation_prof_widget, tr("Vacation"));
}
