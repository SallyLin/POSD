#ifndef CIRCLEPAINTER_H_INCLUDED
#define CIRCLEPAINTER_H_INCLUDED

#include "Painter.h"
class CirclePainter : public Painter{
public:
    CirclePainter(qreal cx, qreal cy, qreal radius, std::string description);
    virtual ~CirclePainter();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QPainterPath shape();
private:
    qreal r;
};

#endif // CIRCLEPAINTER_H_INCLUDED
