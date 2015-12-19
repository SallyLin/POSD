#ifndef MAINWINDOW1_H_INCLUDED
#define MAINWINDOW1_H_INCLUDED
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QMenu>
#include <QAction>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Presentation.h"

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(Presentation* presentation);
    ~MainWindow();
    void graphicPointChange(int del_x, int del_y);
    void setDrag(bool flag);
    void setSelectedGraphicDescription(string description);
    void setSelectedGraphic(string description);
    void setSelectedGraphicByMousePoint(int x, int y);

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
    QAction *omitAct;
    QAction *groupAct;
    QAction *ungroupAct;
    QAction *newFileAct;
    QAction *upperLayerAct;
    QAction *lowerLayerAct;
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
    void changeActionStatus();
    Presentation* p;

private slots:
    void loadFile();
    void saveFile();
    void aboutDeveloper();
    void createSquare();
    void createCircle();
    void createRectangle();
    void undo();
    void redo();
    void omit();
    void group();
    void ungroup();
    void newFile();
    void moveUpperLayer();
    void moveLowerLayer();
};


#endif // MAINWINDOW1_H_INCLUDED
