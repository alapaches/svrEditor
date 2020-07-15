#include "importmodel.h"

ImportModel::ImportModel()
{

}

void ImportModel::ImportCharacterModel(const char **argv)
{
    QString id = argv[0];
    QString wrestlerPacFile = argv[2];
    string model = argv[1];
    int idWrestler = id.toInt();
    if(idWrestler < 130) {
        chFile = "ch.pac";
        emdFile = "EMD";
    } else if(idWrestler >= 130 && idWrestler < 160) {
        chFile = "ch2.pac";
        emdFile = "EMD2";
    } else if(idWrestler >= 160) {
        chFile = "ch3.pac";
        emdFile = "EMD3";
    }
    string wrestlerId = argv[0];
    const char * emd = emdFile.c_str();
    const char* ch = chFile.c_str();
    QDir dir;
    QString file = "plistps2.arc";
    dir.absolutePath();
    qDebug() << dir;
    ModelImporter *modelImporter = new ModelImporter();
    modelImporter->RunImport(wrestlerId, model,wrestlerPacFile,emd,ch, "plistps2.arc");
}
