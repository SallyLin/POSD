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
    QAction *loadFileAct;
    QAction *saveFileAct;
    QAction *aboutDeveloperAct;
    QGraphicsView *graphicsView;
    QToolBar *fileToolBar;

private:
    //void createView();
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
};


#endif // MAINWINDOW1_H_INCLUDED
