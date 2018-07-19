#include "..\include\Boss.h"




Boss::Boss(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, speed, pic, scene, parent)
{
	health = healthvalue;
	angle = 0;
	step = 0;
}

Boss::~Boss()
{
}





void Boss::hitCtrl()
{
	FlyingObject *t;
	for each (QGraphicsItem* i in collidingItems())
	{
		if (i->type() == FlyingObject::Type) {
			t = static_cast<FlyingObject*>(i);
			if (t->getType()==Type_Bullet) {
				damaged(static_cast<Bullet*>(t));
			}
		}
	}
	return;
}

void Boss::damaged(Bullet *t)
{
	if (t->belong != Enemy)
		return;
	health -= (t->damage);
	t->Bullet::destroy();
	if (health <= 0) {
		destroy();
	}
	return;
}

void Boss::destroy()
{
	setVisible(false);
	deleteLater();
}

void Boss::Attack(QGraphicsScene *ptrsence)
{
	int ShootAngle;
	Bullet* b = NULL;
	for (ShootAngle =angle; ShootAngle <= 180; ShootAngle += 36) {
		b=createBullet(Ordinary_Enemy, ptrsence,  ShootAngle*3.1415926/180);
		b->setPos(this->scenePos());
	}
	angle += 5;
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
	return;
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
	painter->drawPixmap(-0.5*width, -0.5*height, pixmaps.at(0));
	//painter->setPen(QColor("red"));
	//painter->drawEllipse(-35, -35, 70, 70);
	return;
}

flyingObjectType Boss::getType() {
	return Type_Boss;
}

Boss* createBoss(QGraphicsScene* scene, gamenumber game) {
	Boss* newBoss = NULL;
	QPixmaps tmp;
	tmp.append(QPixmap(Enemybullet_Ordinary_Image));
	newBoss = new Boss(100, 100, 2, tmp, scene, 0, 1000);

	return newBoss;
}
int Boss::gethealth()
{
	return this->health;
}