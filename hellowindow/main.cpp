#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main()
{
    glfwInit(); // inicialização do GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // especifica a versão máxima do openGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // especifica a versao minima do opengl
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // especifica que a aplicação usara o nucleo do opengl como perfil
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // para inicialização no MACOS

    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello OPENGL", NULL, NULL); // cria uma janela GLFW
    if (window == NULL) {
        cout << "Falha ao criar a janela GLFW" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); // insere o contexto da janela na thread principal

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { // inicializa o GLAD
        cout << "Falha ao inicializar GLAD" << endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while(!glfwWindowShouldClose(window))
    {
        // entrada
        processInput(window);

        // renderização
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // checagem, chamada de eventos e troca de buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
