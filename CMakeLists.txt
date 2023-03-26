cmake_minimum_required(VERSION 3.24)
project(esame_lab_programmazione)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Item.cpp Item.h ShoppingList.cpp ShoppingList.h User.cpp User.h Observer.h Subject.h)
add_executable(esame_lab_programmazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(esame_lab_programmazione core)
