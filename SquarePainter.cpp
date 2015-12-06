#include "SquarePainter.h"
#include <QPainter>

SquarePainter::SquarePainter(qreal sx, qreal sy, qreal length):l(length){
    this->setX(sx);
    this->setY(sy);
}

SquarePainter::~SquarePainter(){}

QRectF SquarePainter::boundingRect() const{
    return QRectF(x(),y(),l,l);
}

void SquarePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawRect(x(), y(), l, l);
}

