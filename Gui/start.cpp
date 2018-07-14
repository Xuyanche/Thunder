#include "start.h"

start::start(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setFixedSize(500, 400);
	QFont font("Microsoft YaHei", 24, 75);
	tital->setText(tr("À×µç"));
	tital->setGeometry(180, 0, 200, 100);
	tital->setFont(font);
	startbutton->setText("game start");
	quitbutton->setText("quit");
	startbutton->setGeometry(200, 100, 80, 25);
	quitbutton->setGeometry(200, 200, 50, 25);
	connect(quitbutton, SIGNAL(clicked(bool)), this, SLOT(close()));
	connect(startbutton, SIGNAL(clicked(bool)), this, SLOT(accept()));

}
