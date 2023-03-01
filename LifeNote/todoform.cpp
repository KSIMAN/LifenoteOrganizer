#include "todoform.h"
#include "ui_todoform.h"
ToDoController::ToDoController()
{

}
ToDoForm::ToDoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToDoForm)
{
    ui->setupUi(this);
    controller.FindDay(ui->dateEdit->date());
    ui->dateEdit->setDate(QDate::currentDate());
    controller.LoadDay(controller.FindDay(ui->dateEdit->date()), ui->doingsLay);
}

ToDoForm::~ToDoForm()
{
    delete ui;
}

void ToDoForm::AnalyzeJson()
{

}


ToDoDay::ToDoDay(QDate d)
{
    date = d;
    edited = false;

}

ToDoDay::~ToDoDay()
{
    doings.clear();
}

void ToDoController::LoadDay(ToDoDay * day, QVBoxLayout* owner)
{
    int j = 0;
    while(owner->itemAt(j)!=nullptr)
        owner->removeItem(owner->itemAt(j));
    for(int i = 0; i < day->doings.size(); i++)
    {
    owner->addWidget(day->doings.at(i));
    }
}

void ToDoController::SaveDay(ToDoDay * day)
{

}

ToDoDay *ToDoController::ConvertObjectToDay(QJsonObject obj)
{
    QDate date =  QDate::fromString(obj["date"].toString(),"dd/MM/yyyy");
    ToDoDay * day = new ToDoDay(date);
    QJsonArray daysjs = obj["items"].toArray();

    for(int i = 0; i< daysjs.size(); i++)
    {
        QString name = daysjs.takeAt(i)["name"].toString();
        TDLitem * item = new TDLitem(nullptr,name , obj["state"].toBool());
        day->doings.push_back(item);
    }
    return day;

}

ToDoDay* ToDoController::FindDay(QDate date)
{
    QFile file(json_path);
    if(file.open(QIODevice::ReadOnly))
    {
        QJsonDocument doc = QJsonDocument::fromJson(QByteArray(file.readAll()), &err);
        QJsonArray days = doc.array();
        for(int i = 0;i < days.size(); i++)
        {
            QJsonObject obj = days[i].toObject();
            QString da = date.toString("dd/MM/yyyy");
            if(obj["date"]== da)
            return ConvertObjectToDay(obj);
        }
    }
    file.close();
    return new ToDoDay(date);
}


void ToDoForm::on_dateEdit_userDateChanged(const QDate &date)
{
    controller.LoadDay(controller.FindDay(ui->dateEdit->date()), ui->doingsLay);

}

