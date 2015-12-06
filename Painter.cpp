#include "Painter.h"
#include "MainWindow.h"
Painter::Painter(){ pen.setColor("blue");}

Painter::~Painter(){}

QRectF Painter::boundingRect() const{
    return QRectF(0,0,0,0);
}

void Painter::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget){}

void Painter::green(){
    pen.setColor("green");
    update();
}

void Painter::setWindow(MainWindow *window){
    this->w = window;
}
