#pragma once
#include "global.h"
#include "bullet.h"


enum angleChangePolicy {
	AnglePolicy_Steady, AnglePolicy_Turn
};




class Weapon {
public:
	Weapon(BulletType typeValue, int attackspeedvalue, angleChangePolicy policy, FlyingObject* parentptr, int OffsetValue = 0);
	

	void attack();
	QGraphicsScene* getScene();
	void anglechange();



	BulletType bulletType;
	int attackSpeed;
	int step;
	int offset;
	qreal angle;
	angleChangePolicy anglePolicy;
	FlyingObject *parent;


	friend Weapon* createWeapon(int weaponType, FlyingObject* parentptr, int offset = 0);


};


