
#include "vacation_profile_widget.h"
#include <QGridLayout>
#include <QRadioButton>
#include <QGroupBox>
#include "qtsvgslideswitch.h"
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <QPainter>
#include <QObject>
#include <QDebug>
#include "gui/screen/help_screen.h"

VacationProfileWidget::VacationProfileWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    toplay = new QGridLayout(this);
    QGroupBox* beryl = new QGroupBox(tr(""), this);
    toplay->addWidget(beryl, 0, 0);


    QGridLayout* bgrid = new QGridLayout(beryl);

    QLabel* label = new QLabel(tr("Sprinklers: "), beryl);
    QFont font = label->font();
    font.setPixelSize(24);
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignHCenter);
    bgrid->addWidget(label, 0, 1, Qt::AlignHCenter);

    QLabel* on_label = new QLabel(tr("On"), beryl);
    QRadioButton* on_button = new QRadioButton(beryl);
    on_button->setChecked(true);
    on_label->setFont(font);
    bgrid->addWidget(on_label, 1, 0, Qt::AlignHCenter);
    bgrid->addWidget(on_button, 1, 2, Qt::AlignHCenter);

    QLabel* off_label = new QLabel(tr("Off"), beryl);
    QRadioButton* off_button = new QRadioButton(beryl);
    off_label->setFont(font);
    bgrid->addWidget(off_label, 2, 0, Qt::AlignHCenter);
    bgrid->addWidget(off_button, 2, 2, Qt::AlignHCenter);

    QLabel* dummy_label = new QLabel(tr(""), beryl);
    dummy_label->setMinimumSize(100, 100);
    bgrid->addWidget(dummy_label, 3, 1, Qt::AlignHCenter);
}
