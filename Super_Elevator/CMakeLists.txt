cmake_minimum_required(VERSION 3.27)
project(Elevator)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)
include_directories(Elevator)
include_directories(Logger)
include_directories(Printer)

add_executable(Elevator
        main.cpp
        config.cpp
        Elevator/Elevator.cpp
        Elevator/AdvElevator.cpp
        Logger/Logger.cpp
        Printer/Printer.cpp
        TerminalControl.cpp
        SolveElevator.cpp
        SolveAdvElevator.cpp
)

set_target_properties(Elevator PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

configure_file(Printer/About.txt ${CMAKE_BINARY_DIR}/bin/About.txt COPYONLY)
configure_file(Printer/OpenDoor.txt ${CMAKE_BINARY_DIR}/bin/OpenDoor.txt COPYONLY)
configure_file(Printer/CloseDoor.txt ${CMAKE_BINARY_DIR}/bin/CloseDoor.txt COPYONLY)

add_executable(test test.cpp)