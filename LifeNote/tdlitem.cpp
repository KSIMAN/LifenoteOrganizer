#include "tdlitem.h"
#include "ui_tdlitem.h"
#include <QVBoxLayout>

TDLitem::TDLitem(QString * itemname, bool * don) :
    ui(new Ui::TDLitem),
    item_name(itemname),
    done(don)
{
    ui->setupUi(this);
    ui->itemname->setText(*itemname);
    ui->done_chb->setChecked(*don);
    setVisible(true);
}

TDLitem::~TDLitem()
{
    delete ui;
}

void TDLitem::DestroyObject()
{
    destroy(true,true);
}


void TDLitem::on_itemname_textChanged(const QString &arg1)
{
    *item_name = ui->itemname->text();
}

void TDLitem::on_done_chb_stateChanged(int arg1)
{
    *done = ui->done_chb->isChecked();
}


DoingItem::DoingItem(QString itemname, bool don)
{
    item_name = itemname;
    done = don;
}

bool DoingItem::nameNotEmpty()
{
    if(item_name != "")
        return true;
    else return false;
}
