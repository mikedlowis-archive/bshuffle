#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QVector>
#include <QPrinter>
#include "printsettings.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_goButton_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_QT_triggered();
    void on_actionAbout_triggered();
    void on_numGroupsSpinner_valueChanged(int arg1);
    void on_groupNamesButton_clicked();

private:
    Ui::MainWindow *ui;
    QPrinter printer;
    QStringList groupNames;
    PrintSettings printSettings;
    QStringList buildNamesList(QString names);
    QStringList shuffleNames(QStringList names);
    QVector<QString> generateGroups(QStringList names);
    QString buildGroupsString(QVector<QString> groupList);
};

#endif // MAINWINDOW_H
