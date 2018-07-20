#include "game1.h"
#include"ui_game1.h"
#include"include/global.h"
#include <QTimer>
#include "qlabel.h"
#include <qgraphicsitem.h>

game1::game1(gamenumber game,QWidget *parent)
	: QMainWindow(parent)
{   
	this->game = game;
	ui = new Ui::game1();
	ui->setupUi(this);
	ui->backbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/back.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	ui->nextbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/next.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	connect(ui->backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_game1()));
	connect(ui->nextbutton, SIGNAL(clicked(bool)), this, SLOT(on_nextbutton_clicked_game1()));
	sence = new QGraphicsScene(10, 0, SCENEHEIGHT/2, SCENEWIDTH);
	ui->view->setScene(sence);
	ui->progressBar->setTextVisible(false);
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	isInit = false;
}

game1::~game1()
{
	delete ui;
}
void game1::on_backbutton_clicked_game1()
{   
	this->hide();
	emit show_fromgame1();
}

void game1::on_nextbutton_clicked_game1()
{  
	this->hide();
	emit show_next();
	
}
void game1::init()
{
	QPixmap sencemap;
	if (isInit) {
		return;
	}
	Boss* boss = createBoss(sence, game);
	PlayerFighter* fighter = createPlayerFighter(sence);
	QObject::connect(fighter, SIGNAL(sig_fall()), this, SLOT(slt_playerDead()));
	QObject::connect(boss, SIGNAL(sig_fall()), this, SLOT(slt_bossDead()));
	switch (game)
	{
	case gameone:
		fighter->setPos(100, 350);
		fighter->setFocus();
		boss->setPos(100, 50);
		lamp = startTimer(50);
		this->setStyleSheet("QMainWindow {border-image: url(:/start/image/gw1.png);}");
		ui->view->setStyleSheet( "border-image: url(:/start/image/bg1.jpg)");
		
		ui->progressBar->setRange(0, PLAYER_ORDINARY_MAXHEALTH);
		ui->progressBar->setValue(PLAYER_ORDINARY_MAXHEALTH);
		QObject::connect(fighter, SIGNAL(notify(int)), this, SLOT(OnNotify(int)));
		isInit = true;
		
		break;
	case gametwo:
		fighter->setPos(100, 350);
		fighter->setFocus();
		boss->setPos(100, 50);
		lamp = startTimer(50);
		this->setStyleSheet("QMainWindow {border-image: url(:/start/image/gw1.png);}");
		ui->view->setStyleSheet("border-image: url(:/start/image/bg2.jpg)");

		ui->progressBar->setRange(0, PLAYER_ORDINARY_MAXHEALTH);
		ui->progressBar->setValue(PLAYER_ORDINARY_MAXHEALTH);
		QObject::connect(fighter, SIGNAL(notify(int)), this, SLOT(OnNotify(int)));
		isInit = true;
		break;
	case gamethree:
		break;
	default:
		break;
	}
	return;
}

void game1::receive_fromgame1()
{
	this->show();
	this->close();
	init();
	
}

void game1::timerEvent(QTimerEvent* Event)
{
	if(Event->timerId()==lamp)
		sence->advance();
	    sence->update();
}

void game1::close()
{
	sence->clear();
	isInit = false;

}
void  game1::slt_playerDead()
{
	this->hide();
	emit showgameover();
}
void game1::slt_bossDead()
{
	this->hide();
	emit show_next();
}
void game1::OnNotify(int health)
{
	ui->progressBar->setValue(health);

}
