#ifndef CREATEUI_H_INCLUDED
#define CREATEUI_H_INCLUDED

#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "MainWindow.h"
#include "Model.h"

int argc = 0;
char a[2]={'0','1'};
char * argv[1]={a};

TEST (MainWindow, show_mainwindow) {
    QApplication app(argc, argv);
    Model model;
    Presentation presentation(&model);
    MainWindow window(&presentation);
    window.show();
    app.exec();
}

TEST (OneSimpleGraphics, file_rec){
    GraphicsFactory gf;
    Graphics * graphics = gf.buildGraphicsFromFile("rec.txt").at(0);

    DescriptionVisitor dv;
    graphics->accept(dv);

    std::string ans("R(-50,-50,50,150)\n");
    //ans += std::string("S(-100,-100,100)\n");
    CHECK(ans==dv.getDescription());
}

TEST (TwoSimpleGraphics, file_root1){
    GraphicsFactory gf;
    vector<Graphics *> graphics = gf.buildGraphicsFromFile("root1.txt");
    DescriptionVisitor dv;
    for(int i=0 ; i<graphics.size() ; i++){
        graphics.at(i)->accept(dv);
    }
    std::string ans("R(-50,-50,50,150)\n");
    ans += std::string("S(-100,-100,100)\n");
    CHECK(ans==dv.getDescription());
}

TEST (SimpleComposite, file_root2){
    GraphicsFactory gf;
    vector<Graphics *> graphics = gf.buildGraphicsFromFile("root2.txt");
    DescriptionVisitor dv;
    for(int i=0 ; i<graphics.size() ; i++){
        graphics.at(i)->accept(dv);
    }
    std::string ans("R(-50,-50,50,150)\n");
    ans += std::string("Comp R(-100,-100,150,150)\n");
    ans += std::string("  C(0,0,50)\n");
    ans += std::string("  S(-100,-100,100)\n");
    CHECK(ans==dv.getDescription());
}

TEST (CompositeSimple, file_root3){
    GraphicsFactory gf;
    vector<Graphics *> graphics = gf.buildGraphicsFromFile("root3.txt");
    DescriptionVisitor dv;
    for(int i=0 ; i<graphics.size() ; i++){
        graphics.at(i)->accept(dv);
    }
    std::string ans("Comp R(-100,-100,150,150)\n");
    ans += std::string("  C(0,0,50)\n");
    ans += std::string("  S(-100,-100,100)\n");
    ans += std::string("R(-50,-50,50,150)\n");
    CHECK(ans==dv.getDescription());
}

TEST (CompositeSimple, file_root4){
    GraphicsFactory gf;
    vector<Graphics *> graphics = gf.buildGraphicsFromFile("root4.txt");
    DescriptionVisitor dv;
    for(int i=0 ; i<graphics.size() ; i++){
        graphics.at(i)->accept(dv);
    }
    std::string ans("Comp R(-100,-100,150,150)\n");
    ans += std::string("  C(0,0,50)\n");
    ans += std::string("  S(-100,-100,100)\n");
    ans += std::string("Comp R(-100,-100,250,250)\n");
    ans += std::string("  S(-50,-50,200)\n");
    ans += std::string("  S(-100,-100,100)\n");
    CHECK(ans==dv.getDescription());
}
/*
TEST (TryQt, second) {
    QApplication app(argc, argv);
    QWidget * window = new QWidget;
    window->setWindowTitle("Graphics App");

    QVBoxLayout *wLayout = new QVBoxLayout(window);

    QGraphicsView *gv = new QGraphicsView;
    QGraphicsScene *gs = new QGraphicsScene(0,0,200,120);
    gv->setScene(gs);
    gs->addRect(50, 50, 100, 50);
    gs->addEllipse(60,60,60,40);
    gs->addLine(200,0,0,120);

    QPushButton *quit = new QPushButton("Quit");

    wLayout->addWidget(gv);
    wLayout->addWidget(quit);

    quit->resize(75, 30);
    quit->setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(quit, SIGNAL(clicked()), &app, SLOT(quit()));

    window->show();

    app.exec();
}*/

#endif // CREATEUI_H_INCLUDED
