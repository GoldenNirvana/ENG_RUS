cmake_minimum_required(VERSION 3.16)
project(RGR_ENG_RUS)

set(CMAKE_CXX_STANDARD 14)

add_executable(RGR_ENG_RUS main.cpp Dictionary.cpp Dictionary.hpp Utilities.cpp Utilities.hpp userCommands.hpp userCommands.cpp forRead.hpp forRead.cpp iofmtguard.hpp iofmtguard.cpp)
