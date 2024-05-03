cmake_minimum_required(VERSION 3.27)
project(Elevator)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Elevator
        main.cpp
        Elevator.cpp
        AdvElevator.cpp
        Logger.cpp
        TerminalControl.cpp
        config.cpp
        Printer.cpp
        SolveElevator.cpp
        SolveAdvelevator.cpp
)

set_target_properties(Elevator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

configure_file(About.txt ${CMAKE_BINARY_DIR}/bin/About.txt COPYONLY)
configure_file(CloseDoor.txt ${CMAKE_BINARY_DIR}/bin/CloseDoor.txt COPYONLY)

add_executable(test test.cpp)