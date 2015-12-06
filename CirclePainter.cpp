#include "CirclePainter.h"
#include <QPainter>

CirclePainter::CirclePainter(qreal cx, qreal cy, qreal radius):r(radius){
    this->setX(cx);
    this->setY(cy);
}

CirclePainter::~CirclePainter(){}

QRectF CirclePainter::boundingRect() const{
    return QRectF(x()-r,y()-r,2*r,2*r);
}

void CirclePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawEllipse(QPointF(x(),y()), r, r);
}
