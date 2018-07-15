#pragma once

#include <QDialog>
#include"QPushButton"
namespace Ui { class list; };

class list : public QDialog
{
	Q_OBJECT

public:
	list(QWidget *parent = Q_NULLPTR);
	~list();
private
slots:
	void receivestart_fromlist();
	void on_backbutton_clicked_list();
signals:
	void showstart_fromlist();
private:
	Ui::list *ui;
	QPushButton*backbutton = new QPushButton(this);
};
