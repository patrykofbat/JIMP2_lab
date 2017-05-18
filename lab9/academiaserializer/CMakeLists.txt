
project(serialization)

set(HEDEAR_FILES Serialization.h JsonSerializer.h Room.h Building.h Serializer.h)
set(SOURCE_FILES Serialization.cpp JsonSerializer.cpp Room.cpp Building.cpp Serializer.cpp)

add_library(libserialization STATIC ${SOURCE_FILES})
target_include_directories(libserialization PUBLIC .)

add_executable(serialization ${SOURCE_FILES} main.cpp Room.cpp Room.h JsonSerializer.cpp JsonSerializer.h Building.cpp Building.h Serializer.cpp Serializer.h)

target_link_libraries(serialization libserialization)