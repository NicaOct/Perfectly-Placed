#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <exception>
#include <string>

class MyExcpetion : public std::exception {
public:
    explicit MyExcpetion(std::string  message);
    [[nodiscard]] const char* what() const noexcept override;
private:
    std::string message;
};

#endif //MYEXCEPTION_H
