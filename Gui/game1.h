#pragma once
#pragma execution_character_set("utf-8")

#include <QMainwindow>
#include"QPushButton"
#include"qgraphicsscene.h"
#include"qgraphicswidget.h"
namespace Ui { class MainWindow; };
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
	Ui::MainWindow *ui;
	QPushButton*backbutton;
	QGraphicsScene*scene;
	QGraphicsView*view;
};
