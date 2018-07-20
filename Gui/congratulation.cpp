#include "congratulation.h"
#include "ui_congratulation.h"

congratulation::congratulation(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::congratulation();
	ui->setupUi(this);
	this->setStyleSheet("border-image: url(:/start/image/gameover.png)");
	this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	connect(ui->backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_gameover()));
	connect(ui->restartbutton, SIGNAL(clicked(bool)), this, SLOT(on_restartbutton_clicked_gameover()));
	ui->backbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/back.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
	ui->restartbutton->setStyleSheet("QPushButton{background:transparent;border-image:url(:/start/image/restart.png)}""QPushButton:hover{border-radius:5px; border:1px solid rgb(210, 225, 230);}");
}

congratulation::~congratulation()
{
	delete ui;
}
void congratulation::receive()
{
	this->show();
}
void congratulation::on_backbutton_clicked_gameover()
{
	this->hide();
	emit show_start();
}
void congratulation::on_restartbutton_clicked_gameover()
{
	this->hide();
	emit show_gameone();

}