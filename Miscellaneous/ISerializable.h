#pragma once

#include <fstream>
#include <iostream>

namespace serialization
{
    class ISerializable
    {
    public:
        virtual void Serialize(std::ostream& stream) const = 0;
        virtual void Deserialize(std::istream& stream) = 0;
    };

    void loadWeightsFromFile(const char* filePath, ISerializable& target);
    void serializeToFile(const char* filePath, const ISerializable& target);
}
