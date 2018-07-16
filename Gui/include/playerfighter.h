#pragma once
#include "flyingObject.h"
#include "BulletManager.h"
#include <QKeyEvent>

class PlayerFighter :public FlyingObject
{
public:

	PlayerFighter(qreal wvalue, qreal hvalue, qreal speed, QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent, int healthvalue);
	~PlayerFighter();



	flyingObjectType getType();

	//继承自QgraphicsObject的纯虚函数
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void Attack(QGraphicsScene *ptrsence);
	void hitCtrl();
	void damaged(Bullet* t);
	void destroy();

	//移动函数
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void keyPressEvent(QKeyEvent* Event);
	void keyReleaseEvent(QKeyEvent* Event);
	void advance(int);
	

private:
	int health;
	bool W, A, S, D;
};