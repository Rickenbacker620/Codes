#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glutils.h>
#include <cmath>
#include <iostream>

int main()
{
    auto window = CreateApp("hello", 800, 600);

    float vertices[] = {
        0.5f, 0.5f, 0.0f, 0.5f, 0.1f, 0.7f,
        0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.4f,
        -0.5f, -0.5f, 0.0f, 0.3f, 0.9f, 0.7f,
        -0.5f, 0.5f, 0.0f, 0.6f, 0.1f, 0.2f};
    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3};
    Shader program("../resources/shaders/mixshader.glsl");
    Shader program2("../resources/shaders/mxshader2.glsl");
    VertexArray VAO;
    VertexBuffer VBO(vertices, sizeof(vertices));
    VertexBufferLayout layout;
    layout.Pushfloat(3);
    layout.Pushfloat(3);
    VAO.AddBuffer(VBO, layout);
    ElementBuffer EBO(indices, 6);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float base = (sin(glfwGetTime() * 2.0f)) + 2.6f;
        glUniform1f(program.GetUniformLocation("baase"), base);
        program.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}