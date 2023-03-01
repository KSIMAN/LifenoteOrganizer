#include "tdlitem.h"
#include "ui_tdlitem.h"

TDLitem::TDLitem(QWidget *parent, QString itemname, bool don) :
    QWidget(parent),
    ui(new Ui::TDLitem),
    item_name(itemname),
    done(don)
{
    ui->setupUi(this);
    ui->itemname->setText(item_name);
    setVisible(true);
}

TDLitem::~TDLitem()
{
    delete ui;
}

void TDLitem::on_itemname_textChanged(const QString &arg1)
{
    item_name = ui->itemname->text();
}

void TDLitem::on_done_chb_stateChanged(int arg1)
{
    done = ui->done_chb->isChecked();
}

