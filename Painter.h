#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

//#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <QBrush>
#include <vector>

using namespace std;

class Presentation;
class MainWindow;
class Painter : public QGraphicsItemGroup{
public:
    Painter();
    virtual ~Painter();
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    //void setPresentation(Presentation *presentation);
    void setWindow(MainWindow* mainwindow);
    void addChild(Painter* child);
    vector<Painter*> getChildren();
    std::string description();
    void setDescription(std::string content);
    void green();
    void setPos(qreal x, qreal y);
    void selected();
    void unselected();
    void checkSelected(vector<string> descriptions);

    //event
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
protected:
    qreal px, py;
    QPointF prePoint;
    QPointF location;
    QPen pen;
    QColor color;
    Presentation *p;
    MainWindow* mw;
    std::string des;
    vector<Painter*> children;
    bool isComposite;
};


#endif // PAINTER_H_INCLUDED
