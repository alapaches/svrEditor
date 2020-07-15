#ifndef PLISTPS2_H
#define PLISTPS2_H

#include <iostream>
#include "model.h"
#include <vector>
#include <fstream>
#include <iterator>

using namespace std;
class PListPs2
{
    public:
        PListPs2(string, bool);
        void TestFunction();
        void SetOffsetAndSizeOf(string, int, string, bool, bool);
        void SetOffsetAndSizeOfEMDs();
        void SetOffsetAndSizeOfSTG();
        void SetOffsetAndSizeOfEND();
        void SetOffsetAndSizeOfSSFA();
        void SetOffsetAndSizeOfSSFB();
        void SetOffsetAndSizeOfSSFC();
        void SetOffsetAndSizeOfSSFD();
        void AnalyzeEmd();
        void RegisterModels(int, string, string, int);
        void AnalyzeModels();
        void Analyze();
        void RemovePreloadFromArcFile();
        void AddModel(Model,string);
        int Size();

    private:
        bool performAnalysis;
        bool analysisPerformed = false;
        string fileName;
        map<string,string> offset;
        map<string,string> size;
        map<string,string> charModels;
        map<string,string> charImages;
        map<string,string> emdFile;
        vector<char> byteData;
};

#endif // PLISTPS2_H
