#include "instrumento.h"

Instrumento::Instrumento(double x, double y, QString filename)
{
    this->filename = filename;
    this->x = x;
    this->y = y;
}
