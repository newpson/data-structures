#include "NAirlines.hpp"
#include <QApplication>
#include <random>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	NAirlines terminal;
	terminal.show();

	return app.exec();
}

