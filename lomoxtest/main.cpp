//#include <QtGui/QApplication> //QT5.0已经替换成QtWidgets
#include <QtWidgets/QApplication>
#include "../lomox/lxcoreprivate.h"

int main(int argc, char *argv[])
{
	lxCoreApp->runLomoxApp(argc,argv);
	return 0;
}
