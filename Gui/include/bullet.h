#pragma once
#include "flyingObject.h"
#include "global.h"
#include <math.h>
using namespace std;

class Bullet :public FlyingObject {
public:
	Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue);
	~Bullet();


	void hitCtrl();
	void advance(int);
	flyingObjectType getType();
	void destroy();

	//¼Ì³Ð×ÔQgraphicsObjectµÄ´¿Ðéº¯Êý
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	

	qreal xspeed;
	qreal yspeed;
	int damage;
	BelongTo belong;


	extern friend Bullet* createBullet(BulletType typevalue, QGraphicsScene *scene, qreal anglevalue);
};






