#pragma once
#include <vector>
#include <iostream>
using namespace std;


enum BelongTo {
	Enemy, Friend, Self
};



class Bullet {
public:
	Bullet();
	Bullet(BelongTo BValue, int damageValue, double startX, double startY, double speed, double direction);
	~Bullet();

	double getLocationX();
	double getLocationY();
	double getDamage();
	double getBelong();

	
	void fly();
	void setPosition(double x, double y);
	void setDirection(double directionValue);
	void setDamage(int damage);

	Object* isHit();



	void display();

private:
	double location_X;
	double location_Y;
	int damage;
	BelongTo belong;
	double speed; // pixel/second
	double direction;
	

};






class BulletManager {
public:
	BulletManager();
	~BulletManager();



	void createBullet(BelongTo BValue, int damageValue, double startX, double startY, double speedvalue, double directionvalue);
	






	vector<Bullet*> exist;


	



};




