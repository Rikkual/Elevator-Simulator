cmake_minimum_required(VERSION 3.27)
project(Elevator)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Elevator
        main.cpp
        Elevator/Elevator.cpp
        Elevator/AdvElevator.cpp
        Logger/Logger.cpp
        TerminalControl.cpp
        config.cpp
        Printer/Printer.cpp
        SolveElevator.cpp
        SolveAdvElevator.cpp
)

set_target_properties(Elevator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

configure_file(Printer/About.txt ${CMAKE_BINARY_DIR}/bin/About.txt COPYONLY)
configure_file(Printer/CloseDoor.txt ${CMAKE_BINARY_DIR}/bin/CloseDoor.txt COPYONLY)

add_executable(test test.cpp)