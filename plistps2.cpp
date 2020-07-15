#include "plistps2.h"

PListPs2::PListPs2(string fileName, bool performAnalysis = true)
{
    // fonction "Load" ici
    this->fileName = fileName;
    ifstream input("C:\\Users\\julie\\Desktop\\svredit_v24\\svredit_files\\2010\\PS2\\CH.PAC.1.PAC", std::ios::binary);
    vector<char> fileData((std::istreambuf_iterator<char>(input)),(std::istreambuf_iterator<char>()));
    input.close();

    byteData = fileData;
    TestFunction();
}

void PListPs2::TestFunction()
{
//    for (std::vector<char>::const_iterator i = byteData.begin(); i != byteData.end(); ++i) {
//        cout << *i << ' ';
//    }
    cout << this->fileName << endl;
}

//void PListPs2::SetOffsetAndSizeOf(string emdId, int size, string searchStr, bool findFirst = true, bool useNumbers = false)
//{
//    int count = 0;
//    int emdPos = 0;
//    int emdCnt = 0;
//    int found = 0;
//    int foundTimes = 0;
//    int foundEnd = 0;
//    int i = 0;
//}

//void PListPs2::SetOffsetAndSizeOfEMDs()
//{
//    SetOffsetAndSizeOf("EMD", 8, "EMD", false, true);
//}

//void PListPs2::SetOffsetAndSizeOfSTG()
//{
//    SetOffsetAndSizeOf("STG", 8, "STG ");
//}

//void PListPs2::SetOffsetAndSizeOfEND()
//{
//    SetOffsetAndSizeOf("END", 0, "CHAR");
//}

//void PListPs2::SetOffsetAndSizeOfSSFA()
//{
//    SetOffsetAndSizeOf("SSFA", 8, "SSFA", false);
//}

//void PListPs2::SetOffsetAndSizeOfSSFB()
//{
//    SetOffsetAndSizeOf("SSFB", 8, "SSFB", false);
//}

//void PListPs2::SetOffsetAndSizeOfSSFC()
//{
//    SetOffsetAndSizeOf("SSFC", 8, "SSFC", false);
//}

//void PListPs2::SetOffsetAndSizeOfSSFD()
//{
//    SetOffsetAndSizeOf("PICEND", 0, "OPTN");
//}

//void PListPs2::AnalyzeEmd()
//{
//    SetOffsetAndSizeOfEMDs();
//    SetOffsetAndSizeOfSTG();
//    SetOffsetAndSizeOfEND();
//    SetOffsetAndSizeOfSSFA();
//    SetOffsetAndSizeOfSSFB();
//    SetOffsetAndSizeOfSSFC();
//    SetOffsetAndSizeOfSSFD();
//}

//void PListPs2::RegisterModels(int size, string emdFile, string emdEnd, int endOffset = 0)
//{

//}

//void PListPs2::AnalyzeModels()
//{
//    RegisterModels(8, "STG", "ARENAEND");
//    RegisterModels(8, "SSFA", "SSFB");
//    RegisterModels(8, "SSFB", "SSFC");
//    RegisterModels(8, "SSFC", "PICEND");
//    RegisterModels(12, "EMD", "EMD2");
//    RegisterModels(12, "EMD2", "EMD3");
//    RegisterModels(12, "EMD3", "END");
//}

//void PListPs2::Analyze()
//{
//    AnalyzeEmd();
//    AnalyzeModels();
//}

//void PListPs2::RemovePreloadFromArcFile()
//{
//    int preloadInfoStart = 144;
//    int preloadInfoEnd = 292;
//}

//void PListPs2::AddModel(Model model, string emdId = NULL)
//{
//    if(analysisPerformed == false && emdId.empty()) {
//        SetOffsetAndSizeOf(model.Identifier(), 0, model.Identifier());

//    }
//}

//int PListPs2::Size()
//{
//    return byteData.size();
//}
