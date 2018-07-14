#pragma once
#include <qwidget.h>
#include <qgraphicsitem.h>

//qreal Ô¼µÈÓÚ double






class FlyingObject : public QGraphicsObject {
	
	Q_OBJECT
public:
	FlyingObject(qreal wvalue, qreal hvalue, qreal spead, QPixmap &pic, QGraphicsScene *scene, QGraphicsItem* parent);

	~FlyingObject();

	virtual void hitCtrl() = 0;
	


	//x, y, z value is included in the qgraphicobject class
	qreal width;
	qreal height;
	qreal maxspeed;
	qreal pixpos;
	uint step;
	QPixmap pixmap;

};







