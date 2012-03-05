/****************************************************************************
** Form implementation generated from reading ui file 'src/form1.ui'
**
** Created: Wed Dec 15 12:21:01 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#include "form1.h"

#include <qvariant.h>
#include <qlabel.h>
#include <qspinbox.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>

/*
 *  Constructs a Form1 as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  TRUE to construct a modal dialog.
 */
Form1::Form1( QWidget* parent, const char* name, bool modal, WFlags fl )
    : QDialog( parent, name, modal, fl )
{
    if ( !name )
	setName( "Form1" );

    textLabel3 = new QLabel( this, "textLabel3" );
    textLabel3->setGeometry( QRect( 10, 40, 270, 20 ) );

    textLabel1 = new QLabel( this, "textLabel1" );
    textLabel1->setGeometry( QRect( 10, 10, 60, 20 ) );

    textLabel2 = new QLabel( this, "textLabel2" );
    textLabel2->setGeometry( QRect( 220, 10, 80, 20 ) );

    rows = new QSpinBox( this, "rows" );
    rows->setGeometry( QRect( 80, 10, 55, 21 ) );
    rows->setMinValue( 3 );
    rows->setValue( 5 );

    columns = new QSpinBox( this, "columns" );
    columns->setGeometry( QRect( 310, 10, 55, 21 ) );
    columns->setMinValue( 3 );
    columns->setValue( 5 );

    speed = new QSpinBox( this, "speed" );
    speed->setGeometry( QRect( 310, 40, 55, 21 ) );
    speed->setMaxValue( 1000 );
    speed->setMinValue( 1 );
    speed->setValue( 100 );

    pushButton1 = new QPushButton( this, "pushButton1" );
    pushButton1->setGeometry( QRect( 60, 80, 270, 50 ) );
    languageChange();
    resize( QSize(377, 140).expandedTo(minimumSizeHint()) );
    clearWState( WState_Polished );

    // signals and slots connections
    connect( pushButton1, SIGNAL( clicked() ), this, SLOT( accept() ) );

    // tab order
    setTabOrder( pushButton1, rows );
    setTabOrder( rows, columns );
    setTabOrder( columns, speed );
}

/*
 *  Destroys the object and frees any allocated resources
 */
Form1::~Form1()
{
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void Form1::languageChange()
{
    setCaption( tr( "New Game" ) );
    QToolTip::add( this, trUtf8( "\x48\x69\x65\x72\x6d\x69\x74\x20\x6b\xc3\xb6\x6e\x6e\x65\x6e\x20\x53\x69\x65\x20\x69\x68\x72\x20\x6e\x65\x75\x65\x73\x20\x53\x70\x69\x65\x6c\x20\x65\x69\x6e\x73\x74\x65\x6c\x6c\x65\x6e" ) );
    textLabel3->setText( tr( "Speed (smaller means faster):" ) );
    textLabel1->setText( tr( "Rows:" ) );
    textLabel2->setText( tr( "Columns:" ) );
    QToolTip::add( rows, tr( "Anzahl der Zeilen" ) );
    QToolTip::add( columns, tr( "Anzalh der Spalten" ) );
    pushButton1->setText( tr( "START GAME!" ) );
    QToolTip::add( pushButton1, trUtf8( "\x44\x72\xc3\xbc\x63\x6b\x65\x6e\x20\x53\x69\x65\x20\x64\x69\x65\x73\x65\x73\x20\x4b\x6e\x6f\x70\x66\x20\x75\x6d\x20\x64\x61\x73\x20\x53\x70\x69\x65\x6c\x20\x7a\x75\x20\x62\x65\x67\x69\x6e\x6e\x65\x6e" ) );
}

