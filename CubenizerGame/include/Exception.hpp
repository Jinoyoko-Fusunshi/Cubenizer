#pragma once

#include <exception>
#include <string>

class Exception : std::exception {
private:
    std::string message {};

public:
    Exception() = default;
    explicit Exception(std::string message) : message(message) {}
    ~Exception() = default;

    const char* what() const noexcept override { return message.c_str(); }
};