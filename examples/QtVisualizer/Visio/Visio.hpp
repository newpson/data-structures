#pragma once
#include "ui_Visio.h"

#include <QWidget>
#include <QMainWindow>

class Visio: public QMainWindow, Ui::Visio
{
	Q_OBJECT
public:
	Visio(QWidget *parent = nullptr);
};
