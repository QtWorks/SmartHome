#include "temperature_options_widget.h"
#include <QPainter>
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <qpushbutton.h>

void TemperatureOptionsWidget::temperatureClicked()
{
    emit temperature();
}

void TemperatureOptionsWidget::ventilatorOnClicked()
{
    emit ventilatorOn();
}

void TemperatureOptionsWidget::ventilatorOffClicked()
{
    emit ventilatorOff();
}

TemperatureOptionsWidget::TemperatureOptionsWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    QGridLayout* toplay = new QGridLayout(this);

    QGroupBox *berylsq = new QGroupBox(tr(""), this);

    toplay->addWidget(berylsq, 0, 0);
    QGridLayout *sgrid = new QGridLayout(berylsq);

    QtSvgButton* button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    QLabel* label = new QLabel(tr("Set global temperature"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 0, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 1, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(temperatureClicked()));

    button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    label = new QLabel(tr("Turn on all ventilators"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 2, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 3, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(ventilatorOnClicked()));

    button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    label = new QLabel(tr("Turn off all ventilators"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 4, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 5, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(ventilatorOffClicked()));
}

void TemperatureOptionsWidget::paintEvent(QPaintEvent*)
{
    /*
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::red);
    */
}
