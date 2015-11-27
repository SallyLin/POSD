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
    Model* model = new Model();
    MainWindow window(model);
    window.show();
    app.exec();
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
