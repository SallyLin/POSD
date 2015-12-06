#include "SquarePainter.h"
#include <QPainter>

SquarePainter::SquarePainter(qreal sx, qreal sy, qreal length):l(length){
    this->px = sx;
    this->py = sy;
}

SquarePainter::~SquarePainter(){}

QRectF SquarePainter::boundingRect() const{
    return QRectF(px,py,l,l);
}

void SquarePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawRect(px, py, l, l);
}

