cmake_minimum_required(VERSION 3.19)
project(implementacion C)

set(CMAKE_C_STANDARD 11)

add_executable(implementacion main.c saferplus.c saferplus.h aux.c aux.h)