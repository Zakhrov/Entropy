#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "box.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void loop();

    void on_actionClose_triggered();

    void on_actionStart_triggered();

    void on_actionStop_triggered();

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    Phonon::AudioOutput *aout;
    QGraphicsScene *scene;
    QTimer *timer;
};

#endif // MAINWINDOW_H
