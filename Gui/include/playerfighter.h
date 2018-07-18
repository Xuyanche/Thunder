#pragma once
#include "flyingObject.h"
#include "bullet.h"
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
	
	void destroy();

	//移动函数，请每个时钟周期检查一次键盘，并调用一次此函数
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void keyPressEvent(QKeyEvent* Event);
	void keyReleaseEvent(QKeyEvent* Event);
	void advance(int);
	
	friend PlayerFighter* createPlayerFighter(QGraphicsScene* scene);


private:
	int health;
	bool W, A, S, D;
};