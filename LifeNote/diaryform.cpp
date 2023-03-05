#include "diaryform.h"
#include "ui_diaryform.h"

DiaryForm::DiaryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryForm)
{
    ui->setupUi(this);
    diary_controller = new DiaryController(ui->textEdit, ui->date_label, QDate::currentDate(), "storage/diaries/");

}

DiaryForm::~DiaryForm()
{
    delete ui;
}

void DiaryForm::on_previousdate_clicked()
{
    diary_controller->ChangeCurrDate(false);
}


void DiaryForm::on_next_date_clicked()
{
    diary_controller->ChangeCurrDate(true);
}


void DiaryForm::on_save_butt_clicked()
{
     diary_controller->SaveActiveRecord();
}

