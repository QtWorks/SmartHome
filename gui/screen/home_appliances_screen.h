#ifndef HOME_APPLIANCES_SCREEN_H
#define HOME_APPLIANCES_SCREEN_H

#include "left_right_screen.h"
#include "gui/widget/icon_widget.h"
#include "model/power.h"
#include "gui/widget/home_appliances_options_widget.h"

class HomeAppliancesScreen : public LeftRightScreen
{
    Q_OBJECT

protected:
    QVector<IconWidget*> m_icon_widget_vector;
    HomeAppliancesOptionsWidget* m_home_app_opt_widget{nullptr};
    Power& m_power_state = Singleton<Power>::instance();

    QSize m_icon_widget_size{119, 90};
    int m_row_space{7};
    int m_column_space{5};
    int m_row_count{4};
    int m_column_count{4};

    PlaceholderWidget* m_dismiss_widget;

    QSize m_dismiss_widget_size{228, 35};
    QPoint m_dismiss_widget_pos{30, 443};

    QString getRoomName(int index) const;
    QPixmap getPixmap(int index);

private slots:
    void iconClicked(int index);
    void powerUpdate();
    void turnOffAll();

public:
    explicit HomeAppliancesScreen(QWidget* parent);

protected:
    void setupLayout();
};

#endif
