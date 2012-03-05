#include "pipedreamz.h"

#include <qpixmap.h>
#include <qpopupmenu.h>
#include <qmenubar.h>
#include <qmessagebox.h>
#include <qapplication.h>
#include <qaccel.h>
#include <qpainter.h>
#include <qpaintdevicemetrics.h>
#include <qwhatsthis.h>

#include <qspinbox.h>	// a Form1-hez
#include <qgrid.h>
#include "pipe.h"

PipeDreamz::PipeDreamz()
    : QMainWindow( 0, "PipeDreamz", WDestructiveClose )
{
	QPopupMenu * file = new QPopupMenu( this );
	menuBar()->insertItem( tr("&File"), file );


	file->insertItem( tr("&Neues Game"), this, SLOT(newGame()), CTRL+Key_N );

	file->insertItem( tr("&Quit"), qApp, SLOT( closeAllWindows() ), CTRL+Key_Q );

	menuBar()->insertSeparator();

	QPopupMenu * help = new QPopupMenu( this );
	menuBar()->insertItem( tr("&Help"), help );

	help->insertItem( tr("&About"), this, SLOT(about()), Key_F1 );
	help->insertItem( tr("About &Qt"), this, SLOT(aboutQt()) );
	help->insertSeparator();
	help->insertItem( tr("What's &This"), this, SLOT(whatsThis()), SHIFT+Key_F1 );

	pipes = (Pipe***) 0;

	newGame();
}


PipeDreamz::~PipeDreamz()
{
	delete water;
	delete [] pipes;
	for(int i=0; i<5; i++)
		delete Tmp[i];
	delete left;
	delete right;
	delete cw;
}



void PipeDreamz::newGame()
{
	newForm = new Form1(this);
	if(pipes)
	{
		delete water;
		for(int i=0; i<columns; i++)
		{
			for(int j=0; j<rows; j++)
				delete pipes[i][j];
			delete [] pipes[i];
		}
		delete [] pipes;
		delete [] Tmp;
		delete right;
		delete left;
		delete cw;
	}

	if(newForm->exec())
	{
		rows = newForm->rows->value();
		columns = newForm->columns->value();
		speed = newForm->speed->value();
	} else 
		exit(0);
	delete newForm;
	show();
	cw = new QGrid(2,this);
	cw->setSpacing(5);
	cw->setFocus();
	cw->show();
	setCentralWidget(cw);


	left = new QGrid(rows, Vertical, cw);
	right = new QGrid(1, cw);

	left->show();
	right->show();

	Tmp = new Pipe* [5];
	for(int i=0; i<5; i++)
		Tmp[i] = new Pipe(right);
	pipes = new Pipe ** [columns];
	for(int i=0; i<columns; i++)
	{
		pipes[i]= new Pipe * [rows];
		for(int j=0; j<rows; j++)
		{
			pipes[i][j] = new Pipe(left, Tmp);
			pipes[i][j]->setEnabled(true);
			pipes[i][j]->show();
		}
	}

	water = new Water(pipes, rows, columns, this, speed);
	statusBar()->message( tr("Ready"), 2000 );
	setFixedSize( sizeHint() );
}


void PipeDreamz::about()
{
	QMessageBox::about( this, tr("Pipe Dreams for Qt"),
				tr("The popular Game with Pipes and Water "
				"\nA Multi-Platform remake by Tamás \"HAMU\" Hámor"));
}


void PipeDreamz::aboutQt()
{
	QMessageBox::aboutQt( this, tr("Qt PipeDreamz") );
}


void PipeDreamz::lost(unsigned long punkte)
{
	if(QMessageBox::warning(this,tr("Game Over"), tr("Unfortunately this game is over, but you can try again!\n\n"
										"You had %1 Points!\n"
										"Would you like to play again?").arg(punkte), QMessageBox::Retry, QMessageBox::Cancel)==QMessageBox::Retry)
		newGame();
	else
		this->close();
}
