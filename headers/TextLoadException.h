#ifndef TEXTLOADEXCEPTION_H
#define TEXTLOADEXCEPTION_H

#include <exception>
#include <string>

#include <exception>
#include <string>

class TextLoadException : public std::exception {
public:
    explicit TextLoadException(const std::string& path);
    [[nodiscard]] const char* what() const noexcept override;
    [[nodiscard]] const std::string& GetFilePath() const;

private:
    std::string message;
    std::string path;
};

#endif //TEXTLOADEXCEPTION_H
