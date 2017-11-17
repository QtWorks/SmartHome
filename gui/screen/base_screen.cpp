#include "base_screen.h"

BaseScreen::BaseScreen(QWidget* parent) : ScalableWidget(parent, parent->size())
{
    QPalette palette(BaseScreen::palette());
    palette.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(palette);
}

void BaseScreen::resizeEvent(QResizeEvent*)
{
    updateScale();
    setupLayout();
}
