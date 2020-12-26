#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glUtils.h>
#include <gldebug.h>
#include <cmath>
#include <iostream>

//test texture (using std_image header only lib)

float vertices[] = {
    0.5f, 0.5f, 0.0f, 0.5f, 0.1f, 0.7f, 1.0f, 1.0f,
    0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.4f, 1.0f, 0.0f,
    -0.5f, -0.5f, 0.0f, 0.3f, 0.9f, 0.7f, 0.0f, 0.0f,
    -0.5f, 0.5f, 0.0f, 0.6f, 0.1f, 0.2f, 0.0f, 1.0f};
unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3};

int main()
{
    auto window = CreateApp("hello", 800, 600);

    Shader program("../resources/shaders/textureshader.glsl");
    VertexArray VAO;
    VertexBuffer VBO(vertices, sizeof(vertices));
    VertexBufferLayout layout;
    layout.Pushfloat(3);
    layout.Pushfloat(3);
    layout.Pushfloat(2);
    VAO.AddBuffer(VBO, layout);
    ElementBuffer EBO(indices, 6);

    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../resources/textures/container.jpg", &width, &height, &nrChannels, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    LOG(width);

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