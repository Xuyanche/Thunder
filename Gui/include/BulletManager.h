#pragma once
#include <vector>
#include <iostream>
#include "../include/flyingObject.h"
using namespace std;


enum BelongTo {
	Enemy, Nutural, Self
};



class Bullet :public FlyingObject {
public:
	Bullet();
	Bullet(qreal wvalue, qreal hvalue, qreal spead, QPixmap &pic, QGraphicsScene *scene, QGraphicsItem* parent);
	~Bullet();


	void hitCtrl();



	qreal xspeed;
	qreal yspeed;
	int damange;
	BelongTo belong;

};








