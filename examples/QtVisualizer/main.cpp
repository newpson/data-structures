#include "Visio.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	Visio visio;
	visio.show();

	return app.exec();
}

