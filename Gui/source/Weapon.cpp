#include "../include/weapon.h"

Weapon::Weapon(BulletType typeValue, int attackspeedvalue, angleChangePolicy policy, FlyingObject* parentptr, int OffsetValue, qreal startangle)
{
	attackSpeed = attackspeedvalue;
	bulletType = typeValue;
	parent = parentptr;
	offset = OffsetValue;
	angle = startangle;
	anglePolicy = policy;
}



void Weapon::attack()
{
	Bullet* b;
	if (step == attackSpeed) {
		b = createBullet(bulletType, getScene(), angle);
		QPointF pos = parent->scenePos();
		pos.rx() = pos.rx() + parent->width / 2 - b->width / 2;
		pos.ry() = pos.ry() + parent->height / 2 - b->height - 2;
		b->setPos(pos);

		step = offset;
		anglechange();
	}
	else
		step++;

	return;
}

void Weapon::anglechange()
{
	switch (anglePolicy)
	{
	case AnglePolicy_Steady:
		break;
	case AnglePolicy_Turn:
		angle += ANGLEPOLICY_TURN_CONST;
	default:
		break;
	}
}



QGraphicsScene* Weapon::getScene()
{
	return parent->scene();
}


Weapon* createWeapon(weaponType weaponTypeValue, FlyingObject* parentptr, int offsetValue, qreal startangle)
{
	Weapon* newWeapon;
	switch (weaponTypeValue)
	{
	case weaponType_normal:
		newWeapon = new Weapon(Ordinary_Enemy, BOSS_ORDINARY_ATTACKSPEED, AnglePolicy_Steady, parentptr, offsetValue, startangle);
	case waponType_Curve:
		newWeapon = new Weapon(Plus_Curve_Enemy, BOSS_ORDINARY_ATTACKSPEED, AnglePolicy_Turn, parentptr, offsetValue, startangle);
	default:
		break;
	}
	return newWeapon;

}