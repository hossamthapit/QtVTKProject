#include <QtWidgets/QApplication>
#include <MainWindow.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	MainWindow mainwidnow;

	mainwidnow.show();

	return app.exec();
}