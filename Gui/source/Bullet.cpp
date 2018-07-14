#include "../include/BulletManager.h"


Bullet::Bullet(qreal wvalue, qreal hvalue, qreal spead, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, int damagevalue, BelongTo belongvalue)
	: FlyingObject(wvalue, hvalue, spead, pixs, scene, parent), damage(damagevalue), belong(belongvalue) {

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
	//�ӵ����parentָ��ָ����������Ǹ��ɻ���ͬʱ��qt��һ��graphicobjct��������������parent��Ϊ����ϵ�ģ�����ʼ�ص��ǣ�0��0����
	return;
}




void BulletManager::createBullet(BulletType typevalue, QGraphicsScene *scene) {
	Bullet* newbullet;

	switch (typevalue) {
	case Ordinary_Enemy:
		newbullet = Bullet();
		break;
	case Ordinary_Friend:
		newbullet = Bullet();
		break;
	default:
		break;
	}

	if (newbullet != NULL) {
		bulletList.append(newbullet);
	}

	return;
}

