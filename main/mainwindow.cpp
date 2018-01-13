#include "mainwindow.h"
#include "preprocessing.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
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

void MainWindow::on_buttonAdd_clicked()     //showing image in the view port
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Open Signature file"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    QImage image(fileName);

    PreProcessing* preProcessing = new PreProcessing();
    image = preProcessing->convertToGrayScale(image); //converting To GrayScale
    image = preProcessing->noiseReduction(image);       //noise Reduction


    QPixmap pix;
    pix.convertFromImage(image,Qt::AutoColor);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->imageViewSignature->setScene(scene);
    scene->addPixmap(pix);
    ui->imageViewSignature->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    qInfo("Image shown in the view port!");
}

void MainWindow::on_buttonVerify_clicked()
{
    QMessageBox::information(this,"Error","The provided signature do not match with any person in the database!");
    //TODO adding the algorithm to search data on the database.
}
