#pragma once

#include <fstream>
#include <iostream>

namespace Serialization
{
    class ISerializable
    {
    public:
        virtual void Serialize(std::ostream& stream) const = 0;
        virtual void Deserialize(std::istream& stream) = 0;
    };

    void LoadWeightsFromFile(const char* filePath, ISerializable& target);
    void SerializeToFile(const char* filePath, const ISerializable& target);
}
