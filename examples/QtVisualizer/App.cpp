#include "App.hpp"
#include <QApplication>

App::App(int &argc, char *argv[]):
	QApplication(argc, argv)
{
	setApplicationName("QtTests");
	setApplicationVersion("1.0");
}

