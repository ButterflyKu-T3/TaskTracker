#include "TaskWindow.h"
#include "imgui.h"
#include <vector>
#include "misc/cpp/imgui_stdlib.h"

#include <chrono>

TaskWindow::TaskWindow(TaskManager& taskManager)
    : taskManager(taskManager)
{
}

void TaskWindow::Draw()
{
    ImGui::Begin("TaskTracker");

    auto date = taskManager.GetSelectedDate();

    ImGui::Text(
        "%s",
        std::format(
            "{:02}.{:02}.{}",
            unsigned(date.day()),
            unsigned(date.month()),
            int(date.year())
        ).c_str()
    );

    const std::vector<Task>& tasks = taskManager.GetTasks();

    for (size_t i = 0; i < tasks.size(); i++)
    {
        const Task& task = tasks[i];

        bool completed = task.IsCompleted();

        if (ImGui::Checkbox(task.GetName().c_str(), &completed))
        {
            taskManager.SetTaskCompleted(i, completed);
        }

    }

    if (!showAddTask)
    {
        if (ImGui::Button("+ Добавить задачу"))
        {
            showAddTask = !showAddTask;
        }
    }
    else
    {
        ImGui::Text("Название задачи:");
        ImGui::SameLine();

        ImGui::InputText("##taskName", &taskName);

        if (ImGui::Button("Добавить"))
        {
            taskManager.AddTask(taskName);
            taskName.clear();
            showAddTask = false;
        }

    }

    ImGui::End();
}