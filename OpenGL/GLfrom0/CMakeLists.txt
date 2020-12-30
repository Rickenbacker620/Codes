cmake_minimum_required(VERSION 2.8)

project(learnGL)


add_executable(learnGL
    # src/rainbow.cpp
    src/case3.cpp
    "D:/Devs/modernGL/src/glUtils.cpp"
    "D:/Devs/modernGL/src/shader.cpp"
    "D:/Devs/modernGL/src/vao.cpp"
    "D:/Devs/modernGL/src/vbo.cpp"
    "D:/Devs/modernGL/src/ebo.cpp"
    "D:/Devs/modernGL/src/gldebug.cpp"
    "D:/Devs/modernGL/src/texture.cpp"
    "D:/Devs/modernGL/src/camera.cpp"
)

target_link_directories(learnGL
    PRIVATE
        "D:/Devs/OpenGL(MinGW)/GLFWlib"
)

target_link_libraries(learnGL
    opengl32
    glfw3
    glad
    gdi32
)

target_include_directories(learnGL
    PRIVATE
        "D:/Devs/OpenGL(MinGW)/include"
    PUBLIC
        "D:/Devs/modernGL/include"
)