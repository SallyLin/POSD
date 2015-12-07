#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

//#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QPen>

class MainWindow;
class Painter : public QGraphicsItemGroup{
public:
    Painter();
    virtual ~Painter();
    qreal px, py;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void setWindow(MainWindow *window);

    //virtual method
    virtual void green();
protected:
    QPen pen;

    MainWindow *w;
};


#endif // PAINTER_H_INCLUDED
