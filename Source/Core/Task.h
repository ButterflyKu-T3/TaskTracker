#pragma once

#include <string>

class Task {

public:
    Task(const std::string& name);

    const std::string& GetName() const;

    bool IsCompleted() const;

    void SetCompleted(bool completed);

private:
    std::string name;
    bool completed;
};