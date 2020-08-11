//
// Created by Ezra on 2020/7/7.
//

#ifndef MATRIX_MATRIXEXCEPTION_H
#define MATRIX_MATRIXEXCEPTION_H

#include <exception>
#include <string>

class MatrixException : public std::exception {
private:
    std::string msg;

public:
    MatrixException(std::string message) noexcept;

    MatrixException(const MatrixException& other_exception) noexcept;

    MatrixException(MatrixException&& other_exception) noexcept;

    char const* what() const override;
};

#endif //MATRIX_MATRIXEXCEPTION_H
