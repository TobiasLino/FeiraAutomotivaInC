cmake_minimum_required(VERSION 3.15)
project(FeiraAutomotivaInC C)

set(CMAKE_C_STANDARD 11)

include_directories(src/include)
include_directories(src/model)

add_executable(FeiraAutomotivaInC
        include/list.h
        src/address.c
        include/address.h
        src/client.c
        include/client.h
        src/phone.c
        include/phone.h
        src/schedule.c
        include/schedule.h
        include/vehicle.h
        teste.c)
