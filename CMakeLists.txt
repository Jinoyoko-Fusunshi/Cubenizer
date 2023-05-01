cmake_minimum_required(VERSION 3.24)
project(Cubenizer)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB_RECURSE Source src/*.c*)
add_executable(Cubenizer ${Source})
target_include_directories(Cubenizer PRIVATE include)
target_link_libraries(Cubenizer PRIVATE -lGLEW glfw -lGL -lm)