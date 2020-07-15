#ifndef MODELIMPORTER_H
#define MODELIMPORTER_H

#include <iostream>
#include <QDebug>
#include <QString>
#include "model.h"
#include "plistps2.h"

using namespace std;
class ModelImporter
{

    public:
        ModelImporter();
        void RunImport(string,string,QString,string,string,string);

    private:
        string wrestlerId;
        string wrestlerModel;
        string wrestlerPacFile;
        string emd;
        string ch;
        string plistArcFile;
};

#endif // MODELIMPORTER_H
