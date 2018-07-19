#include "game1.h"
#include"ui_game1.h"
#include"include/global.h"
#include <QTimer>
#include <qgraphicsitem.h>

game1::game1(gamenumber game,QWidget *parent)
	: QMainWindow(parent)
{   
	this->game = game;
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
	QPixmap sencemap;
	if (isInit) {
		return;
	}
	Boss* boss = createBoss(sence, game);
	PlayerFighter* fighter = createPlayerFighter(sence);
	switch (game)
	{
	case gameone:
		fighter->setPos(100, 350);
		fighter->setFocus();
		boss->setPos(100, 50);
		lamp = startTimer(50);
		sencemap.load(":/start/image/game1.jpg");
		ui->progressBar->setRange(0, PLAYER_ORDINARY_MAXHEALTH);
		ui->progressBar->setValue(PLAYER_ORDINARY_MAXHEALTH);
		QObject::connect(fighter, SIGNAL(notify(int)), this, SLOT(OnNotify(int)));
		isInit = true;
		break;
	case gametwo:
		sencemap.load(":/start/image/game2.jpg");
		break;
	case gamethree:
		break;
	default:
		break;
	}
	QPalette palette(this->palette());
	palette.setBrush(QPalette::Background, QBrush(sencemap));
	this->setPalette(palette);
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

void game1::close()
{
	sence->clear();
	isInit = false;

}
void game1::OnNotify(int health)
{
	ui->progressBar->setValue(health);

}
