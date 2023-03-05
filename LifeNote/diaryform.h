#ifndef DIARYFORM_H
#define DIARYFORM_H
#include <QWidget>
#include "diarycontroller.h"

namespace Ui {
class DiaryForm;
}

class DiaryForm : public QWidget
{
    Q_OBJECT

public:
    explicit DiaryForm(QWidget *parent = nullptr);
    DiaryController * diary_controller;

    ~DiaryForm();

private slots:

    void on_previousdate_clicked();

    void on_next_date_clicked();

    void on_save_butt_clicked();

private:
    Ui::DiaryForm *ui;
};

#endif // DIARYFORM_H
