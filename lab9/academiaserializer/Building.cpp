//
// Created by Patryk on 17.05.2017.
//

#include "Building.h"
namespace academia {
    void Building::Serialize(academia::Serializer *in) const{
        in->Header("building");
        in->IntegerField("id", this->id);
        in->Comma("id");
        in->StringField("name", this->name);
        in->Comma("name");
        in->ArrayField("rooms", this->rooms);
        in->Footer("building");

    }

    Building::Building(int id, const std::string &name,
                       const std::vector<std::reference_wrapper<const Serializable>> &rooms) : id(id), name(name), rooms(rooms) {}
}
