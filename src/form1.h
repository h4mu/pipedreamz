/****************************************************************************
** Form interface generated from reading ui file 'src/form1.ui'
**
** Created: Wed Dec 15 12:20:38 2004
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.3   edited Nov 24 2003 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FORM1_H
#define FORM1_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QSpinBox;
class QPushButton;

class Form1 : public QDialog
{
    Q_OBJECT

public:
    Form1( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Form1();

    QLabel* textLabel3;
    QLabel* textLabel1;
    QLabel* textLabel2;
    QSpinBox* rows;
    QSpinBox* columns;
    QSpinBox* speed;
    QPushButton* pushButton1;

protected:

protected slots:
    virtual void languageChange();

};

#endif // FORM1_H
