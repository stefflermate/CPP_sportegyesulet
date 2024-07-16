cmake_minimum_required(VERSION 3.27)
project(Nagy_HF)

set(CMAKE_CXX_STANDARD 17)

add_executable(Nagy_HF main.cpp
        Egyesulet.cpp
        Egyesulet.h
        SportAg.cpp
        SportAg.h
        Labdarugas.cpp
        Labdarugas.h
        Kosarlabda.cpp
        Kosarlabda.h
        Kezilabda.cpp
        Kezilabda.h
        Csapat.cpp
        Csapat.h
        Csapat.h
        memtrace.cpp)

set(CMAKE_CXX_FLAGS "-DMEMTRACE -g")
