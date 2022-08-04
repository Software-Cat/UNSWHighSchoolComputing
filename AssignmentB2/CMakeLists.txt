# =============================================================================
# CS Pizzeria
# CMakeLists.txt
#
# This program was written by Bowen Wu
# on 04/08/22
# =============================================================================

# Basic Info
cmake_minimum_required(VERSION 3.10)

project(AssignmentB2)
add_executable(pizzeria main.c order.c pizzeria.c utils.c)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

# If the IDE doesn't provide build type, default to Release
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Config header setup
configure_file(config.h.in config.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
