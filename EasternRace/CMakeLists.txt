cmake_minimum_required(VERSION 3.22.0)
project(EasternRace)

include_directories(../VehicleLib)
include_directories(../RaceLib)

set(SOURCES_VEHICLE_LIB 
    ../VehicleLib/LandVehicle.cpp
    ../VehicleLib/AirVehicle.cpp
    ../VehicleLib/Broom.cpp
    ../VehicleLib/Camel.cpp 
    ../VehicleLib/Centaur.cpp
    ../VehicleLib/Eagle.cpp 
    ../VehicleLib/FastCamel.cpp 
    ../VehicleLib/MagicCarpet.cpp 
    ../VehicleLib/RoverBoots.cpp)

set(HEADERS_VEHICLE_LIB
    ../VehicleLib/LandVehicle.h 
    ../VehicleLib/AirVehicle.h 
    ../VehicleLib/Broom.h 
    ../VehicleLib/Camel.h 
    ../VehicleLib/Centaur.h 
    ../VehicleLib/Eagle.h 
    ../VehicleLib/FastCamel.h 
    ../VehicleLib/MagicCarpet.h 
    ../VehicleLib/RoverBoots.h)

set(SOURCES_RACE_LIB
    ../RaceLib/Race.cpp 
    ../RaceLib/RaceResult.cpp)

set(HEADERS_RACE_LIB
    ../RaceLib/Race.h 
    ../RaceLib/RaceResult.h)

set(SOURCES
    EasternRace.cpp 
    Check.cpp 
    Error.cpp)

set(HEADERS
    Check.h
    Error.h)

add_library(VehicleLib SHARED ${HEADERS_VEHICLE_LIB} ${SOURCES_VEHICLE_LIB})

add_library(RaceLib SHARED ${HEADERS_RACE_LIB} ${SOURCES_RACE_LIB} ${HEADERS_VEHICLE_LIB} ${SOURCES_VEHICLE_LIB})

add_executable(EasternRace ${SOURCES} ${HEADERS})

target_link_libraries(EasternRace RaceLib VehicleLib)
