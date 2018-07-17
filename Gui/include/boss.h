#pragma once
#include <ctime>
#include "include/flyingObject.h"
#include "include/BulletManager.h"

class Boss :public FlyingObject
{
public:
	Boss();
	Boss(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent ,int healthvalue);
	~Boss();

	void hitCtrl();
	void damaged(Bullet* t);
	void destroy();

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void Attack(QGraphicsScene *ptrsence);
	void advance(int);

private:
	int health;
	int angle = 0;
	uint step = 0;
};