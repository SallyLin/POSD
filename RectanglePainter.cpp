#include "RectanglePainter.h"
#include <QPainter>

RectanglePainter::RectanglePainter(qreal rx, qreal ry, qreal length, qreal width, std::string description)
    :Painter(), l(length), w(width){
    this->px = rx;
    this->py = ry;
    this->des = description;
}

RectanglePainter::~RectanglePainter(){}

QRectF RectanglePainter::boundingRect() const{
    return QRectF(px,py,l,w);
}

void RectanglePainter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){
    painter->setPen(pen);
    if(!isComposite){
        painter->fillRect(px, py, l, w, color);
    }
    painter->drawRect(px, py, l, w);
}

