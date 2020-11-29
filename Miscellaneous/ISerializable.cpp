#include "ISerializable.h"

void deserializeFromFile(const char* filePath, ISerializable& target)
{
    std::fstream myfile;
    myfile.open (filePath);
    if (myfile.good())
    {
        target.deserialize(myfile);
    }
    myfile.close();
}

void serializeToFile(const char* filePath, const ISerializable& target)
{
    std::fstream myfile;
    myfile.open (filePath);
    if (myfile.good())
    {
        target.serialize(myfile);
    }
    myfile.close();
}
