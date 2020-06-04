cmake_minimum_required(VERSION 3.13)
project(LearnOpenGL)
#add include
INCLUDE_DIRECTORIES(glad/include glfw/include)
# add glfw and opengl(windows)
FIND_LIBRARY(GLFW_LIB glfw3 lib NO_DEFAULT_PATH)
FIND_LIBRARY(OPENGL_LIB OpenGL32 lib NO_DEFAULT_PATH)
LINK_LIBRARIES(${GLFW_LIB} ${OPENGL_LIB})

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB SOURCE_FILE "*.cpp")
FILE(GLOB HEADER_FILE "*.h")

add_executable(LearnOpenGL
        ${SOURCE_FILE}
        ${HEADER_FILE}
        glad/src/glad.c)