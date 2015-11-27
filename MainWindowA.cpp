#include "MainWindowA.h"
#include <QtWidgets>
#include <iostream>
void MainWindowA::loadFile(){
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty()){

        }

}
