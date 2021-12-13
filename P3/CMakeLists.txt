CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(GarciaPozo)
ENABLE_LANGUAGE(CXX)
set(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main Menu.cpp algoritmos.cpp ficheros.cpp voraces.cpp)