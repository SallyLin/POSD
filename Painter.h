#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

#include <QGraphicsItem>
#include <QPen>
class Painter : public QGraphicsItem{
public:
    Painter();
    virtual ~Painter();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    virtual void green();

protected:
    QPen pen;
};


#endif // PAINTER_H_INCLUDED
