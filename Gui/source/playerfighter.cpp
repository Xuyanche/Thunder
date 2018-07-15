#include "..\include\playerfighter.h"

PlayerFighter::PlayerFighter(qreal wvalue, qreal hvalue, qreal speed, QPixmaps & pic, QGraphicsScene * scene, QGraphicsItem * parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, speed, pic, scene, parent)
{
	health = healthvalue;
}

PlayerFighter::~PlayerFighter()
{
}


flyingObjectType PlayerFighter::getType() {
	return flyingObjectType::Type_Player;
}

//�̳���QgraphicsObject�Ĵ��麯��
QRectF PlayerFighter::boundingRect() const {
	return pixmaps.at(0).rect();
}

QPainterPath PlayerFighter::shape() const {
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void PlayerFighter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, pixmaps.at(0));
	//�������painter
	return;
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

void PlayerFighter::destroy()
{
	deleteLater();
}