cmake_minimum_required(VERSION 3.10)
project(PhySim)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file(GLOB src_folder
    "includes/*.h"
    "src/*.cpp"
)

include_directories(includes)
add_executable(physim ${src_folder})

target_link_libraries(physim ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})