# minimum CMake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(cnipe-bot VERSION 1.0 DESCRIPTION "A Snipe Bot for Discord written in C(++)")

# Add DPP as dependency
add_subdirectory(
    libs/DPP
)
# You can also add any other libs you want to use
 
# Create an executable
add_executable(${PROJECT_NAME}
    src/utils.cpp
    src/commands.cpp
    src/events.cpp
    src/main.cpp
    # your other files...
)
 
# Linking libraries
target_link_libraries(${PROJECT_NAME}
    dpp
    -lpqxx
    -lpq
    # Add any other libs you want to use here
)
 
# Specify includes
target_include_directories(${PROJECT_NAME} PRIVATE
    libs/DPP/include
    src/include
)
 
# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
