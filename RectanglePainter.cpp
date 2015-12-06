#include "RectanglePainter.h"
#include <QPainter>

RectanglePainter::RectanglePainter(qreal rx, qreal ry, qreal length, qreal width)
    :l(length), w(width){
    this->setX(rx);
    this->setY(ry);
}

RectanglePainter::~RectanglePainter(){}

QRectF RectanglePainter::boundingRect() const{
    return QRectF(x(),y(),l,w);
}

void RectanglePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawRect(x(), y(), l, w);
}

