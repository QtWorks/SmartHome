#ifndef SETTINGS_SCREEN_H
#define SETTINGS_SCREEN_H

#include "left_screen.h"
#include "gui/widget/active_profile_widget.h"
#include "gui/widget/workday_profile_widget.h"
#include "gui/widget/weekend_profile_widget.h"
#include "gui/widget/vacation_profile_widget.h"
#include <QTabWidget>

class SettingsScreen : public LeftScreen
{
    Q_OBJECT

    ActiveProfileWidget* m_active_prof_widget{nullptr};
    WorkdayProfileWidget* m_workday_prof_widget{nullptr};
    WeekendProfileWidget* m_weekend_prof_widget{nullptr};
    VacationProfileWidget* m_vacation_prof_widget{nullptr};
    QTabWidget* m_tab_widget{nullptr};
    const QSize m_tab_widget_size{728, 300};

public:
    explicit SettingsScreen(QWidget* parent);
};

#endif
