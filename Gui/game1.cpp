#include "game1.h"
#include"ui_game1.h"
#include"include/global.h"
#include <QTimer>
#include <qgraphicsitem.h>

game1::game1(gamenumber game,QWidget *parent)
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

	ui->progressBar->setStyleSheet("QProgressBar{border:1px solid #FFFFFF;"  "height:30;" "background:red;""text-align:center;""color:rgb(255,255,0);" "border-radius:10px;}" "QProgressBar::chunk{ ""background:qlineargradient(spread : pad,x1 : 0,y1 : 0,x2 : 1,y2 : 0,stop : 0 red,stop : 1 blue);" "border-radius:10px; }" );
	isInit = false;

}

game1::~game1()
{
	delete ui;
}
void game1::on_backbutton_clicked_game1()
{
	this->hide();
	emit showstart_fromgame1();
	this->close();
}

void game1::init()
{
	if (isInit) {
		return;
	}
	Boss* boss = createBoss(sence,game);
	PlayerFighter* fighter = createPlayerFighter(sence);
	fighter->setPos(100, 350);
	fighter->setFocus();
	boss->setPos(100, 50);
	lamp = startTimer(50);
	isInit = true;
	return;
}

void game1::receivestart_fromgame1()
{
	this->show();
	init();
}

void game1::timerEvent(QTimerEvent* Event)
{
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
void game1::close()
{
	sence->clear();
	isInit = false;

}