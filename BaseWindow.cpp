//
// Created by srdczk on 2020/6/4.
//

#include "BaseWindow.h"
#include "Global.h"

int RunBaseWindow(int ac, char **av) {
    // set for glfw's window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    auto window = glfwCreateWindow(kWidth, kHeight, "BaseWindow", nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to create openGL window\n";
        glfwTerminate();
        return -1;
    }
    // init context for window
    glfwMakeContextCurrent(window);
    // glad -> manage openGL
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD\n";
        return -1;
    }
    // add openGL's windows's size
    glViewport(0, 0, kWidth, kHeight);
    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
    // render loop
    // check if should close
    while (!glfwWindowShouldClose(window)) {
        ProcessInput(window);
        // add color
        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        // check poller
        glfwPollEvents();
        // render(double buffer)
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}

