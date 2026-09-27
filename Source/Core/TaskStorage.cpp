#include "TaskStorage.h"

#include "TaskManager.h"

#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include <sstream>
#include <stdexcept>

TaskStorage::TaskStorage(const std::string& fileName)
    : fileName(fileName)
{
}

void TaskStorage::Save(const TaskManager& taskManager)
{
    nlohmann::json data;

    std::ifstream input(fileName);

    if (input.is_open())
    {
        input >> data;
    }

    input.close();

    std::string dateString =
        DateToString(taskManager.GetSelectedDate());

    data[dateString]["tasks"] = nlohmann::json::array();

    for (const auto& task : taskManager.GetTasks())
    {
        data[dateString]["tasks"].push_back({
            {"name", task.GetName()},
            {"completed", task.IsCompleted()}
            });
    }

    std::ofstream output(fileName);

    if (!output.is_open())
    {
        throw std::runtime_error(
            "Не удалось открыть JSON-файл для записи");
    }

    output << data.dump(4);

    if (!output)
    {
        throw std::runtime_error(
            "Ошибка записи в JSON-файл");
    }
}

void TaskStorage::Load(TaskManager& taskManager)
{
    std::ifstream input(fileName);

    if (!input.is_open())
    {
        return;
    }

    nlohmann::json data;
    input >> data;

    input.close();

    std::string dateString =
        DateToString(taskManager.GetSelectedDate());

    if (!data.contains(dateString))
    {
        return;
    }

    taskManager.ClearTasks();

    for (const auto& task : data[dateString]["tasks"])
    {
        std::string name =
            task["name"].get<std::string>();

        bool completed =
            task["completed"].get<bool>();

        taskManager.AddTask(name);

        const auto& tasks = taskManager.GetTasks();

        taskManager.SetTaskCompleted(
            tasks.size() - 1,
            completed);
    }
}

std::string TaskStorage::DateToString(
    const std::chrono::year_month_day& date) const
{
    std::ostringstream stream;

    stream << std::setw(2) << std::setfill('0')
        << unsigned(date.day());

    stream << "-";

    stream << std::setw(2) << std::setfill('0')
        << unsigned(date.month());

    stream << "-";

    stream << int(date.year());

    return stream.str();
}