#pragma once

#include <fstream>
#include <iostream>

namespace serialization
{
    class ISerializable
    {
    public:
        virtual void serialize(std::ostream& stream) const = 0;
        virtual void deserialize(std::istream& stream) = 0;
    };

    void deserializeFromFile(const char* filePath, ISerializable& target);
    void saveWeightsIntoFile(const char* filePath, const ISerializable& target);
}
