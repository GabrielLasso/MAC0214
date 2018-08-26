#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mapa.h>
#include <mapawidget.h>
#include <QDoubleSpinBox>
#include <QDialog>
#include <QFormLayout>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QAction* novoMapa;
    QAction* loadMapa;
    QAction* saveMapa;
    void mostraMapa(Mapa* map);

public slots:
    void criaMapa();
    void carregaMapa();
    void salvaMapa();

private slots:
    void on_tabWidget_tabCloseRequested(int index);
};


#endif // MAINWINDOW_H
