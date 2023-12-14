cmake_minimum_required(VERSION 3.16)

project(MAVLink-Slaver VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5 COMPONENTS Core Widgets Network  REQUIRED)

file(GLOB_RECURSE SOURCE_LIST *.cc)
file(GLOB_RECURSE HEADER_LIST *.h)
file(GLOB_RECURSE UI_LIST *.ui)


add_executable(MAVLink-Slaver
    ${SOURCE_LIST}
	${HEADER_LIST}
    ${UI_LIST}
  )

target_link_libraries(MAVLink-Slaver PRIVATE 
    Qt5::Core 
    Qt5::Widgets
    Qt5::Network
)