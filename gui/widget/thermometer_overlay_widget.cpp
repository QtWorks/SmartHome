#include "thermometer_overlay_widget.h"
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include "qtsvgdialgauge.h"

void ThermometerOverlayWidget::okClicked()
{
    emit ok();
}

void ThermometerOverlayWidget::cancelClicked()
{
    emit cancel();
}

ThermometerOverlayWidget::ThermometerOverlayWidget(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* toplay = new QVBoxLayout(this);

    QWidget* group = new QGroupBox(tr("Thermometer"), this);
    QGridLayout* grid = new QGridLayout(group);

    toplay->addWidget(group);

    m_gauge = new QtSvgDialGauge(group);
    m_gauge->setSkin("Thermometer");
    m_gauge->setNeedleOrigin(0.456, 0.459);
    m_gauge->setMinimum(0);
    m_gauge->setMaximum(360);
    m_gauge->setStartAngle(-90);
    m_gauge->setEndAngle(90);
    m_gauge->setValue(0);
    m_gauge->setMaximumSize(200, 200);
    m_gauge->setShowOverlay(false);

    m_slider = new QSlider(Qt::Horizontal, group);
    m_slider->setRange(0, 360);
    m_slider->setValue(0);
    connect(m_slider, SIGNAL(valueChanged(int)), m_gauge, SLOT(setValue(int)));

    grid->addWidget(m_gauge, 0, 0, 1, 2, Qt::AlignHCenter);
    grid->addWidget(m_slider, 1, 0, 1, 2);

    QPushButton* ok_button = new QPushButton("OK", group);
    grid->addWidget(ok_button, 2, 0);

    QPushButton* cancel_button = new QPushButton("Cancel", group);
    grid->addWidget(cancel_button, 2, 1);

    connect(ok_button, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancelClicked()));
}

void ThermometerOverlayWidget::setValue(int value)
{
    m_slider->setValue(value);
    update();
}

qreal ThermometerOverlayWidget::value() const
{
    return 12 * qreal(m_slider->value()) / 360 + 18;
}
