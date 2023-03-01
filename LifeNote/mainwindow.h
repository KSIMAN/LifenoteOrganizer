#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <noteform.h>
#include <todoform.h>
#include "includes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    NoteForm * n_form ;
    ToDoForm * td_form;
    QWidget * activeform;
private slots:
    void on_notes_Button_clicked();


    void on_doings_butt_clicked();

private:
    void createDirs();
    void initForms();
    void changeActive(QWidget * active);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
