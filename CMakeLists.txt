cmake_minimum_required(VERSION 3.15)
project(FeiraAutomotivaInC C)

set(CMAKE_C_STANDARD 11)

include_directories(src/include)
include_directories(src/model)

add_executable(FeiraAutomotivaInC
        src/teste.c
        src/include/list.c
        src/model/address.c
        src/model/client.c
        src/model/phone.c
        src/model/schedule.c)
