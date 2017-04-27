
project(matrix)

set(HEDEAR_FILES matrix.h)
set(SOURCE_FILES matrix.cpp)

add_library(libmatrix STATIC ${SOURCE_FILES})
target_include_directories(libmatrix PUBLIC .)

add_executable(matrix ${SOURCE_FILES} main.cpp)

target_link_libraries(matrix libmatrix)
