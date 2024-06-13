cmake_minimum_required(VERSION 3.10)
project(PhySim)

include_directories(SYSTEM "include")

file(GLOB src_folder
    "src/*.cpp"
    "src/*.c"
)

add_executable(physim ${src_folder})