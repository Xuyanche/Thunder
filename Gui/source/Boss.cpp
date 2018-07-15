#include "..\include\Boss.h"




Boss::Boss(qreal wvalue, qreal hvalue, qreal spead, QPixmap & pic, QGraphicsScene * scene, QGraphicsItem * parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, spead, pic, scene, parent)
{
	health = healthvalue;
}

Boss::~Boss()
{
}





void Boss::hitCtrl()
{
	for each (QGraphicsItem* i in collidingItems())
	{
		if (i->type() == Bullet::Type) {
			Bullet *t = (Bullet*)i;
			if (t->belong == Self) {
				damaged(t);
			}
		}
	}
}

void Boss::damaged(Bullet* t)
{
	health -= (t->damange);
	t->destroyed();
	if (health <= 0) {
		destroyed();
	}
}

void Boss::destroyed()
{
	delete this;
}

void Boss::battlemode()
{





}


