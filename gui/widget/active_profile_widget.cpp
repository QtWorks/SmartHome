#include "active_profile_widget.h"
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgslideswitch.h"
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <QPainter>
#include <QRadioButton>

ActiveProfileWidget::ActiveProfileWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    toplay = new QGridLayout(this);
    QGroupBox* beryl = new QGroupBox(tr(""), this);
    toplay->addWidget(beryl, 0, 0);


    QGridLayout* bgrid = new QGridLayout(beryl);

    QLabel* label = new QLabel(tr("Active Profile: "), beryl);
    QFont font = label->font();
    font.setPixelSize(24);
    font.setBold(true);
    label->setFont(font);
    label->setAlignment(Qt::AlignHCenter);
    bgrid->addWidget(label, 0, 1, Qt::AlignHCenter);

    QLabel* weekly_label = new QLabel(tr("Weekly"), beryl);
    QRadioButton* weekly_button = new QRadioButton(beryl);
    weekly_button->setChecked(true);
    weekly_label->setFont(font);
    bgrid->addWidget(weekly_label, 1, 0, Qt::AlignHCenter);
    bgrid->addWidget(weekly_button, 1, 2, Qt::AlignHCenter);

    QLabel* vacation_label = new QLabel(tr("Vacation"), beryl);
    QRadioButton* vacation_button = new QRadioButton(beryl);
    vacation_label->setFont(font);
    bgrid->addWidget(vacation_label, 2, 0, Qt::AlignHCenter);
    bgrid->addWidget(vacation_button, 2, 2, Qt::AlignHCenter);

    QLabel* dummy_label = new QLabel(tr(""), beryl);
    dummy_label->setMinimumSize(100, 100);
    bgrid->addWidget(dummy_label, 3, 1, Qt::AlignHCenter);
}

