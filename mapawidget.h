#ifndef MAPAWIDGET_H
#define MAPAWIDGET_H

#include <QWidget>
#include <mapa.h>
#include <QLabel>
#include <QGraphicsView>
#include <qgraphicstaikoitem.h>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

namespace Ui {
class MapaWidget;
}

class MapaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MapaWidget(QWidget *parent = nullptr, Mapa *data = nullptr);
    ~MapaWidget();
    Mapa* data;
    QLabel* titulo;
    QGraphicsView* view;
    void save(QString filename);
    qreal scale;
    QList<Instrumento> getTaikos();

private slots:
    void on_add_okedo_clicked();
    void on_add_shime_clicked();
    void on_zoom_in_clicked();
    void on_zoom_out_clicked();

private:
    Ui::MapaWidget *ui;
    void createScene();
    void addInstrument(QString name);
    void updateScene(QList<Instrumento> taikos);
    QGraphicsScene *scene;
};

#endif // MAPAWIDGET_H
