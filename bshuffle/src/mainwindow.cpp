#include <QMessageBox>
#include <QRegExp>
#include <QTime>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPageSetupDialog>
#include <QPainter>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "groupsdialog.h"
#include "bsession.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    groupNames.push_back("Group 1");
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList MainWindow::buildNamesList(QString names)
{
    QString nameList = names;
    nameList.replace(QRegExp("^\\s+"),"");      // Remove Beginning Whitespace
    nameList.replace(QRegExp("\\s+$"),"");      // Remove Trailing Whitespace
    nameList.replace(QRegExp("\n\\s*\n"),"\n"); // Remove Empty Lines
    return nameList.split(QRegExp("\n"));
}

QStringList MainWindow::shuffleNames(QStringList names)
{
    QStringList nameList = names;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    for (int i = 0; i < nameList.size(); i++)
    {
        int new_index = qrand() % nameList.size();
        QString swapped = nameList[new_index];
        nameList[new_index] = nameList[i];
        nameList[i] = swapped;
    }
    return nameList;
}

QVector<QString> MainWindow::generateGroups(QStringList names)
{
    QVector<QString> groupList( ui->numGroupsSpinner->value() );
    for (int i = 0; i < names.size(); i++)
    {
        groupList[ i % groupList.size() ].append( "    " + names[i] + "\n");
    }
    return groupList;
}

QString MainWindow::buildGroupsString(QVector<QString> groupList)
{
    QString groupString;
    for (int i = 0; i < groupList.size(); i++)
    {
        groupString.append(groupNames.at(i) + ":\n");
        groupString.append(groupList[i]);
        groupString.append("\n");
    }
    return groupString;
}

void MainWindow::on_groupNamesButton_clicked()
{
    GroupsDialog groupsDialog(this, &groupNames);
    groupsDialog.exec();
}

void MainWindow::on_goButton_clicked()
{
    QStringList names = buildNamesList( ui->namesEdit->toPlainText() );
    names = shuffleNames( names );
    QVector<QString> groupList = generateGroups( names );
    ui->groupsEdit->setPlainText( buildGroupsString( groupList ) );
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QApplication::aboutQt();
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog about;
    about.exec();
}

void MainWindow::on_numGroupsSpinner_valueChanged(int arg1)
{
    int difference = arg1 - groupNames.size();
    bool is_incremented = (difference > 0) ? TRUE : FALSE;
    difference = (is_incremented) ? difference : (0 - difference);

    for (int i = 0; i < difference; i++ )
    {
        if (is_incremented)
        {
            int groupid = groupNames.size() + 1;
            groupNames.push_back("Group " + QString::number(groupid));
        }
        else
        {
            groupNames.pop_back();
        }
    }
}
