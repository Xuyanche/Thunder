#include "..\include\playerfighter.h"

PlayerFighter::PlayerFighter(qreal wvalue, qreal hvalue, qreal speed, QPixmaps & pic, QGraphicsScene * scene, QGraphicsItem * parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, speed, pic, scene, parent)
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
			if (t->belong != Friend)	
				damaged(t);
		}
	}
}

void PlayerFighter::damaged(Bullet* t)
{
	health -= (t->damage);
	t->destroyed();
	if (health <= 0) {
		destroyed();
	}
}

void PlayerFighter::destroyed()
{
	deleteLater();
}