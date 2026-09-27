#pragma once

#include "../Core/TaskManager.h"
#include "../UI/TaskWindow.h"
#include <GLFW/glfw3.h>

class Application {
public:
    Application();

    void Run();

private:
    TaskManager taskManager;
    TaskWindow taskWindow;
    GLFWwindow* window;
};