#pragma once

#include "../Core/TaskManager.h"
#include <string>

class TaskWindow {
public:
    TaskWindow(TaskManager& taskManager);

    void Draw();

private:
    TaskManager& taskManager;
    std::string taskName;
    bool showAddTask = false;
};