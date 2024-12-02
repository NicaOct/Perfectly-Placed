#include <utility>

#include "../headers/MyException.h"

MyExcpetion::MyExcpetion(std::string message)
    : message(std::move(message)) {}
const char* MyExcpetion::what() const noexcept {
    return message.c_str();
}

