cmake_minimum_required(VERSION 3.17)
project(SwitchStatement C)

set(CMAKE_C_STANDARD 99)

add_executable(SwitchStatement main.c mainQuiz.h
        questions.h)

#added by sofoste
set(CMAKE_CXX_FLAGS_"${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")