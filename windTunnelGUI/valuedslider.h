#ifndef VALUEDSLIDER_H
#define VALUEDSLIDER_H

#include <QSlider>
#include <QtGui>

class ValuedSlider : public QSlider {
    Q_OBJECT;

public:
    ValuedSlider(QWidget *parent=nullptr) :
        QSlider(parent){};
    ValuedSlider(Qt::Orientation orientation, QWidget *parent=nullptr) :
        QSlider(orientation, parent){};

private:
    void paintEvent(QPaintEvent *event);

};



#endif // VALUEDSLIDER_H
