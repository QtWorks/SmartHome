#include "gardening_options_widget.h"
#include <QPainter>
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <qpushbutton.h>

void GardeningOptionsWidget::sprinklerOnClicked()
{
    emit sprinklerOn();
}

void GardeningOptionsWidget::sprinklerOffClicked()
{
    emit sprinklerOff();
}

GardeningOptionsWidget::GardeningOptionsWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    QGridLayout* toplay = new QGridLayout(this);

    QGroupBox *berylsq = new QGroupBox(tr(""), this);

    toplay->addWidget(berylsq, 0, 0);
    QGridLayout *sgrid = new QGridLayout(berylsq);

    QtSvgButton* button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    QLabel* label = new QLabel(tr("Turn on all sprinklers"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 2, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 3, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(sprinklerOnClicked()));

    button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    label = new QLabel(tr("Turn off all sprinklers"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 4, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 5, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(sprinklerOffClicked()));
}

