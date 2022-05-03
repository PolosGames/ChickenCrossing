cmake_minimum_required(VERSION 3.21)

project(ChickenCrossing)

add_subdirectory(Polos)

add_executable(ChickenCrossing)

target_sources(ChickenCrossing 
    PRIVATE
        Game/EntryPoint.cpp
)

target_link_libraries(ChickenCrossing PUBLIC Runtime)

target_compile_features(ChickenCrossing PRIVATE cxx_std_20)

target_include_directories(ChickenCrossing PRIVATE Game)

install(TARGETS ChickenCrossing DESTINATION bin/${CMAKE_BUILD_TYPE})
install(DIRECTORY resources DESTINATION bin/${CMAKE_BUILD_TYPE})