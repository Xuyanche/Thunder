#pragma once
#include <qstring.h>




#define SCENEHEIGHT 1000
#define SCENEWIDTH 1000




#define ENEMYBULLET_ORDINARY_SPEED 5
#define ENEMYBULLET_ORDINARY_WIDTH 50
#define ENEMYBULLET_ORDINARY_HEIGHT 50
#define ENEMYBULLET_ORDINARY_DAMAGE 3

#define FRIENDBULLET_ORDINARY_SPEED 5
#define FRIENDBULLET_ORDINARY_WIDTH 50
#define FRIENDBULLET_ORDINARY_HEIGHT 50
#define FRIENDBULLET_ORDINARY_DAMAGE 3

#define PLAYER_ORDINARY_SPEED 10
#define FIGHTER_ORDINARY_WIDTH 100
#define FIGHTER_ORDINARY_HEIGHT 100

#define ACTION_FREQUENCY	50

const QString Enemybullet_Ordinary_Image = ":/start/image/enemyBullet_ordinary.png";
const QString Friendbullet_Ordinary_Image = ":/start/image/friendBullet_ordinary.png";

const QString PlayerFighter_Ordinary_Image = ":/start/image/playerfighter.png";




enum BelongTo {
	Enemy, Nutural, Friend
};
enum BulletType {
	Ordinary_Friend, Ordinary_Enemy
};

typedef QList<QPixmap> QPixmaps;
enum flyingObjectType {
	Type_Boss, Type_Bullet, Type_Player
};
