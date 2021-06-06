cmake_minimum_required(VERSION 3.14)

project(2021-06-07-Qt-Concurrent-Run LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS Concurrent REQUIRED)

add_executable(2021-06-07-Qt-Concurrent-Run
  main.cpp
)
target_link_libraries(2021-06-07-Qt-Concurrent-Run Qt${QT_VERSION_MAJOR}::Core Qt6::Concurrent)
