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

	void Attack();
	void BattleMode();

private:
	int health;
	int angle = 0;

};