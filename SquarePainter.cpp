#include "SquarePainter.h"
#include <QPainter>
#include <iostream>

SquarePainter::SquarePainter(qreal sx, qreal sy, qreal length, std::string description)
:Painter(), l(length){
    //this->setPos(sx, sy);
    this->px = sx;
    this->py = sy;
    this->des = description;
}

SquarePainter::~SquarePainter(){}

QRectF SquarePainter::boundingRect() const{
    return QRectF(px,py,l,l);
    //return QRectF(x(),y(),l,l);
}

void SquarePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    painter->drawRect(px, py, l, l);
    //std::cout << "(x, y) = (" << x() << ", " << y() << endl;
    //painter->drawRect(x(), y(), l, l);
}

