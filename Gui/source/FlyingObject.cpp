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



FlyingObject::~FlyingObject() {

}

bool FlyingObject::checkPos() {
	bool poslegal = false;
	QPointF pos = scenePos();
	if (pos.rx() > -1 * width && pos.rx() < SCENEHEIGHT&& pos.ry() > -1 * height && pos.ry() < SCENEHEIGHT) {
		poslegal = true;
	}
	return poslegal;
}



bool FlyingObject::checkPos(int dx, int dy)
{
	bool poslegal = false;
	QPointF pos = scenePos();
	if (pos.rx()+dx > -1 * width && pos.rx()+dx < SCENEHEIGHT&& pos.ry() +dy > -1 * height && pos.ry() + dy < SCENEHEIGHT) {
		poslegal = true;
	}
	return poslegal;
}