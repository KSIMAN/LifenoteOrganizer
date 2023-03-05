#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createDirs();
    initForms();
    activeform = static_cast<QWidget*>(n_form);
    //activeform->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createDirs()
{
    QDir dir = QDir::current();
    dir.mkdir(QString("storage"));
    dir.mkdir(QString("storage/notes"));
    dir.mkdir(QString("storage/diaries"));
    dir.mkdir(QString("storage/links"));
    dir.mkdir(QString("storage/doings"));
}
void MainWindow::initForms()
{
    n_form  = new NoteForm(ui->FormShowW);
    n_form->show();
    td_form = new ToDoForm(ui->FormShowW);
    td_form->hide();
    d_form = new DiaryForm(ui->FormShowW);
    d_form->hide();
}
void MainWindow::changeActive(QWidget *active)
{
    activeform->hide();
    activeform = active;
    activeform->show();
}
void MainWindow::on_notes_Button_clicked()
{
   changeActive(static_cast<QWidget*>(n_form));
}
void MainWindow::on_doings_butt_clicked()
{
   changeActive(static_cast<QWidget*>(td_form));
}


void MainWindow::on_diary_butt_clicked()
{
   changeActive(static_cast<QWidget*>(d_form));
}

