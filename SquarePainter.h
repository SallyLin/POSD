#ifndef SQUAREPAINTER_H_INCLUDED
#define SQUAREPAINTER_H_INCLUDED

#include "Painter.h"

class SquarePainter : public Painter{
public:
    SquarePainter(qreal sx, qreal sy, qreal length, std::string description);
    virtual ~SquarePainter();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
private:
    qreal l;
};

#endif // SQUAREPAINTER_H_INCLUDED
