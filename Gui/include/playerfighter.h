#pragma once
#include "flyingObject.h"
#include "BulletManager.h"
#include <QKeyEvent>

class PlayerFighter :public FlyingObject
{
public:

	PlayerFighter(qreal wvalue, qreal hvalue, qreal spead, QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, int healthvalue);
	~PlayerFighter();


	void KeyPressEvent(QKeyEvent *event);
	
	void hitCtrl();
	void damaged(Bullet* t);
	void destroyed();

private:
	int health;
};