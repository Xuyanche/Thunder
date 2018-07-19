#pragma once

#include <QMainwindow>
#include"QPushButton"
#include"include/global.h"
#include"include/playerfighter.h"
#include"include/boss.h"
#include"qgraphicsscene.h"
#include"qgraphicsview.h"
namespace Ui { class game1; };
class game1 : public QMainWindow
{
	Q_OBJECT

public:
	game1(gamenumber game, QWidget *parent = Q_NULLPTR);
	~game1();
	void timerEvent(QTimerEvent* Event);
private 
slots:
	void receivestart_fromgame1();
	void on_backbutton_clicked_game1();
	void OnNotify(int health);
signals: 
	void showstart_fromgame1();
	
private:
	void close();
	int lamp;
	bool isInit;
	void init();
	Ui::game1*ui;
	QPushButton*backbutton;
	QGraphicsScene* sence;
	gamenumber game;
	};
