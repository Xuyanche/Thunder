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

//继承自QgraphicsObject的纯虚函数
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
	//自身带有painter
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


void PlayerFighter::MoveLeft()
{
	QPointF pos = scenePos();
	if (checkPos(-PLAYER_ORDINARY_SPEED, 0)) {
		pos.rx -= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}


void PlayerFighter::MoveRight()
{
	QPointF pos = scenePos();
	if (checkPos(PLAYER_ORDINARY_SPEED, 0)) {
		pos.rx += PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}

void PlayerFighter::MoveUp()
{
	QPointF pos = scenePos();
	if (checkPos(0, -PLAYER_ORDINARY_SPEED)) {
		pos.ry -= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}

void PlayerFighter::MoveDown()
{
	QPointF pos = scenePos();
	if (checkPos(0, PLAYER_ORDINARY_SPEED)) {
		pos.ry += PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}
