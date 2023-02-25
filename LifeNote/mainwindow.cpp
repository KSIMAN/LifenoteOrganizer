#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDirs();
    initForms();
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
    n_form->hide();
}


void MainWindow::on_notes_Button_clicked()
{
    n_form->show();
}

