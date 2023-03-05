#ifndef TODOFORM_H
#define TODOFORM_H
#include <QList>
#include <QWidget>
#include <tdlitem.h>
#include <QJsonDocument>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QVBoxLayout>
#include <QJsonParseError>
namespace Ui {
class ToDoForm;
}
class ToDoDay
{
public:
    ToDoDay(QDate d);
    ~ToDoDay();
    QDate date;
    QString getDateInString();
    bool edited;
    QList<DoingItem*> doings;

};
class ToDoController
{
public:
    ToDoController();
   ~ToDoController();
    QString json_path = "storage/doings/doings.json";
    void LoadDay(ToDoDay * day,QVBoxLayout* owner);

    void ReadDaysInfo();
    void WriteDaysInfo();
    bool RemoveOldData(QList<DoingItem*> * list, int max); //check and remove old days info
    int max_days;

    QList<ToDoDay*> days;
    QJsonObject SerializeDay(ToDoDay * day);
    QJsonArray ConvertDoingsToJson(ToDoDay * day);
    void ClearLayout(QVBoxLayout* owner);
    ToDoDay *ConvertObjectToDay(QJsonObject obj);
    void AddDoing();
    ToDoDay* FindDay(QDate date);
private:
    //ToDoDay *active_day_ptr;
    QJsonParseError err;
};

class ToDoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ToDoForm(QWidget *parent = nullptr);
    void AddNewDoing(); // add Empty doing to active_day
    void SetDeleteModeEnable();
    ~ToDoForm();

private slots:

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_saveButtton_clicked();

    void on_addDoing_Butt_clicked();

private:
    Ui::ToDoForm *ui;
    int max_count;
    QJsonDocument items_doc;
    ToDoDay * active_day;
    ToDoController controller;

};


#endif // TODOFORM_H
