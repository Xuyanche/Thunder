#pragma once
#include <ctime>
#include <qlist.h>
#include "flyingObject.h"
#include "bullet.h"
#include "global.h"
#include "weapon.h"

class Boss :public FlyingObject
{ 

public:
	Boss(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, int healthvalue, QList<Weapon*> weaponsValue);
	~Boss();

	void hitCtrl();
	void damaged(Bullet* t);
	void destroy();
	flyingObjectType getType();

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void Attack(QGraphicsScene *ptrsence);
	void advance(int);

private:
	int health;
	int angle;
	uint step;
	QList<Weapon*> weapons;

	friend Boss* createBoss(QGraphicsScene *scene, gamenumber game);

};