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

void Boss::damaged(Bullet *t)
{
	health -= (t->damage);
	t->Bullet::destroy();
	if (health <= 0) {
		destroy();
	}
}

void Boss::destroy()
{
	deleteLater();
}

void Boss::Attack(QGraphicsScene *ptrsence)
{
	int ShootAngle;
	 
	for (ShootAngle = angle; ShootAngle <= 180; ShootAngle += 36) {
		ObjectManager::createBullet(Ordinary_Enemy, ptrsence, (360 - ShootAngle)/3.14159);
	}
	angle += 10;
	if (angle >= 36)
		angle -= 36;
}

void Boss::advance(int) {
	step++;
	if (step%ACTION_FREQUENCY == 0)
		Attack(scene());
	if (step >= 100 * ACTION_FREQUENCY)
		step = 0;
	hitCtrl();
}


QRectF Boss::boundingRect() const {
	return pixmaps.at(0).rect();
}

QPainterPath Boss::shape() const {
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void Boss::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, pixmaps.at(0));
	return;
}
