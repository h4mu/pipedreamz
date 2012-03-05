#include <qapplication.h>
#include "pipedreamz.h"

int main( int argc, char ** argv ) {
	QApplication a( argc, argv );
	PipeDreamz * mw = new PipeDreamz();
	mw->setCaption( "PipeDreamz" );
	mw->show();
	a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
	return a.exec();
}
