#pragma once
# pragma execution_character_set("utf-8")
#include "start.h"
#include "game1.h"
#include "list.h"
#include "gameover.h"
#include<qstring.h>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Dialog w;
	game1 g1(gameone);
	game1 g2(gametwo);
	gameover o;
	List l;
	l.setWindowTitle(QString("成绩"));
	List people;
	people.setWindowTitle(QString("制作人员"));
	w.show();
	QObject::connect(&w, SIGNAL(showlist()), &l, SLOT(receivestart_fromlist()));
	QObject::connect(&w, SIGNAL(showgame1()), &g1, SLOT(receive_fromgame1()));
	QObject::connect(&g1, SIGNAL(show_fromgame1()), &w, SLOT(receive()));
	QObject::connect(&l, SIGNAL(showstart_fromlist()), &w, SLOT(receive()));
	QObject::connect(&w, SIGNAL(showpeople()), &people, SLOT(receivestart_fromlist()));
	QObject::connect(&g1, SIGNAL(show_next()), &g2, SLOT(receive_fromgame1()));
	QObject::connect(&g2, SIGNAL(show_fromgame1()), &w, SLOT(receive()));
	QObject::connect(&g1, SIGNAL(showgameover()), &o, SLOT(receive()));
	QObject::connect(&g2, SIGNAL(showgameover()), &o, SLOT(receive()));
	QObject::connect(&o, SIGNAL(show_start()), &w, SLOT(receive()));
	QObject::connect(&o, SIGNAL(show_gameone()), &g1, SLOT(receive_fromgame1()));
	return a.exec();
	return a.exec();
}
