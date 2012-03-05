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
#ifndef WATER_H
#define WATER_H

#include <qobject.h>
#include "pipe.h"

/**
In Element, der fliesst :)

@author Tamás "H4MU" Hámor
*/
class Water : public QObject
{
		Q_OBJECT
public:
	Water(Pipe*** r, const int rows, const int columns, QObject *parent, const int g = 100, const char *name = 0);
	~Water();
	void timerEvent ( QTimerEvent * );

private:
	unsigned long Points;
	Pipe *** pipe;
	int x;
	int y;
	const int maxx;
	const int maxy;
};

#endif
