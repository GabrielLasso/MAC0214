#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QGraphicsView>
#include <QPainter>
#include <instrumento.h>
#include <QList>
#include <QTextStream>
#include <QString>

class Mapa
{
public:
    explicit Mapa(double height = 0, double width = 0, QString titulo = "",QString equipe = "", QString cidade = "", QList<Instrumento>* taikos = new QList<Instrumento>);
    double height, width;
    QList<Instrumento>* taikos;
    QString titulo;
    QString equipe;
    QString cidade;
    static Mapa* carrega_mapa(QString file);

signals:

private:

};

#endif // MAPA_H
