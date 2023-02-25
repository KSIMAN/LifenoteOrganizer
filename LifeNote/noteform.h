#ifndef NOTEFORM_H
#define NOTEFORM_H

#include <QWidget>
#include "noteclass.h"
#include "includes.h"
namespace Ui {
class NoteForm;
}

class NoteForm : public QWidget
{
    Q_OBJECT

public:
    explicit NoteForm(QWidget *parent = nullptr);
    ~NoteForm();
    QString notedir = QDir::currentPath() + "/storage/notes";
private slots:
    void on_add_butt_clicked();

private:
    Ui::NoteForm *ui;
    int note_index;
    std::vector<NoteClass*> notes;
    void LoadNotes();
    void CreateNote();
    void AddNote( QString path);
};

#endif // NOTEFORM_H
