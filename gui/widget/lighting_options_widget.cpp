#include "lighting_options_widget.h"
#include <QPainter>
#include <QGridLayout>
#include <QGroupBox>
#include "qtsvgbutton.h"
#include <qlabel.h>
#include <qpushbutton.h>

void LightingOptionsWidget::temperatureClicked()
{
    emit lighting();
}

void LightingOptionsWidget::ventilatorOnClicked()
{
    emit lightingOn();
}

void LightingOptionsWidget::ventilatorOffClicked()
{
    emit lightingOff();
}

LightingOptionsWidget::LightingOptionsWidget(QWidget* parent, QSize base_size) : ScalableWidget(parent, base_size)
{
    QGridLayout* toplay = new QGridLayout(this);

    QGroupBox *berylsq = new QGroupBox(tr(""), this);

    toplay->addWidget(berylsq, 0, 0);
    QGridLayout *sgrid = new QGridLayout(berylsq);

    QtSvgButton* button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    QLabel* label = new QLabel(tr("Set global brightness"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 0, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 1, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(temperatureClicked()));

    button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    label = new QLabel(tr("Turn on all lights"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 2, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 3, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(ventilatorOnClicked()));

    button = new QtSvgButton(berylsq);
    button->setSkin("BerylSquare");
    label = new QLabel(tr("Turn off all lights"), berylsq);
    label->setAlignment(Qt::AlignHCenter);
    sgrid->addWidget(button, 4, 0, Qt::AlignHCenter);
    sgrid->addWidget(label, 5, 0, Qt::AlignHCenter);

    connect(button, SIGNAL(clicked()), this, SLOT(ventilatorOffClicked()));
}

void LightingOptionsWidget::paintEvent(QPaintEvent*)
{
    /*
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.fillRect(rect(), Qt::red);
    */
}
