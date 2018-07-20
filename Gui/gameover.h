#pragma once

#include <QDialog>
namespace Ui { class gameover; };

class gameover : public QDialog
{
	Q_OBJECT

public:
	gameover(QWidget *parent = Q_NULLPTR);
	~gameover();
private slots:
	void on_backbutton_clicked_gameover();
	void on_restartbutton_clicked_gameover();
	void receive();
signals:
	void show_start();
signals:
	void show_gameone();
private:
	Ui::gameover *ui;
};
