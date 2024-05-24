cmake_minimum_required(VERSION 3.10)
project(PhySim)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

include_directories(SYSTEM "include")
include_directories(SYSTEM "headers")

file(GLOB src_folder
    "src/*.cpp"
    "src/*.c"
)

add_executable(physim ${src_folder})

target_link_libraries(physim ${OPENGL_LIBRARIES} ${glfw} -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl)