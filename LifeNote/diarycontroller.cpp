#include "diarycontroller.h"

DiaryController::DiaryController(QPlainTextEdit * editor, QLabel * date_label, QDate curr_date, QString dir_path) :
    diary_dir_path(dir_path),
    editor_ptr(editor),
    rec_date(curr_date),
    date_label_ptr(date_label)
{
    active_record = FindRecord(rec_date);
    editor_ptr->setPlainText(active_record->record_text);
}

DiaryController::~DiaryController()
{
    delete active_record;
}

Record* DiaryController::FindRecord(QDate date)
{
    QString date_str = DateToFilename(&date);
    QDir dir(diary_dir_path);
    date_label_ptr->setText(date.toString("dd/MM/yyyy"));
    for(const QFileInfo &file_info : dir.entryInfoList(QDir::Files))
    {
        if(file_info.fileName()==date_str)
        {
            QFile file(file_info.filePath());
            if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return new Record("Проблема с файлом:(", date_str);
            QString text = QString(file.readAll().toStdString().c_str());
            return new Record(text, file.fileName());
        }
    }
    return new Record("", diary_dir_path + date_str);
}

QString DiaryController::DateToFilename(QDate *date)
{
    return date->toString("dd_MM_yyyy");
}

void DiaryController::UpdateRecordText()
{
    active_record->record_text = editor_ptr->toPlainText();
}

void DiaryController::ChangeCurrDate(bool get_next)
{
    int it;
    if(get_next)
    {
        if(rec_date == QDate::currentDate())
            return; // check if its feauture
        it = 1;
    }
    else it = -1;
        rec_date = rec_date.addDays(it);
        ChangeActiveRecord();

}

void DiaryController::ChangeActiveRecord(Record *new_record)
{
    SaveActiveRecord();
    active_record = new_record;
    editor_ptr->setPlainText(active_record->record_text);
}

void DiaryController::ChangeActiveRecord()
{
   SaveActiveRecord();
   active_record = FindRecord(rec_date);
   editor_ptr->setPlainText(active_record->record_text);
}

void DiaryController::SaveActiveRecord()
{
    UpdateRecordText();
    if(active_record->record_text.isEmpty())
        return;
    QFile file(active_record->record_path);
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream iStream(&file);
        iStream << active_record->record_text;
        file.close();
    }

}
