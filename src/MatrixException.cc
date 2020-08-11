#include "MatrixException.h"
#include <utility>

MatrixException::MatrixException(std::string message) noexcept
    : msg(std::move(message))
{
}

MatrixException::MatrixException(const MatrixException& other_exception) noexcept
    : msg(other_exception.msg)
{
}

MatrixException::MatrixException(MatrixException&& other_exception) noexcept
    : msg(other_exception.msg)
{
    other_exception.msg.clear();
}

char const* MatrixException::what() const
{
    return msg.c_str();
}
