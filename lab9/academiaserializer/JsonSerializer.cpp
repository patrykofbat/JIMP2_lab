//
// Created by Patryk on 17.05.2017.
//


#include "JsonSerializer.h"


void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    *(this->out) << "\"" << field_name << "\": " << value;

}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {

}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    *(this->out) << "\"" << field_name << "\": " << "\"" << value << "\"";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {

}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}


void academia::JsonSerializer::Header(const std::string &object_name) {
    *(this->out) << "{";

}

void academia::JsonSerializer::Footer(const std::string &object_name) {
    *(this->out) << "}";
}

void academia::JsonSerializer::Comma(const std::string &field_name) {
    *(this->out) << ", ";
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    *this->out << "\"" << field_name << "\": [";
    int i = 0;
    for (const Serializable &n : value) {

        SerializableField(" ", n);
        if(i != value.size()-1) {
            *this->out << ", ";
        }
        i++;
    }
    *this->out << "]";
}

academia::JsonSerializer::JsonSerializer(std::ostream *out) : Serializer(out) {
    this->out=out;
}
