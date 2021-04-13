#include "led.h"
#include <QPainter>

Led::Led(QWidget* parent) :
    QWidget(parent)
{
    // inizializzazione con valori di default
    on = true;
    lightColor = QColor(Qt::green);

    // imposta una dimensione fissa per la widget
    setFixedSize(24, 24);

    // inizializzazione dell'effetto di glow
    glowEffect = new QGraphicsDropShadowEffect(this);
    glowEffect->setBlurRadius(48);
    glowEffect->setColor(lightColor.lighter(150));
    glowEffect->setOffset(0, 0);
    glowEffect->setEnabled(false);
    setGraphicsEffect(glowEffect);
}

bool Led::isOn() const
{
    return on;
}

void Led::setOn(bool value)
{
    on = value;
    glowEffect->setEnabled(on);

    update();
}

QColor Led::getLightColor() const
{
    return lightColor;
}

void Led::setLightColor(const QColor& c)
{
    lightColor = c;
    glowEffect->setColor(c.lighter(150));

    update();
}

void Led::paintEvent(QPaintEvent* /*event*/)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing);

    QColor ledColor = (on) ? lightColor : QColor(Qt::darkGray);

    // definizione di un gradiente radiale per renderizzare il
    // colore del led e simulare una riflessione ambientale chiara sulla sua superficie
    int radius = width() / 2.0;
    QRadialGradient radialGrad(QPointF(radius, radius), radius - 1, QPointF(radius, radius / 2.0f));
    radialGrad.setColorAt(0, ledColor.lighter(300));
    radialGrad.setColorAt(0.5, ledColor);
    radialGrad.setColorAt(1, ledColor.darker(200));

    // imposta Pen per il contorno e Brush per il filling
    painter.setPen(QPen(Qt::gray, 2));
    painter.setBrush(radialGrad);

    // disegna con un'unica direttiva il contorno grigio
    // e riempie l'areaola circolare del led con il gradiente
    painter.drawEllipse(QPointF(radius, radius), radius - 1, radius - 1);
}