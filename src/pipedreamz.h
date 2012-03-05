#ifndef PIPEDREAMZ_H
#define PIPEDREAMZ_H

#include <qmainwindow.h>
#include <qstatusbar.h>
#include <qgrid.h>
#include "pipe.h"
#include "water.h"
#include "form1.h"

class PipeDreamz: public QMainWindow
{
	Q_OBJECT

public:
	PipeDreamz();
	~PipeDreamz();
	void lost(unsigned long punkte = 0);

protected:
	Pipe *** pipes;
	Pipe **Tmp;
	Water* water;

private slots:
	void newGame();
	void about();
	void aboutQt();

private:
	QGrid* left;
	QGrid* right;
	QGrid* cw;
	int rows;
	int columns;
	int speed;
	Form1* newForm;
};


#endif
