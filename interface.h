#ifndef INTERFACE_H
#define INTERFACE_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidgetItem>
#include <QDirIterator>
#include <QCompleter>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QFileDialog>

#include "importmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Interface; }
QT_END_NAMESPACE

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    Interface(QWidget *parent = nullptr);
    ~Interface();
    void getCurrentWrestlerInfo(QString wrestler);

private slots:
    void on_wrestlerLineEdit_textEdited();

private:
    Ui::Interface *ui;
    QString wrestlersPics = ":/charatcers_pics";
};
#endif // INTERFACE_H
