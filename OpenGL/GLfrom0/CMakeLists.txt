cmake_minimum_required(VERSION 2.8)

project(learnGL)

file(GLOB_RECURSE SOURCE "src/*.cpp")

add_executable(learnGL
    ${SOURCE}
)

target_link_directories(learnGL
    PUBLIC
        "D:/Devs/OpenGL(MinGW)/GLFWlib"
)

target_link_libraries(learnGL
    opengl32
    glfw3
    glad
    gdi32
)

target_include_directories(learnGL
    PUBLIC
        "D:/Devs/OpenGL(MinGW)/include"
)