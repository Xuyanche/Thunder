#include "../include/Bullet.h"



Bullet::Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue)
	: FlyingObject(wvalue, hvalue, speed, pixs, scene, parent), damage(damagevalue), belong(belongvalue)
{
	xspeed = maxspeed * cos(angle);
	yspeed = maxspeed * sin(angle);
	if (belongvalue == Enemy)
		parent = 0;
	isHit = 0;
}





Bullet::~Bullet()
{
	//do nothing
}


void Bullet::hitCtrl()
{
	// do nothing
}

flyingObjectType Bullet::getType()
{
	return Type_Bullet;
}


void Bullet::destroy()
{
	setVisible(false);
	deleteLater();
}

void Bullet::boom()
{
	isHit = 1;
	return;
}

void Bullet::advance(int) 
{
	if (isHit == 5) 
	{
		destroy();
		return;
	}
	else if (isHit != 0) 
	{
		isHit++;
		pixpos = 1;
		return;
	}

	QPointF pos = scenePos();
	pos.rx() += xspeed;
	pos.ry() += yspeed;
	if (checkPos(xspeed, yspeed) == true)
		setPos(pos);
	else 
		destroy();
	return;
}

QRectF Bullet::boundingRect() const
{
	return pixmaps.at(0).rect();
}

QPainterPath Bullet::shape() const 
{
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) 
{
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, pixmaps.at(pixpos));
	//painter->drawEllipse(-1 * width / 2, -1 * height / 2, width, height);
}


Bullet* createBullet(BulletType typevalue, QGraphicsScene *scene, qreal anglevalue)
{
	Bullet* newbullet = NULL;

	QPixmaps tmp;

	switch (typevalue) 
	{
	case Ordinary_Enemy:
		tmp.append(QPixmap(Enemybullet_Ordinary_Image));
		tmp.append(QPixmap(Enemybullet_Ordinary_Boom_Image));
		newbullet = new Bullet(ENEMYBULLET_ORDINARY_WIDTH, ENEMYBULLET_ORDINARY_HEIGHT, ENEMYBULLET_ORDINARY_SPEED, tmp, scene, 0, anglevalue, ENEMYBULLET_ORDINARY_DAMAGE, Enemy);
		break;
	case Ordinary_Friend:
		tmp.append(QPixmap(Friendbullet_Ordinary_Image));
		tmp.append(QPixmap(Enemybullet_Ordinary_Boom_Image));
		newbullet = new Bullet(FRIENDBULLET_ORDINARY_WIDTH, FRIENDBULLET_ORDINARY_HEIGHT, FRIENDBULLET_ORDINARY_SPEED, tmp, scene, 0, anglevalue, FRIENDBULLET_ORDINARY_DAMAGE, Friend);
		break;
	default:
		break;
	}

	return newbullet;
}


