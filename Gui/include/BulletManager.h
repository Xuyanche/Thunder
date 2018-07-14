#pragma once
#include <vector>
#include <iostream>
#include "../include/flyingObject.h"
using namespace std;


enum BelongTo {
	Enemy, Nutural, Self
};
enum BulletType {
	Ordinary_Friend, Ordinary_Enemy
};


class Bullet :public FlyingObject {
public:
	Bullet(qreal wvalue, qreal hvalue, qreal spead, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, int damagevalue, BelongTo belongvalue);
	~Bullet();


	void hitCtrl();
	void advance();
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

};



class BulletManager {
public:
	void createBullet(BulletType typevalue, QGraphicsScene *scene);
	

	QList<Bullet*> bulletList;
};




