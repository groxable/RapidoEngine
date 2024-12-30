cmake_minimum_required(VERSION 3.5)
project(RapidoEngine)

set(CMAKE_CXX_STANDARD 11)
file(GLOB SOURCES "source/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

message("Processing CMakeLists.txt")

include(FindPkgConfig)

pkg_search_module(OpenGL REQUIRED gl)
pkg_search_module(GLUT REQUIRED glut)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

if (NOT OpenGL_FOUND)
    message(FATAL_ERROR "OpenGL not found")
endif()

if (NOT GLUT_FOUND)
    message(FATAL_ERROR "GLUT not found")
endif()

if (NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found")
endif()

if (NOT SDL2IMAGE_FOUND)
    message(FATAL_ERROR "SDL2_image not found")
endif()

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
)
