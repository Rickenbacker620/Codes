#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glutils.h>
#include <gldebug.h>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

//test rotate,move,zoom

float vertices[] = {
    0.5, 0.5, 0.0, 0.5, 0.1, 0.7, 1.0, 1.0,
    0.5, -0.5, 0.0, 0.2, 0.3, 0.4, 1.0, 0.0,
    -0.5, -0.5, 0.0, 0.3, 0.9, 0.7, 0.0, 0.0,
    -0.5, 0.5, 0.0, 0.6, 0.1, 0.2, 0.0, 1.0};
unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3};

int main()
{
    stbi_set_flip_vertically_on_load(true);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
    auto window = CreateApp("hello", 800, 600);

    VertexArray VAO;
    VertexBuffer VBO(vertices, sizeof(vertices));
    VertexBufferLayout layout;
    layout.Pushfloat(3);
    layout.Pushfloat(3);
    layout.Pushfloat(2);
    VAO.AddBuffer(VBO, layout);
    ElementBuffer EBO(indices, 6);
    Texture tx1("../resources/textures/container.jpg", GL_RGB);
    Texture tx2("../resources/textures/awesomeface.png", GL_RGBA);
    Texture::Config();
    Shader program("../resources/shaders/manipshader.glsl");
    glm::vec4 vec(1.0, 0.0, 0.0, 1.0);
    glm::mat4 trans(1.0);
    trans = glm::translate(trans, glm::vec3(1.0, 0.0, 0.0));
    trans = glm::rotate(trans, glm::radians(90.0f), glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.5));
    vec = trans * vec;
    std::cout << vec.x << vec.y << vec.z << std::endl;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        //////////////////////////////////////

        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        float shift = (sin(glfwGetTime() * 2.0)) + 2.6;
        glUniform1f(program.GetUniformLocation("shift"), shift);

        glUniform1i(program.GetUniformLocation("box"), 0);
        glUniform1i(program.GetUniformLocation("happy"), 1);
        glUniformMatrix4fv(program.GetUniformLocation("transform"), 1, GL_FALSE, glm::value_ptr(trans));

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //////////////////////////////////////
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}