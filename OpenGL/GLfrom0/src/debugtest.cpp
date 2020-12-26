#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glUtils.h>
#include <cmath>
#include <iostream>
#include <gldebug.h>

int main()
{
    // glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
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
        float base = 1.2;
        program.Bind();
        int i = program.GetUniformLocation("baase");
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glClearError();
        glUniform1f(0, 1.2);
        glCheckError();

        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawElements(GL_TRIANGLES, 6, GL_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}