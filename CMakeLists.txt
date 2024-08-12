# 3.16 version required for target_precompile_header feature
cmake_minimum_required(VERSION 3.16)

project(axolotl-cube-timer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ftxui REQUIRED)

file (GLOB_RECURSE app_src "${CMAKE_CURRENT_SOURCE_DIR}/app/cpp/src/*.cpp")

set (PROJECT_SOURCES
    ${app_src}
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/app/cpp/include"
)

target_link_libraries(${PROJECT_NAME} ftxui::ftxui)

target_precompile_headers(${PROJECT_NAME} PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/app/cpp/include/pch.hpp"
)