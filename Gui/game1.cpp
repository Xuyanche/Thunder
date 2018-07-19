#include "game1.h"
#include"ui_game1.h"
#include"include/global.h"
#include <QTimer>
#include <qgraphicsitem.h>

	: QMainWindow(parent)
{   
	ui = new Ui::game1();
	ui->setupUi(this);
	backbutton = new QPushButton(this);
	backbutton->setText("back");
	backbutton->setGeometry(520, 400, 50, 25);
	connect(backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_game1()));
	sence = new QGraphicsScene(10, 0, 260, 400);
	ui->view->setScene(sence);
	ui->progressBar->setTextVisible(false);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	Boss* boss = createBoss(sence, game);
	Bullet* b1 = createBullet(Ordinary_Enemy, sence, 0);
	PlayerFighter* fighter = createPlayerFighter(sence);
	choosegame(game,boss,b1, fighter);
}

game1::~game1()
{
	delete ui;
}
void game1::on_backbutton_clicked_game1()
{
	this->hide();
	emit showstart_fromgame1();
}
void game1::receivestart_fromgame1()
{
	this->show();
}

void game1::timerEvent(QTimerEvent* Event) {

	if(Event->timerId()==lamp)
		sence->advance();
	sence->update();
}
void game1::choosegame(gamenumber game, Boss* boss, Bullet* b1, PlayerFighter* fighter)
{   
	
	switch (game)
	{
	case gameone:
		ui->progressBar->setRange(0, 2000);	
		b1->setPos(100, 100);
		fighter->setPos(200, 200);
		fighter->setFocus();
		boss->setPos(100, 100);
		lamp = startTimer(50);
		ui->progressBar->setValue(boss->gethealth());
		break;
	case gametwo:
		break;
	case gamethree:
		break;
	default:
		break;
	}
}