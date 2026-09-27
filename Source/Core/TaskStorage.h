#pragma once

#include <chrono>
#include <string>

class TaskManager;

class TaskStorage
{
public:
    explicit TaskStorage(const std::string& fileName);

    void Save(const TaskManager& taskManager);
    void Load(TaskManager& taskManager);

private:
    std::string DateToString(
        const std::chrono::year_month_day& date) const;

    std::string fileName;
};