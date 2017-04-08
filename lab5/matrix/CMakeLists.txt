
project(matrix)

set(HEDEAR_FILES Matrix.h)
set(SOURCE_FILES Matrix.cpp)

add_library(libmatrix STATIC ${SOURCE_FILES} main.cpp ../textpool/main.cpp ../textpool/TextPool.cpp ../textpool/TextPool.h)
target_include_directories(libmatrix PUBLIC .)

add_executable(matrix ${SOURCE_FILES} main.cpp)

target_link_libraries(matrix libmatrix)