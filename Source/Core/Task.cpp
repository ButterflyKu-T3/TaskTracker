#include "Task.h"

Task::Task(const std::string& name)
    : name(name), completed(false)
{
}

const std::string& Task::GetName() const
{
    return name;
}

bool Task::IsCompleted() const
{
    return completed;
}

void Task::SetCompleted(bool completed)
{
    this->completed = completed;
}