#include "instrumento.h"

Instrumento::Instrumento(qreal x, qreal y, qreal angle, QString filename)
{
    this->filename = filename;
    this->x = x;
    this->y = y;
    this->angle = angle;
}
