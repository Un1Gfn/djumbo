cmake_minimum_required(VERSION 3.16)

project(djumbo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_PREFIX /usr)
set(CMAKE_VERBOSE_MAKEFILE 1)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(djumbo
	djumbo.cpp
	main.cpp
)

target_link_libraries(djumbo PRIVATE Qt6::Widgets)

set_target_properties(djumbo PROPERTIES
	WIN32_EXECUTABLE ON
	MACOSX_BUNDLE ON
)

install(TARGETS djumbo)

