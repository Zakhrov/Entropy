#include "box.h"

Box::Box()
{

    angle=(qrand()%360);
    setRotation(angle);
    speed=20;
    int startx=0;
    int starty=0;

    if((qrand() % 1))
    {
        startx=(qrand() % 200);
        starty=(qrand() % 200);

    }
    else
    {
        startx=(qrand() % -100);
        starty=(qrand() % -100);
    }
    setPos(mapToParent(startx,starty));
}

QRectF Box::boundingRect() const
{
    return QRect(0,0,40,40);
}

void Box::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect=boundingRect();
    QBrush brush(Qt::white);
    if(scene()->collidingItems(this).isEmpty())
    {
        brush.setColor(Qt::white);
    }
    else
    {
        brush.setColor(Qt::red);
        DoCol();
    }
    int txtspeed=speed;
    QFont sansFont("Helvetica [Cronyx]", 14);
    QString txt=QString::number(txtspeed);
    painter->fillRect(rect,brush);
    painter->drawRect(rect);
    painter->setFont(sansFont);
    painter->drawText(rect,Qt::AlignCenter,txt);
}
void Box::advance(int phase)
{
    if(!phase)
        return ;
    //QPointF loc=this->pos();
    setPos(mapToParent(0,-(speed)));

}

void Box::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    speed=speed+1;
    QGraphicsItem::mousePressEvent(event);
}

void Box::DoCol()
{
    if((qrand() %1))
    {
        setRotation(rotation()+ 180+ (qrand() % 10));
    }
    else
    {
        setRotation(rotation()+ 180+ (qrand() % -10));

    }
    QPointF newpoint=mapToParent(-(boundingRect().width()),-(boundingRect().width() +10));
    if(!scene()->sceneRect().contains(newpoint))
    {
        newpoint=mapToParent(0,0);
        setPos(newpoint);
    }
    else
    {
        setPos(newpoint);
    }
}
