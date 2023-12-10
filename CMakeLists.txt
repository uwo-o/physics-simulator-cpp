cmake_minimum_required(VERSION 3.10)
project(PhySim)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_subdirectory(src)
add_executable(PhySim main.cpp)

target_link_libraries(PhySim ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})