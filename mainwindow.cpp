#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "box.h"
#include <QFileDialog>
#include <QDesktopServices>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    med=new Phonon::MediaObject(this);
    med->setCurrentSource(Phonon::MediaSource(":/audio/Track1.mp3"));
    aout=new Phonon::AudioOutput(Phonon::MusicCategory,this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-100,-100,400,400);
    QPen mypen=QPen(Qt::black);
    QLineF TopLine(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF LeftLine(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF RightLine(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF BottomLine(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());
    scene->addLine(TopLine,mypen);
    scene->addLine(LeftLine,mypen);
    scene->addLine(RightLine,mypen);
    scene->addLine(BottomLine,mypen);

    Phonon::createPath(med,aout);
    int itemcount=20;
    for(int i=0;i<itemcount;i++)
    {
        Box *b=new Box();
        scene->addItem(b);;
    }
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(med,SIGNAL(aboutToFinish()),this,SLOT(loop()));
    med->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loop()
{
   med->setCurrentSource(Phonon::MediaSource(":/audio/Track1.mp3"));
    med->play();
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}
void MainWindow::on_actionStart_triggered()
{
    timer->start(100);
}

void MainWindow::on_actionStop_triggered()
{
     timer->stop();
}
