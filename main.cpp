/*
 *
 *  Author: Luiz Felipe Maciel Correia
 *  E-mail: y9luiz@hotmail.com
 *  github: y9luiz
 *  facebook: https://www.facebook.com/luizfelipe.macielcorreia.5
 *  linkedin: https://www.linkedin.com/in/luiz-correia-78a346168
 */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
