#include "noteeditor.h"
#include "ui_noteeditor.h"

NoteEditor::NoteEditor(QWidget *parent, QFileInfo * fileinfo, QPushButton * bt_ptr) :
    QWidget(parent),
    ui(new Ui::NoteEditor),
    file_info(fileinfo),
    butt_ptr(bt_ptr)
{
    ui->setupUi(this);
    file.setFileName(file_info->filePath());
    loaded = false;
    name_edited = false;
    loadText();

}

NoteEditor::~NoteEditor()
{
    delete ui;
}

void NoteEditor::on_nameedit_textEdited(const QString &arg1)
{
    name_edited = true;
}

void NoteEditor::loadText()
{
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;
    QString text = file.readAll();
    ui->plainTextEdit->setPlainText(text);
    ui->nameedit->setText(file_info->fileName());
    loaded = true;
    file.close();
}

void NoteEditor::saveText()
{
    if(!loaded)
    return;

    if(!file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate))
        return;
    file.write(ui->plainTextEdit->toPlainText().toStdString().c_str());
    file.close();

    if(name_edited)
    {
        QString newname = ui->nameedit->text() ;
        file.rename(file_info->path() + "/" + newname);
        butt_ptr->setText(newname);
    }


}


void NoteEditor::on_savebutton_clicked()
{
    saveText();
    close();
}

