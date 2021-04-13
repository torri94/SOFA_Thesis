#ifndef LED_H
#define LED_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

class Led : public QWidget
{
    Q_OBJECT
public:
    Led(QWidget* parent = 0);

    bool isOn() const;
    QColor getLightColor() const;

public slots:
    void setOn(bool value);
    void setLightColor(const QColor& c);

protected:
    virtual void paintEvent(QPaintEvent* event) override;

    bool on;
    QColor lightColor;
    QGraphicsDropShadowEffect* glowEffect;
};

#endif