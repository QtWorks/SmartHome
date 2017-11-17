#include "lighting_overlay_widget.h"
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include "qtsvgdialgauge.h"

void LightingOverlayWidget::okClicked()
{
    emit ok();
}

void LightingOverlayWidget::cancelClicked()
{
    emit cancel();
}

LightingOverlayWidget::LightingOverlayWidget(QWidget* parent) : QWidget(parent)
{    
    QVBoxLayout* toplay = new QVBoxLayout(this);

    QWidget* group = new QGroupBox(tr("Lighting"), this);
    QGridLayout* grid = new QGridLayout(group);

    toplay->addWidget(group);

    m_slider = new QSlider(Qt::Horizontal, group);
    m_slider->setMinimumHeight(28);
    m_slider->setMinimumWidth(280);
    m_slider->setValue(0);
    QString css = "QSlider::groove:horizontal {"
                  "  border: qlineargradient(x1:0, y1:0, x2:1, y2:1, "
                  "    stop:0 #B1B1B1, stop:1 #000000);"
                  "}"
                  "QSlider::handle:horizontal {"
                  "  background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                  "    stop:0 #DFDFDF, stop: 0.5 #7E7E7E, stop:1 #BCBCBC);"
                  "  border: 2px solid #709E10;"
                  "  border-radius: 3px;"
                  "  width: 30px;"
                  "  height: 30px;"
                  "} "
                  "QSlider::sub-page:horizontal {"
                  "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
                  "    stop: 0 #C3E0CC, stop: 0.5 #7FB605, stop:1 #D8F000);"
                  "}"
                  "QSlider::add-page:horizontal {"
                  "  background: qlineargradient(x1:0, y1:0, x2:1, y2:0, "
                  "    stop: 0 #CCD5CC, stop: 0.5 #435A12, stop:1 #5C6700);"
                  "}"
                  "QSlider::handle:pressed {"
                  "  background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                  "    stop:0 #DFDFDF, stop: 0.5 #7E7E7E, stop:1 #BCBCBC);"
                  "  border: 2px solid #D0F201;"
                  "  border-radius: 3px;"
                  "}";

    m_slider->setStyleSheet(css);
    grid->addWidget(m_slider, 0, 0, 2, 2, Qt::AlignHCenter);

    QPushButton* ok_button = new QPushButton("OK", group);
    ok_button->setMinimumSize(80, 20);
    grid->addWidget(ok_button, 2, 0);

    QPushButton* cancel_button = new QPushButton("Cancel", group);
    cancel_button->setMinimumSize(80, 20);
    grid->addWidget(cancel_button, 2, 1);

    connect(ok_button, SIGNAL(clicked()), this, SLOT(okClicked()));
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancelClicked()));
}

void LightingOverlayWidget::setValue(int value)
{
    m_slider->setValue(value);
    update();
}

int LightingOverlayWidget::value() const
{
    return m_slider->value();
}
