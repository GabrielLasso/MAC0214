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
#include <QListWidget>
#include <QListWidgetItem>
#include <QDirIterator>
#include "mapascene.h"
#include "mapaview.h"

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
    MapaView* view;
    void save(QString filename);
    QList<Instrumento> getTaikos();
    QListWidget* instrumentos;

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_add_taiko_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MapaWidget *ui;
    void createScene();
    void loadList();
    void addInstrument(QString name, qreal x, qreal y);
    void updateScene(QList<Instrumento> taikos);
    MapaScene *scene;
};

#endif // MAPAWIDGET_H
