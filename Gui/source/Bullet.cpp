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

void Bullet::advance() {
	QPointF pos = scenePos();
	pos.x += xspeed;
	pos.y += yspeed;

	setPos(pos);
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
	painter->drawPixmap(0, 0, pixmaps.at(0));
	//子弹类的parent指针指向产生他的那个飞机，同时在qt中一个graphicobjct的坐标是以他的parent作为坐标系的，故起始地点是（0，0）。
	return;
}




void BulletManager::createBullet(BulletType typevalue, QGraphicsScene *scene, qreal anglevalue) {
	Bullet* newbullet;

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

	if (newbullet != NULL) {
		bulletList.append(newbullet);
	}

	return;
}

