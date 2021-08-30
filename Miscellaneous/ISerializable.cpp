#include "ISerializable.h"

namespace serialization
{
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

    void saveWeightsIntoFile(const char* filePath, const ISerializable& target)
    {
        std::fstream myfile;
        myfile.open (filePath);
        if (myfile.good())
        {
            target.serialize(myfile);
        }
        myfile.close();
    }
}
