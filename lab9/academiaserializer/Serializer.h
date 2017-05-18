//
// Created by Patryk on 17.05.2017.
//

#ifndef JIMP_EXERCISES_SERIALIZER_H
#define JIMP_EXERCISES_SERIALIZER_H

#include <ostream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <map>
#include <utility>
#include <functional>
#include <memory>

namespace academia{
    class Serializable;

    class Serializer{
    public:
        Serializer(std::ostream *out){}

        ~Serializer(){}

        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value) =0;
        virtual void BooleanField(const std::string &field_name, bool value) =0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value) =0;
        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value) =0;
        virtual void Header(const std::string &object_name) =0;
        virtual void Footer(const std::string &object_name) =0;
        virtual void Comma(const std::string &field_name)=0;


    };


    class Serializable{
    public:
        virtual void Serialize(Serializer *in)const  =0;

    };



}



#endif //JIMP_EXERCISES_SERIALIZER_H
