#include "noteform.h"
#include "ui_noteform.h"

NoteForm::NoteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteForm)
{
    ui->setupUi(this);
    note_index = 1;
    LoadNotes();
}

NoteForm::~NoteForm()
{
    delete ui;
}

void NoteForm::LoadNotes()
{
    QDir dir(notedir);
    for (const QFileInfo &file : dir.entryInfoList(QDir::Files))
    {
        AddNote(file.filePath());
    }
}

void NoteForm::CreateNote()
{
    QString notepath = notedir + "/note" + QString::number(note_index) + ".txt" ;
    AddNote(notepath);
}

void NoteForm::AddNote(QString path)
{
    NoteClass * note = new NoteClass(path, ui->scrollArea);
    ui->notes_Lay->addWidget(note->button);
    notes.push_back(note);
    connect(note->button, &QPushButton::pressed, note, &NoteClass::ButtonPressed);
    note_index++;
}

void NoteForm::on_add_butt_clicked()
{
    CreateNote();
}

