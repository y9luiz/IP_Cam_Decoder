/*
 *
 *  Author: Luiz Felipe Maciel Correia
 *  E-mail: y9luiz@hotmail.com
 *  github: y9luiz
 *  facebook: https://www.facebook.com/luizfelipe.macielcorreia.5
 *  linkedin: https://www.linkedin.com/in/luiz-correia-78a346168
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <decoder/decoder.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Decoder dec;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void get_image_from_decoder();
    void set_img(QPixmap);

    void on_pushButton_2_clicked();

private:
    QTimer* timer;


    Ui::MainWindow *ui;
signals:
    void update_label(QPixmap pix);
};
#endif // MAINWINDOW_H
