#ifndef MAINWINDOW1_H_INCLUDED
#define MAINWINDOW1_H_INCLUDED
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Model.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(Model* model);

protected:
    QWidget *widget;
    QGraphicsScene *scene;
    QMenu *fileMenu;
    QMenu *aboutMenu;
    QMenu *shapeMenu;
    QAction *loadFileAct;
    QAction *saveFileAct;
    QAction *aboutDeveloperAct;
    QAction *squareAct;
    QAction *circleAct;
    QAction *rectangleAct;
    QAction *undoAct;
    QAction *redoAct;
    QGraphicsView *graphicsView;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;

private:
    void createAction();
    void createMenus();
    void createToolBars();
    void loadFile(QString fileName);
    void writeFile(QString fileName, QString data);
    void drawShapes();

    Model* model;

private slots:
    void loadFile();
    void saveFile();
    void aboutDeveloper();
    void createSquare();
    void createCircle();
    void createRectangle();
    void undo();
    void redo();
};


#endif // MAINWINDOW1_H_INCLUDED
