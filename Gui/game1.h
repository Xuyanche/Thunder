#pragma once

#include <QMainwindow>
#include"QPushButton"
#include"include/global.h"
#include"include/playerfighter.h"
#include"include/boss.h"
#include"qgraphicsscene.h"
#include"qgraphicsview.h"
#include "QtMultimedia/qsound.h"
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
	void receive_fromgame1();
	void on_backbutton_clicked_game1();
	void on_nextbutton_clicked_game1();
	void OnNotify(int health);
	void slt_playerDead();
	void slt_bossDead();
	void on_resumebutton_clicked_game1();
	void on_stopbutton_clicked_game1();
signals: 
	void show_fromgame1();
signals:
	void show_next();
signals:
	void showgameover();
signals:
	void show_congratulation();
private:
	void close();
	int lamp;
	bool isInit;
	bool islastgame;
	void init();
	Ui::game1*ui;
	QPushButton*backbutton;
	QGraphicsScene* sence;
	gamenumber game;
	Boss* boss;
	PlayerFighter* fighter;
	QPixmap sencemap;
	QSound *sound;

	};
