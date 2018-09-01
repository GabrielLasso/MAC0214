#include "instrumento.h"

Instrumento::Instrumento(qreal x, qreal y, QString filename)
{
    this->filename = filename;
    this->x = x;
    this->y = y;
}
