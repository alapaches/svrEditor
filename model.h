#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <cstring>
#include <cstddef>
#include <QDebug>

using namespace std;
class Model
{
    public:
        Model(string, string, QString);
        bool Import(string);
        char* ReadByteDataFromFile(const char*);
        int CorrectSize(int,int);
        int SizeOk(int, int);
        string Identifier();

    private:
        string modelId;
        string modelNumber;
        QString modelFileName;
};

#endif // MODEL_H
