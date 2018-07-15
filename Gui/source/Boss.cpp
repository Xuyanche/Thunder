#include "..\include\Boss.h"




Boss::Boss(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, speed, pic, scene, parent)
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
			if (t->belong ==Friend ) {
				damaged(t);
			}
		}
	}
}

void Boss::damaged(Bullet* t)
{
	health -= (t->damage);
	t->destroy();
	if (health <= 0) {
		destroy();
	}
}

void Boss::destroy()
{
	deleteLater();
}

void Boss::Attack()
{
	int ShootAngle;
	BulletManager BM;
	for (ShootAngle = angle; ShootAngle <= 180; ShootAngle += 36) {
		BM.createBullet(Ordinary_Enemy, ptrtoscene, 360 - ShootAngle);
	}
	angle += 10;
	if (angle >= 36)
		angle -= 36;
}


void Boss::BattleMode()
{
	while (health > 0) {
		Attack();
		_sleep(500);
	}

}