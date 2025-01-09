#ifndef TEXTLOADEXCEPTION_H
#define TEXTLOADEXCEPTION_H

#include <exception>
#include <string>

/**
 * @file TextLoadException.h
 * @brief Defines a custom exception for handling text file loading errors.
 */

/**
 * @class TextLoadException
 * @brief Custom exception class for errors loading texture files.
 *
 * This exception stores the file path of the problematic file.
 */

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
