#include "adder.h"
#include <iostream>
#include "GLFW/glfw3.h"

int main()
{

    std::cout << "2 + 3 = " << adder::add(2, 3) << std::endl;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        exit(EXIT_FAILURE);
    }
    GLFWwindow* window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}