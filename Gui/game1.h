#pragma once

#include <QMainwindow>
#include"QPushButton"
#include"qgraphicsscene.h"
#include"qgraphicsview.h"
namespace Ui { class game1; };
class game1 : public QMainWindow
{
	Q_OBJECT

public:
	game1(QWidget *parent = Q_NULLPTR);
	~game1();
private 
slots:
	void receivestart_fromgame1();
	void on_backbutton_clicked_game1();
signals: 
	void showstart_fromgame1();
private:
	Ui::game1*ui;
	QPushButton*backbutton;
	QGraphicsScene* sence;
};