/****************************************************************************
** PipeDreamz meta object code from reading C++ file 'pipedreamz.h'
**
** Created: Wed Dec 15 12:21:11 2004
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "pipedreamz.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *PipeDreamz::className() const
{
    return "PipeDreamz";
}

QMetaObject *PipeDreamz::metaObj = 0;
static QMetaObjectCleanUp cleanUp_PipeDreamz( "PipeDreamz", &PipeDreamz::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString PipeDreamz::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PipeDreamz", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString PipeDreamz::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "PipeDreamz", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* PipeDreamz::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QMainWindow::staticMetaObject();
    static const QUMethod slot_0 = {"newGame", 0, 0 };
    static const QUMethod slot_1 = {"about", 0, 0 };
    static const QUMethod slot_2 = {"aboutQt", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "newGame()", &slot_0, QMetaData::Private },
	{ "about()", &slot_1, QMetaData::Private },
	{ "aboutQt()", &slot_2, QMetaData::Private }
    };
    metaObj = QMetaObject::new_metaobject(
	"PipeDreamz", parentObject,
	slot_tbl, 3,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_PipeDreamz.setMetaObject( metaObj );
    return metaObj;
}

void* PipeDreamz::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "PipeDreamz" ) )
	return this;
    return QMainWindow::qt_cast( clname );
}

bool PipeDreamz::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: newGame(); break;
    case 1: about(); break;
    case 2: aboutQt(); break;
    default:
	return QMainWindow::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool PipeDreamz::qt_emit( int _id, QUObject* _o )
{
    return QMainWindow::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool PipeDreamz::qt_property( int id, int f, QVariant* v)
{
    return QMainWindow::qt_property( id, f, v);
}

bool PipeDreamz::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
