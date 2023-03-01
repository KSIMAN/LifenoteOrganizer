#ifndef NOTEEDITOR_H
#define NOTEEDITOR_H

#include <QWidget>
#include <QPushButton>
#include "includes.h"
namespace Ui {
class NoteEditor;
}

class NoteEditor : public QWidget
{
    Q_OBJECT

public:
    NoteEditor(QWidget *parent = nullptr, QFileInfo * fileinfo = 0, QPushButton * bt_ptr = nullptr);
    ~NoteEditor();

private slots:
    void on_nameedit_textEdited(const QString &arg1);

    void on_savebutton_clicked();

private:
    Ui::NoteEditor *ui;
    QFileInfo * file_info;
    QFile file;
    QPushButton * butt_ptr;
    bool loaded, name_edited;
    void loadText();
    void saveText();
};

#endif // NOTEEDITOR_H
