#include "noteclass.h"
#include <QApplication>
#include "noteeditor.h"
NoteClass::NoteClass(QString ntpath, QWidget * parent)
{
    button = new QPushButton(parent);
    button->setVisible(true);
    notepath = ntpath;
    note.setFileName(notepath);
    info.setFile(notepath);
    notename = info.fileName();


    if (!note.open(QIODevice::ReadWrite | QIODevice::Text))
        button->setText("Заметка повреждена или перенесена");
    else {
           QByteArray * histogramByteArray =  new QByteArray(note.readAll());
           notetext = *histogramByteArray;
           delete histogramByteArray;
           button->setText(notename + '\n' + notetext);
        }
    note.close();
}

void NoteClass::ButtonPressed()
{
    NoteEditor * editor = new NoteEditor(nullptr, &info);
    editor->setVisible(true);
}

