#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interface)
{
    ui->setupUi(this);
    ui->direcotryLineEdit->setText(qApp->applicationDirPath());
    QFile chFile(qApp->applicationDirPath()+"/ch.pac");
    QFile ch2File(qApp->applicationDirPath()+"/ch2.pac");
    QFile ch3File(qApp->applicationDirPath()+"/ch3.pac");
    QFile chetcFile(qApp->applicationDirPath()+"/chetc.pac");
    QFile bgFile(qApp->applicationDirPath()+"/bg.pac");
    QFile menuFile(qApp->applicationDirPath()+"/menu.pac");
    QFile miscFile(qApp->applicationDirPath()+"/misc.pac");
    QFile plistArcFile(qApp->applicationDirPath()+"/plistps2.arc");
    QFile plistHeaderFile(qApp->applicationDirPath()+"/plistps2.h");
    if(!chFile.exists() && !ch2File.exists() && !ch3File.exists()
            && !chetcFile.exists() && !bgFile.exists() && !menuFile.exists()
            && !miscFile.exists() && !plistArcFile.exists() && !plistHeaderFile.exists()
    ) {
        QMessageBox *warning = new QMessageBox;
        warning->setWindowTitle("Missing Requirements");
        warning->setTextFormat(Qt::RichText);
        warning->setText("Some required files are <b>missing</b> ! <br />"
                         "Please check the list at the bottom of the screen <br />"
                         "Put your files in the given directory<br />"
                         "Once donce, restart the app to apply changes");
        warning->exec();
    } else {
        ui->chCheckBox->setChecked(true);
        ui->ch2CheckBox->setChecked(true);
        ui->ch3CheckBox->setChecked(true);
        ui->chetcCheckBox->setChecked(true);
        ui->bgCheckBox->setChecked(true);
        ui->menuCheckBox->setChecked(true);
        ui->miscCheckBox->setChecked(true);
        ui->plistPs2ArcCheckBox->setChecked(true);
        ui->plistPs2hCheckBox->setChecked(true);
    }
}

Interface::~Interface()
{
    delete ui;
}
void Interface::on_wrestlerLineEdit_textEdited()
{
    QStringList wrestlersName;
    QDirIterator iterator(":/characters_pics", QDir::Files | QDir::NoDotAndDotDot);
    while (iterator.hasNext()) {
        QFileInfo rFile = iterator.next();
        QString realFile = rFile.completeBaseName();
        wrestlersName << realFile;
    }
    QCompleter *completer = new QCompleter(wrestlersName, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->wrestlerLineEdit->setCompleter(completer);
    connect(completer, QOverload<const QString &>::of(&QCompleter::activated),[=](const QString &text)
    {
        getCurrentWrestlerInfo(text);
    });
}

void Interface::getCurrentWrestlerInfo(QString wrestlerName)
{
    QImage *img = new QImage();
    QString val;
    QJsonValue fileValue;
    QFile file(":/json/characters_id_svr2010.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject wrestlers = d.object();
    QJsonValue wrestler = wrestlers.value(QString(wrestlerName));
    QJsonObject item = wrestler.toObject();

    QJsonValue idValue = item.value(QString("id"));
    QString wrestlerId = idValue.toString();

    QJsonValue brandValue = item.value(QString("brand"));
    QString wrestlerBrand = brandValue.toString();

    QJsonValue attributes = item.value(QString("attributes"));
    QJsonObject attributesObject = attributes.toObject();

    QJsonValue grappleAttr = attributesObject.value(QString("grapple"));
    QString grappleValue = grappleAttr.toString();
    QJsonValue strikeAttr = attributesObject.value(QString("strike"));
    QString strikeValue = strikeAttr.toString();
    QJsonValue submissionAttr = attributesObject.value(QString("submission"));
    QString submissionValue = submissionAttr.toString();
    QJsonValue durabilityAttr = attributesObject.value(QString("durability"));
    QString durabilityValue = durabilityAttr.toString();
    QJsonValue techniqueAttr = attributesObject.value(QString("technique"));
    QString techniqueValue = techniqueAttr.toString();
    QJsonValue speedAttr = attributesObject.value(QString("speed"));
    QString speedValue = speedAttr.toString();
    QJsonValue charismaAttr = attributesObject.value(QString("charisma"));
    QString charismaValue = charismaAttr.toString();
    QJsonValue hardcoreAttr = attributesObject.value(QString("hardcore"));
    QString hardcoreValue = hardcoreAttr.toString();

    std::string stringId = wrestlerId.toStdString();
    const char * characterId = stringId.c_str();
    ImportModel *testModel = new ImportModel();
    QString wrestlerQstringFile = QFileDialog::getOpenFileName(this, "Select wrestler PAC file", QString(), "Wrestler (*.pac)");
    std::string wrestlerStdStringFile = wrestlerQstringFile.toStdString();
    const char* wrestlerFile = wrestlerStdStringFile.c_str();
    const char *modelArguments[3] = {characterId,"01",wrestlerFile};
    testModel->ImportCharacterModel(modelArguments);

    bool loaded = img->load(":/characters_pics/" + wrestlerName + ".png");
    if(loaded) {
        ui->wrestlerImage->setPixmap(QPixmap(":/characters_pics/" + wrestlerName + ".png"));
        ui->grappleLineEdit->setText(grappleValue);
        ui->strikeLineEdit->setText(strikeValue);
        ui->submissionLineEdit->setText(submissionValue);
        ui->durabilityLineEdit->setText(durabilityValue);
        ui->techniqueLineEdit->setText(techniqueValue);
        ui->speedLineEdit->setText(speedValue);
        ui->charismaLineEdit->setText(charismaValue);
        ui->hardcoreLineEdit->setText(hardcoreValue);


    } else {

    }
    delete testModel;
}
