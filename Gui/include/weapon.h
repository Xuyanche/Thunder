#pragma once
#include "bullet.h"


enum angleChangePolicy {
	AnglePolicy_Steady, AnglePolicy_Turn
};


enum weaponType {
	weaponType_normal, waponType_Curve
};



class Weapon {
public:
	Weapon(BulletType typeValue, int attackspeedvalue, angleChangePolicy policy, FlyingObject* parentptr, int OffsetValue, qreal startangle);
	

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


	friend Weapon* createWeapon(weaponType weaponTypeValue, FlyingObject* parentptr, int offset, qreal startangle);


};


