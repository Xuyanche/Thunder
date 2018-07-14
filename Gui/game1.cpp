#include "game1.h"
#include"ui_game1.h"


game1::game1(QWidget *parent)
	: QMainWindow(parent)
{   
	ui = new Ui::MainWindow();
	ui->setupUi(this);
	backbutton = new QPushButton(this);
	backbutton->setText("back");
	backbutton->setGeometry(520, 400, 50, 25);
	connect(backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_game1()));
	sence = new QGraphicsScene(0, 0, 250.400);
	
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
