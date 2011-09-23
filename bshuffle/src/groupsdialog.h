#ifndef GROUPSDIALOG_H
#define GROUPSDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
    class GroupsDialog;
}

class GroupsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupsDialog(QWidget *parent = 0, QStringList *groupNames = 0);
    ~GroupsDialog();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    QStringList* groupNames;
    Ui::GroupsDialog *ui;
};

#endif // GROUPSDIALOG_H
