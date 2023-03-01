#ifndef TDLITEM_H
#define TDLITEM_H

#include <QWidget>

namespace Ui {
class TDLitem;
}

class TDLitem : public QWidget
{
    Q_OBJECT

public:
    TDLitem(QWidget *parent = nullptr, QString itemname = "", bool don = false);
    ~TDLitem();
    QString item_name;
    bool done;
private slots:

    void on_itemname_textChanged(const QString &arg1);

    void on_done_chb_stateChanged(int arg1);

private:
    Ui::TDLitem *ui;

};

#endif // TDLITEM_H
