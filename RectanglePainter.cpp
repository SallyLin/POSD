#include "RectanglePainter.h"
#include <QPainter>

RectanglePainter::RectanglePainter(qreal rx, qreal ry, qreal length, qreal width)
    :Painter(), l(length), w(width){
    this->px = rx;
    this->py = ry;
}

RectanglePainter::~RectanglePainter(){}

QRectF RectanglePainter::boundingRect() const{
    return QRectF(px,py,l,w);
}

void RectanglePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawRect(px, py, l, w);
}

