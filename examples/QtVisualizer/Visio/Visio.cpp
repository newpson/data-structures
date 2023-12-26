#include "Visio.hpp"
#include "ui_Visio.h"

#include <QWidget>
#include <QMainWindow>

Visio::Visio(QWidget *parent):
	QMainWindow(parent)
{
	setupUi(this);
}
