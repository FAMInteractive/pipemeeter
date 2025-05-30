cmake_minimum_required(VERSION 3.16)

project(pipemeeter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PIPEWIRE REQUIRED libpipewire-0.3)
include_directories(${PIPEWIRE_INCLUDE_DIRS})

set(PROJECT_SOURCES
        src/Main.cpp
        src/Gui/MainWindow.cpp
        src/Gui/MainWindow.h
        src/Gui/MainWindow.ui
        src/Audio/Audio.cpp
        src/Audio/Audio.h

)
add_executable(pipemeeter
        ${PROJECT_SOURCES}
)

include(cmake/CPM.cmake)

CPMFindPackage(
        NAME           rohrkabel
        VERSION        9.0.0
        GIT_REPOSITORY "https://github.com/Curve/rohrkabel"
)

target_link_libraries(pipemeeter PRIVATE Qt${QT_VERSION_MAJOR}::Widgets cr::rohrkabel)

include(GNUInstallDirs)
install(TARGETS pipemeeter
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(pipemeeter)
endif()
