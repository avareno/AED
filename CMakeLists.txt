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
        SearchStudents.hpp
        SearchStudents.cpp
        SearchUC.cpp
        Change_Class.hpp
        Change_Class.cpp
        Change_UC.hpp
        Change_UC.cpp
        Change.cpp
        Change.hpp
        Quit.cpp
        Quit.hpp
)
