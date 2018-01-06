#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPixmap>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonAdd_clicked()
{
    try{
        QPixmap pix("C:\\Users\\susha\\Qt Projects\\major-project\\database\\test-data\\upload.png");
        QGraphicsScene *scene = new QGraphicsScene(this);
        ui->imageViewSignature->setScene(scene);
        scene->addPixmap(pix);
        ui->imageViewSignature->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
        qInfo("Image shown in the view port!");
    }catch(...){
        qInfo("ERROR Detected");
    }
}
