#pragma once

#include <QDialog>
namespace Ui { class congratulation; };

class congratulation : public QDialog
{
	Q_OBJECT

public:
	congratulation(QWidget *parent = Q_NULLPTR);
	~congratulation();
private slots:
	void on_backbutton_clicked_gameover();
	void on_restartbutton_clicked_gameover();
	void receive();
signals:
	void show_start();
signals:
	void show_gameone();
private:
	Ui::congratulation *ui;
};
