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


	flyingObjectType getType();

	//�̳���QgraphicsObject�Ĵ��麯��
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	
	void hitCtrl();
	void damaged(Bullet* t);
	void destroy();


private:
	int health;
};