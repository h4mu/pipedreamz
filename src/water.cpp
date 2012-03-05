/***************************************************************************
 *   Copyright (C) 2004 by Tamás "H4MU" Hámor                              *
 *   hamu@lamer.hu                                                         *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "water.h"
#include "pipedreamz.h"


Water::Water(Pipe *** r, const int rows, const int columns, QObject *parent, const int g, const char *name)
		: QObject(parent, name), Points(10), pipe(r), maxx(columns-1), maxy(rows-1)
{
	startTimer(g);
	x = maxx/2;
	y = maxy/2;
	pipe[x][y]->setType(Pipe::Horiz);
	pipe[x][y]->waterIn(Pipe::LToR);
}


Water::~Water()
{
	killTimers();
}


void Water::timerEvent ( QTimerEvent * )
{
	Points++;
	((PipeDreamz*)parent())->statusBar()->message( tr("Points: %1").arg(Points), 2000 );

	if(pipe[x][y]->waterIn() == Pipe::None)
		switch(pipe[x][y]->direction())		// None, RToL, DToU, LToR, UToD
		{
		case Pipe::RToL:
			if(x>=1)
			{
				pipe[x-1][y]->waterIn(pipe[x][y]->direction());
				x--;
				return;
			}
			break;
		case Pipe::LToR:
			if(x<maxx)
			{
				pipe[x+1][y]->waterIn(pipe[x][y]->direction());
				x++;
				return;
			}
			break;
		case Pipe::DToU:
			if(y>=1)
			{
				pipe[x][y-1]->waterIn(pipe[x][y]->direction());
				y--;
				return;
			}
			break;
		case Pipe::UToD:
			if(y<maxy)
			{
				pipe[x][y+1]->waterIn(pipe[x][y]->direction());
				y++;
				return;
			}
		default:
			break;
		}
	else if (pipe[x][y]->type() != Pipe::Nothing)
		return;
	killTimers();		// FATAL: STOP
	((PipeDreamz*)parent())->lost(Points);
}
