/****************************************************************************
** Pipe meta object code from reading C++ file 'pipe.h'
**
** Created: Wed Dec 15 12:21:07 2004
**      by: The Qt MOC ($Id: qt/moc_yacc.cpp   3.3.3   edited Aug 5 16:40 $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "pipe.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *Pipe::className() const
{
    return "Pipe";
}

QMetaObject *Pipe::metaObj = 0;
static QMetaObjectCleanUp cleanUp_Pipe( "Pipe", &Pipe::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString Pipe::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Pipe", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString Pipe::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "Pipe", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* Pipe::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QLabel::staticMetaObject();
    metaObj = QMetaObject::new_metaobject(
	"Pipe", parentObject,
	0, 0,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_Pipe.setMetaObject( metaObj );
    return metaObj;
}

void* Pipe::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "Pipe" ) )
	return this;
    return QLabel::qt_cast( clname );
}

bool Pipe::qt_invoke( int _id, QUObject* _o )
{
    return QLabel::qt_invoke(_id,_o);
}

bool Pipe::qt_emit( int _id, QUObject* _o )
{
    return QLabel::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool Pipe::qt_property( int id, int f, QVariant* v)
{
    return QLabel::qt_property( id, f, v);
}

bool Pipe::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
