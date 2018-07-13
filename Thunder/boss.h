#pragma once

#include "BulletManager.h"

class Boss
{
public:

	Boss();
	Boss(int PosX, int PosY, int Life);
	~Boss();

	//accessor
	int getPosX();
	int getPosY();
	int getLifePoint();

	//mutator
	void setPosX(const int NewPosX);
	void setPosY(const int NewPosY);
	void set(const int NewLife);

	//Functions


private:
	int LifePoint;
	int PosX;
	int PosY;

};

