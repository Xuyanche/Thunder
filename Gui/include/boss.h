#pragma once
#include <ctime>
#include "flyingObject.h"
#include "BulletManager.h"

class Boss :public FlyingObject
{
public:
	Boss();
	Boss(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent ,int healthvalue);
	~Boss();

	void hitCtrl();
	void damaged(Bullet* t);
	void destroy();

	void Attack(QGraphicsScene *ptrsence);
	void BattleMode();

private:
	int health;
	int angle = 0;

};