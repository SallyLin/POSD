#include "MainWindow.moc"
#include <QtWidgets>
#include <iostream>
#include <QMessageBox>


MainWindow::MainWindow(Model* model){
    widget = new QWidget;
    this->setWindowTitle("Graphics Editor");
    setCentralWidget(widget);
    graphicsView = new QGraphicsView(widget);
    QVBoxLayout *layout = new QVBoxLayout;
    scene = new QGraphicsScene();
    graphicsView->setScene(scene);
    layout->setMargin(0);
    layout->addWidget(graphicsView);
    widget->setLayout(layout);
    createAction();
    createMenus();
    createToolBars();
    setMinimumSize(1000, 700);

    this->model = model;
}

void MainWindow::createAction(){
    loadFileAct = new QAction(QIcon("images/open.png"),tr("&Load File"), this);
    loadFileAct->setShortcuts(QKeySequence::Open);
    connect(loadFileAct, SIGNAL(triggered()), this, SLOT(loadFile()));

    saveFileAct = new QAction(QIcon("images/save.png"),tr("&Save File"), this);
    saveFileAct->setShortcuts(QKeySequence::Save);
    connect(saveFileAct, SIGNAL(triggered()), this, SLOT(saveFile()));

    aboutDeveloperAct = new QAction(tr("&About Developer"), this);
    connect(aboutDeveloperAct, SIGNAL(triggered()), this, SLOT(aboutDeveloper()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(loadFileAct);
    fileMenu->addAction(saveFileAct);

    aboutMenu = menuBar()->addMenu(tr("&About"));
    aboutMenu->addAction(aboutDeveloperAct);
}

void MainWindow::createToolBars(){
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(loadFileAct);
    fileToolBar->addAction(saveFileAct);
}

void MainWindow::loadFile(){
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()){
        scene->clear();
        loadFile(fileName);
    }

}

void MainWindow::loadFile(QString fileName){
    try{
        model->loadFile(fileName.toStdString());
        QMessageBox::information(this, tr("Success"), tr("Success"));
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
        string descriptions = model->getAllDescription();

        writeFile(files.at(0), QString::fromStdString(descriptions));
	}catch(string e){
        QMessageBox::information(this, tr("Warning"), tr(e.c_str()));
	}

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
    vector<Painter*> shapes = model->getShapes();
    for (auto s:shapes){
        scene->addItem(s);
    }

        scene->update();
}
