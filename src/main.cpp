#include <glad/glad.h>  // Исправленный путь - с подпапкой glad
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Настройка версии OpenGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Создание окна
    GLFWwindow* window = glfwCreateWindow(640, 480, "BattleCity", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Загрузка GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD!" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;

    // Установка цвета очистки (желтый)
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

    // Основной цикл
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}