/*
 *
 *  Author: Luiz Felipe Maciel Correia
 *  E-mail: y9luiz@hotmail.com
 *  github: y9luiz
 *  facebook: https://www.facebook.com/luizfelipe.macielcorreia.5
 *  linkedin: https://www.linkedin.com/in/luiz-correia-78a346168
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    timer->start(40);
    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}
QImage AVFrame2QImage(AVFrame * frameRGB){
    QImage img(1280,960,QImage::Format_RGB888);
    //setting QImage from frameRGB
    for( int y = 0; y < 960; ++y )
       memcpy( img.scanLine(y), frameRGB->data[0]+y * frameRGB->linesize[0], 3840 );

    return img;
}
void MainWindow::on_pushButton_clicked()
{
    if(! ui->textEdit->toPlainText().isEmpty()){
        dec.set_ip(ui->textEdit->toPlainText());
        dec.init();
        connect(timer,SIGNAL(timeout()),this, SLOT(get_image_from_decoder()));
        connect(this,&MainWindow::update_label,this,&MainWindow::set_img);

    }
}

void MainWindow::set_img(QPixmap pix){
    ui->label_img->setPixmap(pix);

}
void MainWindow::get_image_from_decoder()
{
    if(dec.get_frame())
    {
        QImage img = AVFrame2QImage(dec.rgb_frame);
        QPixmap pix;
        pix.convertFromImage(img,Qt::ColorOnly);
        emit(update_label(pix));

    }
    dec.clear();

}

void MainWindow::on_pushButton_2_clicked()
{

     close();

}
