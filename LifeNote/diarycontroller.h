#ifndef DIARYCONTROLLER_H
#define DIARYCONTROLLER_H
#include "includes.h"
#include <QPlainTextEdit>
#include <QLabel>

class Record
{
public:
    Record(QString rec_text, QString rec_path):record_path(rec_path),record_text(rec_text){}
    QString record_text;
    QString record_path;
};
class DiaryController
{
public:

    DiaryController(QPlainTextEdit * editor = nullptr, QLabel * date_label = nullptr, QDate curr_date = QDate::currentDate(), QString dir_path = "storage/diaries/");
    ~DiaryController();
    Record * active_record;
    QDate rec_date;
    Record* FindRecord(QDate date);
    QString DateToFilename(QDate* date);

    void UpdateRecordText();

    void ChangeCurrDate(bool get_next);

    void ChangeActiveRecord(Record * new_record);
    void ChangeActiveRecord();

    void SaveActiveRecord();
private:
    QString diary_dir_path;
    QPlainTextEdit * editor_ptr;
    QLabel * date_label_ptr;
};

#endif // DIARYCONTROLLER_H
