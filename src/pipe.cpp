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
#include "pipe.h"

#include <qpixmap.h>
#include <qpainter.h>
#include "h.xpm"
#include "v.xpm"
#include "x.xpm"
#include "t1.xpm"
#include "t2.xpm"
#include "t3.xpm"
#include "t4.xpm"
#include "logost.xpm"

static const char **pictures[]= {t1_xpm, t2_xpm, t3_xpm, t4_xpm, v_xpm, h_xpm, x_xpm, logost_xpm};


Pipe::Pipe(QWidget* parent, Pipe **tmp, const char* name)
        : QLabel( parent, name ), WaterLevel(0), Direction(None), Tmp(tmp)
{
	setPalette( Qt::white );
	enabled = (bool) tmp;
	if(enabled)
		setType(Nothing);
	else
		setType( (Types) (int) (7.0*rand()/RAND_MAX));
	show();
	setFixedSize( 64, 64 );
}


void Pipe::setType(Types a)
{
	Type=a;
	setPixmap( QPixmap(pictures[(int) Type]) );
}


void Pipe::mousePressEvent ( QMouseEvent * e )
{
	if(enabled && !WaterLevel)
	{
		setType(Tmp[0]->type());
		for(int i=0; i<4; i++)
			Tmp[i]->setType(Tmp[i+1]->type());
		Tmp[4]->setType((Types) (int) (7.0*rand()/(RAND_MAX)));
	}
	repaint();
	QLabel::mousePressEvent(e);
}


void Pipe::paintEvent( QPaintEvent * e)
{
	if(enabled)
	{
		QPainter p(pixmap());
		p.setBrush(blue);
		p.setPen( NoPen );
		switch(Direction)
		{
		case RToL:
			p.drawRect(64-(WaterLevel-1)%64,30,1,4); // horiz
			break;

		case DToU:
			p.drawRect(30,64-((WaterLevel-1)%64),4,1); // vert
			break;

		case LToR:
			p.drawRect((WaterLevel)%64,30,1,4); // horiz
			break;

		case UToD:
			p.drawRect(30,(WaterLevel-1)%64,4,1); // vert
			break;
		default: break;
		}
	}
	QLabel::paintEvent(e);
}


void Pipe::resizeEvent( QResizeEvent* e)
{
	setGeometry( 0, 0, 64, 64 );
	QLabel::resizeEvent(e);
}


Pipe::Directions Pipe::waterIn(Directions direction)
{
	if(!enabled) return None;
	if(direction!=None)
		Direction=direction;
	else
		switch(Type)
		{
		case LToU:
			if(Direction!=UToD && Direction!=LToR && WaterLevel<32)
				Direction=None;
			else if(WaterLevel==32)
					if(Direction==LToR)
						Direction=DToU;
					else
						Direction=RToL;
			break;
		case RToU:
			if(Direction!=RToL && Direction!=UToD && WaterLevel<32)
				Direction=None;
			else if(WaterLevel==32)
					if(Direction==RToL)
						Direction=DToU;
					else
						Direction=LToR;
			break;
		case RToD:
			if(Direction!=RToL && Direction!=DToU && WaterLevel<32)
				Direction=None;
			else if(WaterLevel==32)
					if(Direction==RToL)
						Direction=UToD;
					else
						Direction=LToR;
			break;
		case LToD:
			if(Direction!=LToR && Direction!=DToU && WaterLevel<32)
				Direction=None;
			else if(WaterLevel==32)
					if(Direction==LToR)
						Direction=UToD;
					else
						Direction=RToL;
			break;
		case Cross:
			if(WaterLevel==64 || WaterLevel>=128)
				return None;
			break;
		case Nothing:
			return Direction=None;
		default:
			break;
		};
	if(WaterLevel>=64 && Type!=Cross)
		return None;
	WaterLevel++;
	update();
	return Direction;
}
