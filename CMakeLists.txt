cmake_minimum_required(VERSION 3.26)
project(projeto)

set(CMAKE_CXX_STANDARD 17)

add_executable(projeto main.cpp
        Class_per_uc.hpp
        Class_per_uc.cpp
        Class.hpp
        Class.cpp
        Student_class.hpp
        Student_class.cpp
        Menu.cpp
        SearchClass.hpp
        Search.cpp
        SearchStudents.hpp
        SearchStudents.cpp
        SearchUC.cpp
)
