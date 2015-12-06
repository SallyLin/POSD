#include "CirclePainter.h"
#include <QPainter>

CirclePainter::CirclePainter(qreal cx, qreal cy, qreal radius):r(radius){
    this->px = cx;
    this->py = cy;
}

CirclePainter::~CirclePainter(){}

QRectF CirclePainter::boundingRect() const{
    return QRectF(px-r,py-r,2*r,2*r);
}

void CirclePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawEllipse(QPointF(px,py), r, r);
}
