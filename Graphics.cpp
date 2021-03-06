#include "Graphics.h"
#include "Rectangle.h"
#include <string>
#include "AreaVisitor.h"

Rectangle Graphics:: getBoundingBox() {return Rectangle(0,0,0,0);}
void Graphics::add(Graphics *g) {throw std::string("Cannot add child");}
void Graphics::accept(GraphicsVisitor & av) {}
Graphics::Graphics(){}
Graphics::~Graphics(){}
Painter* Graphics::getPainter(){return new Painter(); }
std::string Graphics::description(){ return std::string(""); }
vector<Graphics*> Graphics::getChildren() {throw std::string("No children");}
void Graphics::changePoint(int del_x, int del_y){}
bool Graphics::isInArea(int x, int y){ return false; }
void Graphics::setChildren(vector<Graphics*> children){}
