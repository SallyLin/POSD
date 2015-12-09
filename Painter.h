#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

//#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <vector>
using namespace std;

class Presentation;
class Painter : public QGraphicsItemGroup{
public:
    Painter();
    virtual ~Painter();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void setPresentation(Presentation *presentation);
    void addChild(Painter* child);
    vector<Painter*> getChildren();
    std::string description();
    void setDescription(std::string content);
    void green();

    //event
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
protected:
    qreal px, py;
    qreal pre_x, pre_y;
    QPointF dragStart;
    QPointF location;
    QPen pen;
    Presentation *p;
    std::string des;
    vector<Painter*> children;
    int _gridSpace;
};


#endif // PAINTER_H_INCLUDED
