#ifndef RECTANGLEPAINTER_H_INCLUDED
#define RECTANGLEPAINTER_H_INCLUDED

#include "Painter.h"
#include <QPen>

class RectanglePainter : public Painter{
public:
    RectanglePainter(qreal rx, qreal ry, qreal length, qreal width);
    virtual ~RectanglePainter();
    void blue();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

private:
    qreal x, y, l, w;
};

#endif // RECTANGLEPAINTER_H_INCLUDED
