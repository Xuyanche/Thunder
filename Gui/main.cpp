#include "start.h"
#include "game1.h"
#include "list.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
	game1 g;
	list l;
    w.show();
	QObject::connect(&w, SIGNAL(showlist()), &l, SLOT(receivestart_fromlist()));
	QObject::connect(&w, SIGNAL(showgame1()), &g, SLOT(receivestart_fromgame1()));
	QObject::connect(&g, SIGNAL(showstart_fromgame1()), &w, SLOT(receive()));
	QObject::connect(&l, SIGNAL(showstart_fromlist()), &w, SLOT(receive()));
    return a.exec();
}
