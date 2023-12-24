#include "App.hpp"
#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
	App app(argc, argv);

	MainWindow main_window;
	main_window.show();

	return app.exec();
}

