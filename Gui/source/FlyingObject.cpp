#include "../include/flyingObject.h"


FlyingObject::FlyingObject(qreal wvalue, qreal hvalue, qreal speed, const QPixmaps &pixs, QGraphicsScene* scene, QGraphicsItem* parent)
	:QGraphicsObject(parent), width(wvalue), height(hvalue), maxspeed(speed), pixpos(0), maxstep(0){


	for (int i = 0; i < pixs.size(); i++) {
		QPixmap temp(pixs.at(i)), t;
		t = temp.scaled(width, height, Qt::KeepAspectRatioByExpanding);
		pixmaps.append(t);
	}
	
	scene->addItem(this);
	
}

