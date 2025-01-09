#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

/**
 * @file MyException.h
 * @brief Custom exception class for handling specific application errors.
 */

/**
 * @class MyExcpetion
 * @brief A custom exception class inheriting from `std::exception`.
 *
 * This class allows for more descriptive error messages tailored to the application's needs.
 */

class MyExcpetion : public std::exception {
public:
    explicit MyExcpetion(std::string  message);
    [[nodiscard]] const char* what() const noexcept override;
private:
    std::string message;
};

#endif //MYEXCEPTION_H
