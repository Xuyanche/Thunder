#pragma once
#include <vector>
#include <iostream>
#include "../include/flyingObject.h"
#include "../include/playerfighter.h" 
using namespace std;


enum BelongTo {
	Enemy, Nutural, Friend
};
enum BulletType {
	Ordinary_Friend, Ordinary_Enemy
};


class Bullet :public FlyingObject {
public:
	Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue);
	Bullet(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem* parent, qreal angle, int damagevalue, BelongTo belongvalue, QPainter* painter);
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

};



class ObjectManager {
public:
	static Bullet* createBullet(BulletType typevalue, QGraphicsScene *scene, qreal anglevalue);

};




