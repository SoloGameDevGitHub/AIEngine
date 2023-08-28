#include "ISerializable.h"

namespace Serialization
{
    void LoadWeightsFromFile(const char* filePath, ISerializable& target)
    {
        std::fstream stream;
        stream.open (filePath, std::fstream::in | std::fstream::binary);
        if (stream.good())
        {
            target.Deserialize(stream);
        }
        stream.close();
    }

    void SerializeToFile(const char* filePath, const ISerializable& target)
    {
        std::fstream stream;
        stream.open (filePath, std::fstream::out | std::fstream::binary | std::fstream::trunc);
        if (stream.good())
        {
            target.Serialize(stream);
        }
        stream.close();
    }
}
