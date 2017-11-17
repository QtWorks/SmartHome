#include "help_screen.h"
#include "QPainter"

HelpScreen::HelpScreen(QWidget* parent): ScalableWidget(parent, parent->size())
{
    QPalette palette(HelpScreen::palette());
    palette.setColor(QPalette::Background, Qt::white);
    setAutoFillBackground(true);
    setPalette(palette);

}


void HelpScreen::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QFont font;
    font.setPixelSize(32 * m_scale);
    font.setBold(true);
    painter.setFont(font);

    QPainterPath path;
    path.addRoundedRect(rect(), m_border_roudness * m_scale, m_border_roudness * m_scale);
    painter.fillPath(path, Qt::darkGray);

    painter.setPen(Qt::black);




}
