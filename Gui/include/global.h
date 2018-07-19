#pragma once
#include <qstring.h>




#define SCENEHEIGHT 520
#define SCENEWIDTH 400




#define ENEMYBULLET_ORDINARY_SPEED 3
#define ENEMYBULLET_ORDINARY_WIDTH 20
#define ENEMYBULLET_ORDINARY_HEIGHT 20
#define ENEMYBULLET_ORDINARY_DAMAGE 3

#define FRIENDBULLET_ORDINARY_SPEED 5
#define FRIENDBULLET_ORDINARY_WIDTH 20
#define FRIENDBULLET_ORDINARY_HEIGHT 20
#define FRIENDBULLET_ORDINARY_DAMAGE 3

#define PLAYER_ORDINARY_SPEED 3
#define FIGHTER_ORDINARY_WIDTH 30
#define FIGHTER_ORDINARY_HEIGHT 30
#define PLAYER_ORDINARY_MAXHEALTH 30

#define ACTION_FREQUENCY	30

#define CONSTANT_PI 3.1415926
#define PLAYER_ATTACK_STEPS 20

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
enum gamenumber{
	gameone,gametwo,gamethree
};