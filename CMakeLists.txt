cmake_minimum_required(VERSION 3.2)
project(Cpp_Linked_List VERSION 1.0.0)

file(GLOB files
        "main.cpp"
        "libraries/*.h"
        "libraries/*.cpp"
        )


add_executable(Cpp_Linked_List ${files})