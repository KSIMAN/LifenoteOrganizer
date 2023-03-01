#ifndef TODOFORM_H
#define TODOFORM_H
#include <QList>
#include <QWidget>
#include <tdlitem.h>
#include <QJsonDocument>
#include <QFile>
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
    bool edited;
    QList<TDLitem*> doings;

};
class ToDoController
{
public:
    ToDoController();
  //  ~ToDoController();
    QString json_path = "storage/doings/doings.json";
    void LoadDay(ToDoDay * day,QVBoxLayout* owner);
    void SaveDay(ToDoDay * day);
    ToDoDay *ConvertObjectToDay(QJsonObject obj);
    ToDoDay* FindDay(QDate date);
    QJsonParseError err;
};

class ToDoForm : public QWidget
{
    Q_OBJECT

public:
    explicit ToDoForm(QWidget *parent = nullptr);
    ~ToDoForm();

private slots:
    void on_dateEdit_dateChanged(const QDate &date);


    void on_dateEdit_editingFinished();

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::ToDoForm *ui;
    int max_count;
    QJsonDocument items_doc;
    ToDoDay * active_day;
    ToDoController controller;
    void AnalyzeJson();
    void addTask();
};


#endif // TODOFORM_H
