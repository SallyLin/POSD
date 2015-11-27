#include "SquarePainter.h"
#include <QPainter>

SquarePainter::SquarePainter(qreal sx, qreal sy, qreal length): x(sx), y(sy), l(length){}

SquarePainter::~SquarePainter(){}

QRectF SquarePainter::boundingRect() const{
    return QRectF(x,y,l,l);
}

void SquarePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawRect(x, y, l, l);
}

