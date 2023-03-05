#include "todoform.h"
#include "ui_todoform.h"
#include <QDebug>

/* ToDoController class*/

ToDoController::ToDoController()
{
    max_days = 30;
}

ToDoController::~ToDoController()
{
    days.clear();
}
void ToDoController::LoadDay(ToDoDay * day, QVBoxLayout* owner)
{
    ClearLayout(owner);
    for(int i = 0; i < day->doings.size(); i++)
    {
        QString* name = &day->doings[i]->item_name;
        bool* done = &day->doings[i]->done;
        TDLitem * item = new TDLitem(name,done);
        owner->addWidget(item);
    }
}

void ToDoController::ReadDaysInfo()
{

    QFile file(json_path);
    if(file.open(QIODevice::ReadOnly))
    {
        QJsonDocument doc = QJsonDocument::fromJson(QByteArray(file.readAll()), &err);
        QJsonArray day_objects = doc.array();
        for(int i = 0;i < day_objects.size(); i++)
        {
            QJsonObject obj = day_objects[i].toObject();
            days.push_back(ConvertObjectToDay(obj));
        }
    }
    file.close();
}

bool ToDoController::RemoveOldData(QList<DoingItem*> * list, int max)
{
    while(list->size() > max)
        list->remove(0);
}

QJsonObject ToDoController::SerializeDay(ToDoDay * day)
{
    QJsonObject day_obj;
    day_obj.insert("date", day->getDateInString());
    day_obj.insert("items", ConvertDoingsToJson(day));
    return day_obj;
}

void ToDoController::WriteDaysInfo()
{
    QJsonArray days_array;
    int i = 0;
    while(i<days.size())
    {
        days_array.insert(i,SerializeDay(days[i]));
        i++;
    }
    QJsonDocument document;
       document.setArray(days_array);
       QByteArray bytes = document.toJson( QJsonDocument::Indented );
       QFile file(json_path);
       if( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) )
       {
           QTextStream iStream(&file);
           iStream << bytes;
           file.close();
       }
}

QJsonArray ToDoController::ConvertDoingsToJson(ToDoDay *day)
{
    QJsonArray doings_json;
    for(int i = 0; i < day->doings.size(); i++)
    {
        DoingItem * doing_item = day->doings[i];
        if(doing_item->nameNotEmpty())
        {
           QJsonObject doing_obj;
           doing_obj.insert("name", doing_item->item_name);
           doing_obj.insert("state", doing_item->done);
           doings_json.push_back(doing_obj);
        }else break;
    }
    return doings_json;
}

void ToDoController::ClearLayout(QVBoxLayout *owner)
{
    while(owner->itemAt(0)!=nullptr)
    {
        QLayoutItem * item_ptr = owner->itemAt(0);
        owner->removeItem(item_ptr);
        delete item_ptr;
    }
}

ToDoDay *ToDoController::ConvertObjectToDay(QJsonObject obj)
{
    QDate date =  QDate::fromString(obj["date"].toString(),"dd/MM/yyyy");
    ToDoDay * day = new ToDoDay(date);
    QJsonArray doingsjs = obj["items"].toArray();
    for(int i = 0; i< doingsjs.size(); i++)
    {
        QString name = doingsjs.at(i)["name"].toString();
        DoingItem * item = new DoingItem(name, doingsjs.at(i)["state"].toBool());
        day->doings.push_back(item);
    }
    return day;
}

ToDoDay* ToDoController::FindDay(QDate date)
{
    QString find_date = date.toString("dd/MM/yyyy");
    for(int i = 0; i < days.size(); i++)
    {
        QString object_date = days[i]->date.toString("dd/MM/yyyy");
        if(find_date == object_date)
           return days[i];
    }
    ToDoDay * new_day = new ToDoDay(date);
    days.push_back(new_day);
    return new_day;
}

/*ToDoDay class*/

ToDoDay::ToDoDay(QDate d)
{
    date = d;
    edited = false;
}

ToDoDay::~ToDoDay()
{
    doings.clear();
}

QString ToDoDay::getDateInString()
{
    return date.toString("dd/MM/yyyy");
}

/* ToDoForm class*/

ToDoForm::ToDoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToDoForm)
{
    ui->setupUi(this);
    controller.ReadDaysInfo();
    ui->dateEdit->setDate(QDate::currentDate());
    active_day = controller.FindDay(ui->dateEdit->date());
    controller.LoadDay(active_day, ui->doingsLay);
}

void ToDoForm::AddNewDoing()
{
    DoingItem * empty_item = new DoingItem("", false);
    active_day->doings.push_back(empty_item);
    ui->doingsLay->addWidget(new TDLitem(&empty_item->item_name, &empty_item->done ));
}

ToDoForm::~ToDoForm()
{
    delete ui;
}


void ToDoForm::on_dateEdit_userDateChanged(const QDate &date)
{
    controller.LoadDay(controller.FindDay(ui->dateEdit->date()), ui->doingsLay);
}


void ToDoForm::on_saveButtton_clicked()
{
    controller.WriteDaysInfo();
}


void ToDoForm::on_addDoing_Butt_clicked()
{
    AddNewDoing();
}

