#include "ISerializable.h"

namespace serialization
{
    void loadWeightsFromFile(const char* filePath, ISerializable& target)
    {
        std::fstream stream;
        stream.open (filePath, std::fstream::in | std::fstream::binary);
        if (stream.good())
        {
            target.deserialize(stream);
        }
        stream.close();
    }

    void serializeToFile(const char* filePath, const ISerializable& target)
    {
        std::fstream stream;
        stream.open (filePath, std::fstream::out | std::fstream::binary | std::fstream::trunc);
        if (stream.good())
        {
            target.serialize(stream);
        }
        stream.close();
    }
}
