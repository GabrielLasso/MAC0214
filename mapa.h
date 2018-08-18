#ifndef MAPA_H
#define MAPA_H

#include <QWidget>
#include <QGraphicsView>
#include <QPainter>
#include <instrumento.h>
#include <QList>
#include <QTextStream>

class Mapa : public QWidget
{
    Q_OBJECT
public:
    explicit Mapa(QWidget *parent = nullptr, double height = 0, double width = 0, QList<Instrumento>* taikos = new QList<Instrumento>);
    double height, width;
    QList<Instrumento>* taikos;
    static Mapa* carrega_mapa(QString file);

signals:

private:
    void paintEvent(QPaintEvent *event);

};

#endif // MAPA_H
