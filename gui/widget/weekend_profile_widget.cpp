#include "weekend_profile_widget.h"
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgslideswitch.h"
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <QRadioButton>
#include <QPainter>
#include <QButtonGroup>

WeekendProfileWidget::WeekendProfileWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
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

    QButtonGroup* sprinkler_bg = new QButtonGroup(this);

    QLabel* on_label = new QLabel(tr("On"), beryl);
    QRadioButton* on_button = new QRadioButton();
    on_button->setChecked(true);
    on_label->setFont(font);
    bgrid->addWidget(on_label, 1, 0, Qt::AlignHCenter);
    bgrid->addWidget(on_button, 1, 2, Qt::AlignHCenter);

    QLabel* off_label = new QLabel(tr("Off"), beryl);
    QRadioButton* off_button = new QRadioButton();
    off_label->setFont(font);
    bgrid->addWidget(off_label, 2, 0, Qt::AlignHCenter);
    bgrid->addWidget(off_button, 2, 2, Qt::AlignHCenter);

    sprinkler_bg->addButton(on_button);
    sprinkler_bg->addButton(off_button);

    QLabel* jalousie_label = new QLabel(tr("Jalousie: "), beryl);
    jalousie_label->setFont(font);
    jalousie_label->setAlignment(Qt::AlignHCenter);
    bgrid->addWidget(jalousie_label, 3, 1, Qt::AlignHCenter);

    QLabel* jon_label = new QLabel(tr("On"), beryl);
    QRadioButton* jon_button = new QRadioButton(beryl);
    jon_button->setChecked(true);
    jon_label->setFont(font);
    bgrid->addWidget(jon_label, 4, 0, Qt::AlignHCenter);
    bgrid->addWidget(jon_button, 4, 2, Qt::AlignHCenter);

    QLabel* joff_label = new QLabel(tr("Off"), beryl);
    QRadioButton* joff_button = new QRadioButton(beryl);
    joff_label->setFont(font);
    bgrid->addWidget(joff_label, 5, 0, Qt::AlignHCenter);
    bgrid->addWidget(joff_button, 5, 2, Qt::AlignHCenter);

    QLabel* dummy_label = new QLabel(tr(""), beryl);
    dummy_label->setMinimumSize(100, 100);
    bgrid->addWidget(dummy_label, 6, 1, Qt::AlignHCenter);
}
