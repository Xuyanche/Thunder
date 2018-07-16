#include "game1.h"
#include"ui_game1.h"
#include "include/playerfighter.h"
#include "include/boss.h"
#include "include/BulletManager.h"
#include <qgraphicsitem.h>

game1::game1(QWidget *parent)
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
	ui->progressBar->setStyleSheet("QProgressBar{border:1px solid #FFFFFF;"  "height:30;" "background:red;""text-align:center;""color:rgb(255,255,0);" "border-radius:10px;}" "QProgressBar::chunk{ ""background:qlineargradient(spread : pad,x1 : 0,y1 : 0,x2 : 1,y2 : 0,stop : 0 red,stop : 1 blue);" "border-radius:10px; }" );

	Bullet* b = ObjectManager::createBullet(Ordinary_Enemy, sence, 0);
	b->setPos(100, 100);

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

