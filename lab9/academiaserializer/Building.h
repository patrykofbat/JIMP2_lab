//
// Created by Patryk on 17.05.2017.
//

#ifndef JIMP_EXERCISES_BUILDING_H
#define JIMP_EXERCISES_BUILDING_H

#include "Serializer.h"
#include "Room.h"

namespace academia {
    class Building:public Serializable {
    private:
        int id;
        std::string name;
        std::vector<std::reference_wrapper<const Serializable>> rooms;
    public:
        void Serialize(Serializer *in) const;
        Building(int id, const std::string &name, const std::vector<std::reference_wrapper<const Serializable>> &rooms);

    };

}


#endif //JIMP_EXERCISES_BUILDING_H
