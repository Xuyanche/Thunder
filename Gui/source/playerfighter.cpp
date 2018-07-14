#include "..\include\playerfighter.h"

PlayerFighter::PlayerFighter(qreal wvalue, qreal hvalue, qreal spead, QPixmap & pic, QGraphicsScene * scene, QGraphicsItem * parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, spead, pic, scene, parent)
{
	health = healthvalue;
}

PlayerFighter::~PlayerFighter()
{
}



void PlayerFighter::hitCtrl()
{
	for each (QGraphicsItem *i in collidingItems())
	{
		if (i->type() == Bullet::Type) {
			Bullet* t = (Bullet*)i;
			if (t->belong != Self)	
				damaged(t);
		}
	}
}

void PlayerFighter::damaged(Bullet* t)
{
	health -= (t->damange);
	t->destroyed();
	if (health <= 0) {
		destroyed();
	}
}

void PlayerFighter::destroyed()
{
	delete this;
}