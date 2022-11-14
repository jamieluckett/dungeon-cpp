cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)
project(dungeoncpp)

# SFML
SET(SFML_VERSION 2.5.1)
SET(SFML_DIR extlib/SFML-${SFML_VERSION}/lib/cmake/SFML)
include_directories(SFML_DIR)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML ${SFML_VERSION} COMPONENTS graphics audio REQUIRED)

if (WIN32)
    # Statically compile in MinGW libraries to make the results portable
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
    set(BUILD_SHARED_LIBS OFF)
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
endif()

# >(._.)< crab
# [._.]  robot

set(
        INCLUDE_DIRS
        src/Floors
        src/Renderers
        src/Util
)

add_executable(
    dungeoncpp
    src/main.cpp
    src/Floors/DrunkardsWalk.cpp
    src/Floors/Floor.cpp
    src/Floors/RandomFloor.cpp
    src/Renderers/SFMLRenderer.cpp
        src/Util/Coordinate.cpp
)

target_include_directories(
    dungeoncpp PRIVATE ${INCLUDE_DIRS}
)

target_link_libraries(dungeoncpp sfml-graphics)

file(COPY tiles DESTINATION .)
