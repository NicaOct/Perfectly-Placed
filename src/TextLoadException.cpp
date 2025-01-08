#include "../headers/TextLoadException.h"

TextLoadException::TextLoadException(const std::string& path)
    : message("Failed texture: " + path), path(path) {}

const char* TextLoadException::what() const noexcept {
    return message.c_str();
}

const std::string& TextLoadException::GetFilePath() const {
    return path;
}
