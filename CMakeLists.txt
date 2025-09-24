cmake_minimum_required(VERSION 3.16)

project(Calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Calculator main.cpp
    calculator.cpp
    calculator.h
    main.cpp
    README.md


)

include(GNUInstallDirs)
install(TARGETS Calculator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
