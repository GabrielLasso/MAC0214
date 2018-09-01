#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <QPixmap>

class Instrumento
{
public:
    Instrumento(double x=0, double y=0, QString filename="");
    qreal x, y;
    QString filename;
};

#endif // INSTRUMENTO_H
