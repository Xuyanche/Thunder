#pragma once

#include "include/flyingObject.h"
#include "include/BulletManager.h"

class Boss :public FlyingObject
{
public:
	Boss();
	Boss(qreal wvalue, qreal hvalue, qreal spead, QPixmap &pic, QGraphicsScene *scene, QGraphicsItem* parent, int healthvalue);
	~Boss();

	void hitCtrl();
	void damaged(Bullet* t);
	void destroyed();

	void battlemode();

private:
	int health;


};