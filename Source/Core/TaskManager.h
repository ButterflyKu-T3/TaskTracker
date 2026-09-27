#pragma once

#include "Task.h"
#include <vector>
#include <chrono>
#include <string>

class TaskManager {
public:
    TaskManager();

    void AddTask(const std::string& name);
    void SetTaskCompleted(size_t index, bool completed);

    const std::vector<Task>& GetTasks() const;
    const std::chrono::year_month_day& GetSelectedDate() const;

private:
    std::vector<Task> tasks;
    std::chrono::year_month_day selectedDate;
};