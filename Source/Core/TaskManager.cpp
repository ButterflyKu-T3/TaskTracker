#include "TaskManager.h"

TaskManager::TaskManager()
{
    selectedDate = std::chrono::year_month_day{
        std::chrono::floor<std::chrono::days>(
            std::chrono::current_zone()->to_local(
                std::chrono::system_clock::now()
            )
        )
    };

    AddTask("Учить C++");
    AddTask("Спорт");
    AddTask("Читать книгу");
}

void TaskManager::AddTask(const std::string& name)
{
    if (!name.empty())
    {
        tasks.emplace_back(name);
    }
}

void TaskManager::SetTaskCompleted(size_t index, bool completed)
{
    tasks[index].SetCompleted(completed);
}

void TaskManager::ClearTasks()
{
    tasks.clear();
}

const std::vector<Task>& TaskManager::GetTasks() const
{
    return tasks;
}

const std::chrono::year_month_day& TaskManager::GetSelectedDate() const
{
    return selectedDate;
}