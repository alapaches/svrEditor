#include "modelimporter.h"

ModelImporter::ModelImporter()
{

}

void ModelImporter::RunImport(string id, string model, QString wrestlerPac, string emdFile, string chPac, string plistFile)
{
    Model testModel(id,model,wrestlerPac);
    PListPs2 *plist = new PListPs2(plistFile,true);
//    if(testModel.Import(chPac)) {
//        PListPs2 *plist = new PListPs2(plistFile,true);
//        plist->AddModel(testModel,emdFile);
//        plist->Save(plistFile+".new.arc");
//        File.rename(plistFile, "#{plistFile}.bak")
//        File.rename("#{plistFile}.new.ARC", plistFile)
//    }
}
