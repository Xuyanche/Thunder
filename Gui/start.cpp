#include "start.h"
#include "ui_start.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{	
	ui = new Ui::startClass();
    ui->setupUi(this);
    connect(ui->quitbutton,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->startbutton,SIGNAL(clicked(bool)),this,SLOT(on_startbutton_clicked()));
	connect(ui->listbutton, SIGNAL(clicked(bool)), this, SLOT(on_listbutton_clicked()));

	QImage *logo_img = new QImage(":/start/image/tital.png");
	QImage *scaled_logo_img = new QImage();
	*scaled_logo_img = logo_img->scaled(ui->tital->width(), ui->tital->height(), Qt::KeepAspectRatio);
	ui->tital->setPixmap(QPixmap::fromImage(*scaled_logo_img));

	QPixmap start(":/start/image/start (1).png");
	ui->startbutton->setIcon(start);
	ui->startbutton->setIconSize(QSize(80, 25));
	ui->startbutton->setStyleSheet("QPushButton{background:transparent;}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");

	QPixmap list(":/start/image/list.png");
	ui->listbutton->setIcon(list);
	ui->listbutton->setIconSize(QSize(80, 25));
	ui->listbutton->setStyleSheet("QPushButton{background:transparent;}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");

	QPixmap quit(":/start/image/quit.png");
	ui->quitbutton->setIcon(quit);
	ui->quitbutton->setIconSize(QSize(25, 25));
	ui->quitbutton->setStyleSheet("QPushButton{background:transparent;}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");

}
Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_startbutton_clicked()
{
	this->hide();
	emit showgame1();
}
void Dialog::on_listbutton_clicked()
{
	this->hide();
	emit showlist();
}
void Dialog::receive()
{
	this->show();
}