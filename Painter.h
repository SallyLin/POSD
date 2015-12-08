#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED

//#include <QGraphicsItem>
#include <QGraphicsItemGroup>
#include <QPen>
#include <vector>
using namespace std;

class MainWindow;
class Painter : public QGraphicsItemGroup{
public:
    Painter();
    virtual ~Painter();
    qreal px, py;
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void setWindow(MainWindow *window);
    void addChild(Painter* child);
    vector<Painter*> getChildren();
    std::string description();
    void setDescription(std::string content);

    //virtual method
    void green();
protected:
    QPen pen;
    MainWindow *w;
    std::string des;
    vector<Painter*> children;
};


#endif // PAINTER_H_INCLUDED
