#ifndef BOX_H
#define BOX_H
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
class Box : public QGraphicsItem
{
public:
    Box();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:

    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
    qreal angle;
    qreal speed;
    void DoCol();



};

#endif // BOX_H
