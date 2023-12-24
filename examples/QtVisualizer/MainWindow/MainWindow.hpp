#pragma once
#include "ui_MainWindow.h"
#include <QMainWindow>
#include <QWidget>

class MainWindow: public QMainWindow, Ui::MainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
};
