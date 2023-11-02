#include <GLFW/glfw3.h>

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1080

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
                                          "Quill", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
