#include "list.h"
#include "ui_list.h"

list::list(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::list();
	ui->setupUi(this);
	backbutton->setText("back");
	backbutton->setGeometry(340, 280, 50, 25);
	connect(backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_list()));
	
}

list::~list()
{
	delete ui;
}
void list::on_backbutton_clicked_list()
{
	this->hide();
	emit showstart_fromlist();
}
void  list::receivestart_fromlist()
{
	this->show();
}