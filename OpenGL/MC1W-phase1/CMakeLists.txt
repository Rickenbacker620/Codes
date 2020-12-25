cmake_minimum_required(VERSION 2.8)

project(mc)

file(GLOB_RECURSE SOURCE "Source/*.cpp")

add_executable(mc
    ${SOURCE}
)

target_link_directories(mc
    PUBLIC
        "D:/Devs/OpenGL(MinGW)/GLFWlib"
    PUBLIC
        "D:/Devs/OpenGL(MinGW)/SFMLlib"
)

target_link_libraries(mc
    sfml-window-s
    sfml-system-s
    sfml-graphics-s
    opengl32
    glfw3
    glad
    gdi32
    winmm
)

target_include_directories(mc
    PUBLIC
        "D:/Devs/OpenGL(MinGW)/include"
)

target_compile_definitions(mc
    PUBLIC
    SFML_STATIC
)