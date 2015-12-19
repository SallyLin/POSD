#include "CirclePainter.h"
#include <QPainter>
#include <QPainterPath>

CirclePainter::CirclePainter(qreal cx, qreal cy, qreal radius, std::string description)
    :Painter(), r(radius){
    this->px = cx;
    this->py = cy;
    this->des = description;
}

CirclePainter::~CirclePainter(){}

QRectF CirclePainter::boundingRect() const{
    return QRectF(px-r,py-r,2*r,2*r);
}

void CirclePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setBrush(color);
    painter->setPen(pen);
    painter->drawEllipse(QPointF(px,py), r, r);
}
