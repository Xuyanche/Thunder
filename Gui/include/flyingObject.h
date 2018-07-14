#pragma once
#include <qwidget.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qpainter.h>
#include "..\include\global.h"

//qreal Ô¼µÈÓÚ double


typedef QList<QPixmap> QPixmaps;
enum flyingObjectType {
	Type_Boss, Type_Bullet, Type_Player
};


class FlyingObject : public QGraphicsObject {
	
	Q_OBJECT

public:
	FlyingObject(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pic, QGraphicsScene *scene, QGraphicsItem* parent);
	virtual ~FlyingObject() = 0;

	virtual void hitCtrl() = 0;
	virtual void destroy() = 0;
	virtual flyingObjectType getType() = 0;


	//x, y, z value is included in the qgraphicobject class
	qreal width;
	qreal height;
	qreal maxspeed;
	qreal pixpos;
	uint maxstep;
	QPixmaps pixmaps;

};



class BulletManage {
	
	QList<> bulletList




};



