#ifndef BASE_SCREEN_H
#define BASE_SCREEN_H

#include "../widget/scalable_widget.h"

class BaseScreen : public ScalableWidget
{
    Q_OBJECT

protected:
    explicit BaseScreen(QWidget* parent);
    void resizeEvent(QResizeEvent*);

    virtual void setupLayout() = 0;

public:
signals:
    void goToNotification();
    void goToHelp();
    void returnFromNotification();
    void returmFromHelp();
};

#endif
