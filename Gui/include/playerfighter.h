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

	//�̳���QgraphicsObject�Ĵ��麯��
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void Attack(QGraphicsScene *ptrsence);
	void hitCtrl();
	
	void destroy();

	//�ƶ���������ÿ��ʱ�����ڼ��һ�μ��̣�������һ�δ˺���
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