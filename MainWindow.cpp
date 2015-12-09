#include "MainWindow.moc"
#include <QtWidgets>
#include <iostream>
#include <sstream>
#include <QMessageBox>
#include <QList>
#include "RectanglePainter.h"
#include <vector>
#include <string>
using namespace std;

MainWindow::MainWindow(Presentation* presentation):p(presentation){
    widget = new QWidget;
    this->setWindowTitle("Graphics Editor");
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);
    graphicsView->setMouseTracking(true);
    graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    QVBoxLayout *layout = new QVBoxLayout;
    scene = new QGraphicsScene();
    scene->setSceneRect(-500, -400, 900, 800);
    graphicsView->setScene(scene);
    graphicsView->setSceneRect(-450, -400, 900, 800);
    graphicsView->resize(900, 800);
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
    createAction();
    createMenus();
    createToolBars();
    setMinimumSize(900, 800);

}

void MainWindow::createAction(){
    loadFileAct = new QAction(QIcon("images/open.png"),tr("&Load File"), this);
    loadFileAct->setShortcuts(QKeySequence::Open);
    connect(loadFileAct, SIGNAL(triggered()), this, SLOT(loadFile()));

    saveFileAct = new QAction(QIcon("images/save.png"),tr("&Save File"), this);
    saveFileAct->setShortcuts(QKeySequence::Save);
    connect(saveFileAct, SIGNAL(triggered()), this, SLOT(saveFile()));

    squareAct = new QAction(QIcon("images/square.png"),tr("Create Square"), this);
    connect(squareAct, SIGNAL(triggered()), this, SLOT(createSquare()));

    circleAct = new QAction(QIcon("images/circle.png"),tr("Create Circle"), this);
    connect(circleAct, SIGNAL(triggered()), this, SLOT(createCircle()));

    rectangleAct = new QAction(QIcon("images/rectangle.png"),tr("Create Rectangle"), this);
    connect(rectangleAct, SIGNAL(triggered()), this, SLOT(createRectangle()));

    aboutDeveloperAct = new QAction(tr("&About Developer"), this);
    connect(aboutDeveloperAct, SIGNAL(triggered()), this, SLOT(aboutDeveloper()));

    undoAct = new QAction(QIcon("images/undo.png"), tr("Undo"), this);
    undoAct->setShortcut(QKeySequence::Undo);
    connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));

    redoAct = new QAction(QIcon("images/redo.png"), tr("Redo"), this);
    redoAct->setShortcut(QKeySequence::Redo);
    connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));

    omitAct = new QAction(QIcon("images/delete.png"), tr("Redo"), this);
    omitAct->setShortcut(QKeySequence::Redo);
    connect(omitAct, SIGNAL(triggered()), this, SLOT(omit()));

    groupAct = new QAction(QIcon("images/group.png"), tr("Group"), this);
    connect(groupAct, SIGNAL(triggered()), this, SLOT(group()));

    ungroupAct = new QAction(QIcon("images/ungroup.png"), tr("Ungroup"), this);
    connect(ungroupAct, SIGNAL(triggered()), this, SLOT(ungroup()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(loadFileAct);
    fileMenu->addAction(saveFileAct);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutDeveloperAct);

    shapeMenu = menuBar()->addMenu(tr("&Create Shape"));
    shapeMenu->addAction(squareAct);
    shapeMenu->addAction(circleAct);
    shapeMenu->addAction(rectangleAct);
}

void MainWindow::createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(loadFileAct);
    fileToolBar->addAction(saveFileAct);

    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(undoAct);
    editToolBar->addAction(redoAct);
    editToolBar->addAction(omitAct);
    editToolBar->addAction(squareAct);
    editToolBar->addAction(circleAct);
    editToolBar->addAction(rectangleAct);
    editToolBar->addAction(groupAct);
    editToolBar->addAction(ungroupAct);
}

void MainWindow::loadFile(){
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
        scene->clear();
        loadFile(fileName);
    }
    p->clearAll();
}

void MainWindow::loadFile(QString fileName){
    try{
        p->loadFile(fileName.toStdString());
        drawShapes();
    }catch(string e){
        QMessageBox::information(this, tr("Warning"), tr(e.c_str()));
    }
}


void MainWindow::saveFile(){
    try{
        QFileDialog dialog(this);
        dialog.setWindowModality(Qt::WindowModal);
        dialog.setAcceptMode(QFileDialog::AcceptSave);
        QStringList files;
        if (dialog.exec())
            files = dialog.selectedFiles();
        else
            return;
        string descriptions = p->getAllDescription();

        writeFile(files.at(0), QString::fromStdString(descriptions));
	}catch(string e){
        QMessageBox::information(this, tr("Warning"), tr(e.c_str()));
	}
    p->clearAll();
	QMessageBox msgbox;
    std::string message("Save!!\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();

}

void MainWindow::writeFile(QString fileName, QString data){

    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        throw "Cannot write file " + fileName;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
	out << data;
    statusBar()->showMessage(tr("File saved"), 2000);
    QApplication::setOverrideCursor(Qt::ArrowCursor);
}

void MainWindow::aboutDeveloper(){
    QMessageBox msgbox;
    std::string message("103598029\n");
    message += std::string("Author:Sally Lin\n");
    QString qstr = QString::fromStdString(message);
    msgbox.setText(qstr);
    msgbox.exec();
}

void MainWindow::drawShapes(){
    //cout << "update scene" << endl;
    scene->clear();
    vector<Painter*> shapes = p->getShapes();
    for (auto s:shapes){
        s->setWindow(this);
        scene->addItem(s);
    }
    scene->update();
}

void MainWindow::createSquare(){
    p->createSquare();
    drawShapes();
}

void MainWindow::createCircle(){
    p->createCircle();
    drawShapes();
}

void MainWindow::createRectangle(){
    p->createRectangle();
    drawShapes();
}

void MainWindow::undo(){
    try{
        p->undo();
        drawShapes();
    }catch(string e){
        QMessageBox::information(this, tr("Warning"), tr(e.c_str()));
	}
}

void MainWindow::redo(){
    try{
        p->redo();
        drawShapes();
    }catch(string e){
        QMessageBox::information(this, tr("Warning"), tr(e.c_str()));
	}
}

void MainWindow::omit(){
    p->omit();
    drawShapes();
    //Original
    /*
    QList<QGraphicsItem*> selectedList = scene->selectedItems();
    Painter* group = static_cast<Painter*>(selectedList.front());
    string description = group->description();
    p->omit(description);
    scene->removeItem(selectedList.back());
    scene->update();*/
}

void MainWindow::group(){
    QList<QGraphicsItem*> selectedList = scene->selectedItems();
    if(selectedList.size() > 1){
        vector<string> descriptions;
        for(auto item : selectedList){
            Painter* painter = static_cast<Painter*> (item);
            scene->removeItem(item);
            descriptions.push_back(painter->description());
        }
        p->group(descriptions);
        /*Painter* group = p->getNewGroup();
        group->setPresentation(p);
        scene->addItem(group);
        scene->update();*/
        drawShapes();
    }
}

void MainWindow::ungroup(){
    p->ungroup();
    drawShapes();
    /*
    QList<QGraphicsItem*> selectedList = scene->selectedItems();
    Painter* group = static_cast<Painter*>(selectedList.front());
    vector<Painter*> children = group->getChildren();
    if(!children.empty()){
        p->ungroup(group->description());
        scene->removeItem(group);

        for(auto child : children){
            scene->addItem(child);
        }
        scene->update();
    }*/
}

void MainWindow::graphicPointChange(int del_x, int del_y){
    p->graphicPointChange(del_x, del_y);
    drawShapes();
}

void MainWindow::setDrag(bool flag){
    p->setDrag(flag);
}

void MainWindow::setSelectedGraphicDescription(string description){
    p->setSelectedGraphicDescription(description);
}
