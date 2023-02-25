#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QWidget>
#include "includes.h"
namespace Ui {
class NoteEditor;
}

class NoteEditor : public QWidget
{
    Q_OBJECT

public:
    NoteEditor(QWidget *parent = nullptr, QFileInfo * fileinfo = 0);
    ~NoteEditor();

private slots:
    void on_nameedit_textEdited(const QString &arg1);

    void on_savebutton_clicked();

private:
    Ui::NoteEditor *ui;
    QFileInfo * file_info;
    QFile file;
    bool loaded, name_edited;
    void loadText();
    void saveText();
};

#endif // NOTEEDITOR_H
