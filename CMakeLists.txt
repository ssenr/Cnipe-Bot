cmake_minimum_required(VERSION 3.15)

project(cnipe-bot VERSION 1.0 DESCRIPTION "A Snipe Bot for Discord written in C++")

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    dpp
    sqlite3
)

target_include_directories(${PROJECT_NAME} PRIVATE
    src/include
    src/include/sqlite3pp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
