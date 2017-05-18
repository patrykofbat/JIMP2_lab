//
// Created by Patryk on 17.05.2017.
//

#ifndef JIMP_EXERCISES_JSONSERIALIZER_H
#define JIMP_EXERCISES_JSONSERIALIZER_H

#include "Serialization.h"

namespace academia {
    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(std::ostream *out);

        std::ostream *out;

        void IntegerField(const std::string &field_name, int value);

        void DoubleField(const std::string &field_name, double value);

        void StringField(const std::string &field_name, const std::string &value);

        void BooleanField(const std::string &field_name, bool value);


        void SerializableField(const std::string &field_name, const academia::Serializable &value);

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value);

        void Header(const std::string &object_name);

        void Footer(const std::string &object_name);

        void Comma(const std::string &field_name);


    };
}


#endif //JIMP_EXERCISES_JSONSERIALIZER_H
