#include <QApplication>
#include "djumbo.h"
int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	Djumbo djumbo;
	djumbo.show();
	return app.exec();
}

