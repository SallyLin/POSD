#ifndef SQUAREPAINTER_H_INCLUDED
#define SQUAREPAINTER_H_INCLUDED

#include "Painter.h"

class SquarePainter : public Painter{
public:
    SquarePainter(qreal sx, qreal sy, qreal length);
    virtual ~SquarePainter();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    qreal x, y, l;
};

#endif // SQUAREPAINTER_H_INCLUDED
