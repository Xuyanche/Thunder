#include "..\include\playerfighter.h"

PlayerFighter::PlayerFighter(qreal wvalue, qreal hvalue, qreal speed, QPixmaps & pic, QGraphicsScene * scene, QGraphicsItem * parent, int healthvalue)
	:FlyingObject(wvalue, hvalue, speed, pic, scene, parent)
{
	health = healthvalue;
	setFlag(ItemIsFocusable, true);
	W = A = S = D = false;
	step = 0;
	setZValue(1);
}

PlayerFighter::~PlayerFighter()
{
}


flyingObjectType PlayerFighter::getType() {
	return flyingObjectType::Type_Player;
}

//继承自QgraphicsObject的纯虚函数
QRectF PlayerFighter::boundingRect() const {
	return pixmaps.at(0).rect();
}

QPainterPath PlayerFighter::shape() const {
	QPainterPath path;
	path.addRect(boundingRect());
	return path;
}

void PlayerFighter::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	Q_UNUSED(option);
	Q_UNUSED(widget);
	painter->drawPixmap(0, 0, pixmaps.at(pixpos));
	/*QPointF point[3] = {
		QPointF(-0.5*width, 0.5*height),
		QPointF(0, -0.5*height),
		QPointF(0.5*width, 0.5*height)
	};
	painter->drawPolygon(point, 3);*/
	return;
}


void PlayerFighter::hitCtrl()
{
	for each (QGraphicsItem *i in collidingItems())
	{
		if (i->type() >= FlyingObject::Type){
			FlyingObject* t = static_cast<FlyingObject*>(i);
			if (t->getType() == Type_Bullet) {
				Bullet* b = static_cast<Bullet*>(t);
				if (b->belong == Enemy && b->isHit == 0) {
					health = health - b->damage;
					b->boom();
					emit notify(health);
					if (health <= 0)
						destroy();
				}
			}
			else if (t->getType() == Type_Boss)
				destroy();
		}
	}
	return;
}



void PlayerFighter::destroy()
{
	deleteLater();
	emit sig_fall();
}

void PlayerFighter::Attack(QGraphicsScene *ptrsence)
{
	Bullet* b = createBullet(Ordinary_Friend, ptrsence, -0.5*CONSTANT_PI);//子弹竖直向上
	QPointF pos = scenePos();
	pos.rx() = pos.rx() + width / 2 - b->width / 2;
	pos.ry() = pos.ry() + height / 2 - b->height - 2;
	b->setPos(pos);
}


void PlayerFighter::MoveLeft()
{
	QPointF pos = scenePos();
	if (checkPos(-1 * PLAYER_ORDINARY_SPEED, 0)) {
		pos.rx ()-= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}


void PlayerFighter::MoveRight()
{
	QPointF pos = scenePos();
	if (checkPos(PLAYER_ORDINARY_SPEED, 0)) {
		pos.rx ()+= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}

void PlayerFighter::MoveUp()
{
	QPointF pos = scenePos();
	if (checkPos(0, -1 * PLAYER_ORDINARY_SPEED)) {
		pos.ry() -= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
}

void PlayerFighter::MoveDown()
{
	QPointF pos = scenePos();
	if (checkPos(0, PLAYER_ORDINARY_SPEED)) {
		pos.ry ()+= PLAYER_ORDINARY_SPEED;
		setPos(pos);
	}
	return;
}


void PlayerFighter::keyPressEvent(QKeyEvent * Event)
{
	switch (Event->key())
	{
	case Qt::Key_Up:
	case Qt::Key_W:
		Event->accept();
		W = true;
		break;
	case Qt::Key_A:
	case Qt::Key_Left:
		Event->accept();
		A = true;
		break;
	case Qt::Key_S:
	case Qt::Key_Down:
		Event->accept();
		S = true;
		break;
	case Qt::Key_D:
	case Qt::Key_Right:
		Event->accept();
		D = true;
		break;
	default:
		Event->ignore();
		break;
	}

}

void PlayerFighter::keyReleaseEvent(QKeyEvent * Event)
{
	switch (Event->key())
	{
	case Qt::Key_Up:
	case Qt::Key_W:
		Event->accept();
		W = false;
		break;
	case Qt::Key_A:
	case Qt::Key_Left:
		Event->accept();
		A = false;
		break;
	case Qt::Key_S:
	case Qt::Key_Down:
		Event->accept();
		S = false;
		break;
	case Qt::Key_D:
	case Qt::Key_Right:
		Event->accept();
		D = false;
		break;
	default:
		Event->ignore();
		break;
	}

}

void PlayerFighter::advance(int)
{
	if (W)
		MoveUp();
	if (S)
		MoveDown();
	if (A)
		MoveLeft();
	if (D)
		MoveRight();
	hitCtrl();
	step++;
	if (step%PLAYER_ATTACK_STEPS == 0)
		Attack(this->scene());
	if (step >= PLAYER_ATTACK_STEPS * 100)
		step = 0;
}



PlayerFighter* createPlayerFighter(QGraphicsScene* scene) {
	PlayerFighter* newfighter = NULL;

	QPixmaps tmp;
	tmp.append(QPixmap(PlayerFighter_Ordinary_Image));
	newfighter = new PlayerFighter(FIGHTER_ORDINARY_WIDTH, FIGHTER_ORDINARY_HEIGHT, PLAYER_ORDINARY_SPEED, tmp, scene, 0, PLAYER_ORDINARY_MAXHEALTH);

	return newfighter;
}

