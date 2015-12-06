#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

#include <QGraphicsItem>
#include <QPen>

class MainWindow;
class Painter : public QGraphicsItem{
public:
    Painter();
    virtual ~Painter();

    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    virtual void green();
    void setWindow(MainWindow *window);

protected:
    QPen pen;
    qreal px, py;
    MainWindow *w;
};


#endif // PAINTER_H_INCLUDED
