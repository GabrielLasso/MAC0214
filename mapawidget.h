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
#include <QLineEdit>
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
    QLineEdit* titulo;
    QLineEdit* equipe;
    QLineEdit* cidade;
    MapaView* view;
    void save(QString filename);
    QList<Instrumento> getTaikos();
    QListWidget* instrumentos;

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_add_taiko_clicked();

    void on_musicNameLineEdit_textEdited(const QString &arg1);

    void on_equipeLineEdit_textEdited(const QString &arg1);

    void on_cidadeLineEdit_textEdited(const QString &arg1);

private:
    Ui::MapaWidget *ui;
    void createScene();
    void loadList();
    void addInstrument(QString name, qreal x, qreal y);
    void updateScene(QList<Instrumento> taikos);
    MapaScene *scene;
};

#endif // MAPAWIDGET_H
