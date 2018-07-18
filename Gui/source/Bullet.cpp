#include "../include/BulletManager.h"
#include "../include/global.h"
#include <math.h>


Bullet::Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue)
	: FlyingObject(wvalue, hvalue, speed, pixs, scene, parent), damage(damagevalue), belong(belongvalue) {
	xspeed = maxspeed * sin(angle);
	yspeed = maxspeed * cos(angle);
	if (belongvalue == Enemy) {
		parent = 0;
	}
}



Bullet::Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue, QPainter* painter)
	: FlyingObject(wvalue, hvalue, speed, pixs, scene, parent), damage(damagevalue), belong(belongvalue) {
	xspeed = maxspeed * sin(angle);
	yspeed = maxspeed * cos(angle);
	if (belongvalue == Enemy) {
		parent = 0;
	}
}



Bullet::~Bullet() {
	//do nothing
}


void Bullet::hitCtrl() {
	// do nothing
}

flyingObjectType Bullet::getType(){
	return Type_Bullet;
}


void Bullet::destroy() {
	setVisible(false);
	deleteLater();
}

void Bullet::advance(int) {
	QPointF pos = scenePos();
	pos.rx() += xspeed;
	pos.ry() += yspeed;
	if (checkPos(xspeed, yspeed) == true) {
		setPos(pos);
	}
	else {
		destroy();
	}
	return;
}

QRectF Bullet::boundingRect() const{
	return pixmaps.at(0).rect();
}

QPainterPath Bullet::shape() const {
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, pixmaps.at(pixpos));
	//painter->drawLine(-10, -10, 10, 10);
}




Bullet* ObjectManager::createBullet(BulletType typevalue, QGraphicsScene *scene, qreal anglevalue) {
	Bullet* newbullet = NULL;

	QPixmaps tmp;

	switch (typevalue) {
	case Ordinary_Enemy:
		tmp.append(QPixmap(Enemybullet_Ordinary_Image));
		newbullet = new Bullet(ENEMYBULLET_ORDINARY_WIDTH, ENEMYBULLET_ORDINARY_HEIGHT, ENEMYBULLET_ORDINARY_SPEED, tmp, scene, 0, anglevalue, ENEMYBULLET_ORDINARY_DAMAGE, Enemy);
		break;
	case Ordinary_Friend:
		tmp.append(QPixmap(Friendbullet_Ordinary_Image));
		newbullet = new Bullet(FRIENDBULLET_ORDINARY_WIDTH, FRIENDBULLET_ORDINARY_HEIGHT, FRIENDBULLET_ORDINARY_SPEED, tmp, scene, 0, anglevalue, FRIENDBULLET_ORDINARY_DAMAGE, Friend);
		break;
	default:
		break;
	}

	return newbullet;
}

/*
PlayerFighter * ObjectManager::createFighter(QGraphicsScene *scene, qint32 healthvalue)
{
	PlayerFighter* newfighter = NULL;
	QPixmaps tmp;

	tmp.append(QPixmap(PlayerFighter_Ordinary_Image));
	newfighter = new PlayerFighter(FIGHTER_ORDINARY_WIDTH, FIGHTER_ORDINARY_HEIGHT, PLAYER_ORDINARY_SPEED, tmp, scene, 0, healthvalue);
	return newfighter;
}*/