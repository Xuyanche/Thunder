#pragma once
# pragma execution_character_set("utf-8")
#include "start.h"
#include "game1.h"
#include "list.h"
#include<qstring.h>
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Dialog w;
	game1 g(gameone);
	List l;
	l.setWindowTitle(QString("�ɼ�"));
	List people;
	people.setWindowTitle(QString("������Ա"));
	w.show();
	QObject::connect(&w, SIGNAL(showlist()), &l, SLOT(receivestart_fromlist()));
	QObject::connect(&w, SIGNAL(showgame1()), &g, SLOT(receivestart_fromgame1()));
	QObject::connect(&g, SIGNAL(showstart_fromgame1()), &w, SLOT(receive()));
	QObject::connect(&l, SIGNAL(showstart_fromlist()), &w, SLOT(receive()));
	QObject::connect(&w, SIGNAL(showpeople()), &people, SLOT(receivestart_fromlist()));
	return a.exec();
}
