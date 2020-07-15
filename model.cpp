#include "model.h"

Model::Model(string id, string number, QString fileName)
{
    this->modelId = id;
    this->modelNumber = number;
    this->modelFileName = fileName;
}

bool Model::Import(string chFileName)
{
//    string pListFileName = "plistps2.arc";
//    this->modelFileName
    char *model_byte_data = ReadByteDataFromFile("C:\\TEST\\TEST.pac");
    CorrectSize(strlen(model_byte_data),256);
    int convertedSize = strlen(model_byte_data)/256;
    int sizeByte1 = convertedSize/256;
    int sizeByte2 = convertedSize - (256*convertedSize);

}

char* Model::ReadByteDataFromFile(const char* name)
{
    ifstream fl(name);
    fl.seekg( 0, ios::end );
    size_t len = fl.tellg();
    char *output = new char[len];
    fl.seekg(0, ios::beg);
    fl.read(output, len);
    fl.close();
    return output;
}

int Model::CorrectSize(int size, int val)
{
    if(SizeOk(size,val)) {
        return size;
    }
    return ((size/val)+1)*val;
}

int Model::SizeOk(int size, int val)
{
    int convSize = size/val;
    return ((convSize*val) == size);
}

string Model::Identifier()
{
    return this->modelId+=this->modelNumber;
}
