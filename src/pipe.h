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
#ifndef PIPE_H
#define PIPE_H

#include <cstdlib>
#include <qlabel.h>

/**
Pipe is an entity that can hold a given amount of water

@author Tamás "H4MU" Hámor
*/
class Pipe : public QLabel
{
		Q_OBJECT

public:
	enum Directions { None, RToL, DToU, LToR, UToD };
	enum Types { LToU, RToU, RToD, LToD, Vert, Horiz, Cross, Nothing };
	Pipe(QWidget* parent = 0, Pipe** tmp = 0, const char * name = 0);
//	~Pipe();

	void resizeEvent( QResizeEvent * );
	void paintEvent( QPaintEvent * );
	Directions waterIn(Directions direction = None);
	Types type() const {return Type;}
	void setType(Types a);
	Directions direction() const {return Direction;}

private:
	int WaterLevel;
	bool enabled;
	Directions Direction;
	Pipe ** Tmp;
	void mousePressEvent( QMouseEvent * );
	Types Type;
};

#endif
