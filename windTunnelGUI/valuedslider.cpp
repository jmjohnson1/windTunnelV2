#include "valuedslider.h"

void ValuedSlider::paintEvent(QPaintEvent *event) {
    QSlider::paintEvent(event);

    auto round_value = std::floor(value());

    QPainter painter(this);
    painter.setPen(QPen(Qt::red));

    auto font_metrics = QFontMetrics(this->font());
    auto font_width = font_metrics.boundingRect(QString::number(round_value)).width();
    auto font_height = font_metrics.boundingRect(QString::number(round_value)).height();

    auto rect = this->geometry();
    if (this->orientation() == Qt::Horizontal) {
        auto horizontal_x_pos = rect.width() - font_width - 5;
        auto horizontal_y_pos = rect.height() * 0.75;
        painter.drawText(QPoint(horizontal_x_pos, horizontal_y_pos),
                          QString::number(round_value));
    } else if (this->orientation() == Qt::Vertical) {
        return;
    } else {
        return;
    }

    painter.drawRect(rect);
}
