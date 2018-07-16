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


void PlayerFighter::Attack(QGraphicsScene *ptrsence)
{
	ObjectManager::createBullet(Ordinary_Friend, ptrsence, (-45 / 3.14159));
}


void PlayerFighter::MoveLeft()
{
	QPointF pos = scenePos();
	if (checkPos(-PLAYER_ORDINARY_SPEED, 0)) {
		pos.rx ()-= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}


void PlayerFighter::MoveRight()
{
	QPointF pos = scenePos();
	if (checkPos(PLAYER_ORDINARY_SPEED, 0)) {
		pos.rx ()+= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}

void PlayerFighter::MoveUp()
{
	QPointF pos = scenePos();
	if (checkPos(0, -PLAYER_ORDINARY_SPEED)) {
		pos.ry() -= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}

void PlayerFighter::MoveDown()
{
	QPointF pos = scenePos();
	if (checkPos(0, PLAYER_ORDINARY_SPEED)) {
		pos.ry ()+= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}


void PlayerFighter::keyPressEvent(QKeyEvent * Event)
{
	switch (Event->key())
	{
	case Qt::Key_Up:
	case Qt::Key_W:
		Event->accept();
		W = true;
		break;
	case Qt::Key_A:
	case Qt::Key_Left:
		Event->accept();
		A = true;
		break;
	case Qt::Key_S:
	case Qt::Key_Down:
		Event->accept();
		S = true;
		break;
	case Qt::Key_D:
	case Qt::Key_Right:
		Event->accept();
		D = true;
		break;
	default:
		Event->ignore();
		break;
	}

}

void PlayerFighter::keyReleaseEvent(QKeyEvent * Event)
{
	switch (Event->key())
	{
	case Qt::Key_Up:
	case Qt::Key_W:
		Event->accept();
		W = false;
		break;
	case Qt::Key_A:
	case Qt::Key_Left:
		Event->accept();
		A = false;
		break;
	case Qt::Key_S:
	case Qt::Key_Down:
		Event->accept();
		S = false;
		break;
	case Qt::Key_D:
	case Qt::Key_Right:
		Event->accept();
		D = false;
		break;
	default:
		Event->ignore();
		break;
	}

}

void PlayerFighter::advance(int)
{
	if (W)
		MoveUp();
	if (S)
		MoveDown();
	if (A)
		MoveLeft();
	if (D)
		MoveRight();
	hitCtrl();
}






