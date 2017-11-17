#include "hhelp_screen.h"
#include <QPainter>

void HHelpScreen::helpClicked()
{
    emit returmFromHelp();
    setupLayout();
}

HHelpScreen::HHelpScreen(QWidget* parent, QString title) : BaseScreen(parent), m_title(title)
{
    m_help_widget = new PlaceholderWidget(this, m_help_widget_size, Qt::darkBlue, "Back", 15);
    m_help_widget->setBorderRoundess(10);

    connect(m_help_widget, SIGNAL(clicked()), this, SLOT(helpClicked()));

    setupLayout();
}

void HHelpScreen::setupLayout()
{
    m_help_widget->resize(m_help_widget_size.width() * m_width_scale, m_help_widget_size.height() * m_height_scale);
    m_help_widget->move(m_help_widget_pos.x() * m_width_scale, m_help_widget_pos.y() * m_height_scale);
}

void HHelpScreen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QFont font;
    font.setPixelSize(32 * m_scale);
    font.setBold(true);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    QRect title_rect(10, 10, 750, 40);

    painter.drawText(title_rect, Qt::AlignCenter, m_title);
}

