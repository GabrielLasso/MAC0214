#include "mapa.h"
#include "ui_mapa.h"

Mapa::Mapa(QWidget *parent, double height, double width, QList<Instrumento>* taikos) : QWidget(parent)
{
    this->taikos = taikos;
    this->height = height;
    this->width = width;
}


void Mapa::paintEvent(QPaintEvent *) {
    QPainter p(this);
    int side=50;
    int i,j;
    for (i=0;i<=height;i++){
        for(j=0;j<=width;j++){
            p.drawLine(j*side,0,j*side,int(height*side));
        }
        p.drawLine(0,i*side,int(width*side),i*side);
    }
    for (Instrumento taiko : *taikos) {
        p.drawRect(int(side*taiko.x-10), int(side*taiko.y-10),20,20);
    }
}

Mapa* Mapa::carrega_mapa(QString file_name) {
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly)) {
        return nullptr;
    }

    double height, width, x, y;
    QTextStream in(&file);
    QString line = in.readLine();
    QStringList fields = line.split(",");
    height = fields[0].toDouble();
    width = fields[1].toDouble();
    QList<Instrumento> *taikos = new QList<Instrumento>;
    while(!in.atEnd()) {
        line = in.readLine();
        fields = line.split(",");
        x = fields[0].toDouble();
        y = fields[1].toDouble();
        taikos->append(Instrumento(x,y));
    }

    file.close();
    return new Mapa(nullptr, height, width, taikos);
}
