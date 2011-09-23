#include <QStringListModel>
#include "groupsdialog.h"
#include "ui_groupsdialog.h"

GroupsDialog::GroupsDialog(QWidget *parent, QStringList *groups) :
    QDialog(parent),
    ui(new Ui::GroupsDialog)
{
    groupNames = groups;
    ui->setupUi(this);
    QStringListModel *model = new QStringListModel();
    model->setStringList(*groups);
    ui->listView->setModel(model);
}

GroupsDialog::~GroupsDialog()
{
    delete ui;
}

void GroupsDialog::on_cancelButton_clicked()
{
    this->close();
}

void GroupsDialog::on_okButton_clicked()
{
    QStringListModel* model = (QStringListModel*)(ui->listView->model());
    QStringList data = model->stringList();
    groupNames->clear();
    for (int i=0; i < data.size(); i++)
    {
        groupNames->push_back(data.at(i));
    }

    this->close();
}
