#include "list.h"
#include "ui_list.h"

List::List(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::list();
	ui->setupUi(this);
	backbutton->setText("back");
	backbutton->setGeometry(340, 280, 50, 25);
	connect(backbutton, SIGNAL(clicked(bool)), this, SLOT(on_backbutton_clicked_list()));
	
}

List::~List()
{
	delete ui;
}
void List::on_backbutton_clicked_list()
{
	this->hide();
	emit showstart_fromlist();
}
void  List::receivestart_fromlist()
{
	this->show();
}