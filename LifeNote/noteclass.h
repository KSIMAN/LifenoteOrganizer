#ifndef NOTECLASS_H
#define NOTECLASS_H

#include <QPushButton>
#include "includes.h"
class NoteClass : public QObject
{
    Q_OBJECT
public:
    NoteClass(QString ntpath, QWidget *  parent);
    QPushButton * button;
    QString notename, notetext, notepath;
    QFile note;
    QFileInfo info;
public slots:
   void  ButtonPressed();

};

#endif // NOTECLASS_H
