#ifndef IMPORTMODEL_H
#define IMPORTMODEL_H

#include <iostream>
#include <QDebug>
#include <QString>
#include <QDir>

#include "modelimporter.h"

using namespace std;
class ImportModel
{
    public:
        ImportModel();
        void ImportCharacterModel(const char *argv[]);
        void ImportArenaModel(char argv[]);
        void ImportSelectionPic(char argv[]);

    private:
        string chFile = "";
        string emdFile = "";
};

#endif // IMPORTMODEL_H
