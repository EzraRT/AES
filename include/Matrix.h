#ifndef MATRIX_H
#define MATRIX_H

#include "easyblasdefs.h"
#include <algorithm>

class Row {
private:
    unsigned unsigned char *data = nullptr;
    size_t size;

    void clear();

public:
    Row() = delete;

    Row(const unsigned char *new_data, size_t size);

    Row(std::initializer_list<unsigned char> list);

    Row(const Row &row);

    Row(Row &&row);

    ~Row();

    unsigned char operator[](int index) const;
};

class Matrix {
private:
    size_t row, col;

    unsigned char **data = nullptr;

public:
    Matrix() = delete;

    Matrix(size_t _row, size_t _col);

    Matrix(const Matrix &other_matrix);

    Matrix(Matrix &&other_matrix) noexcept;

    Matrix operator+(const Matrix &other_matrix) const;

    Matrix operator-(const Matrix &other_matrix) const;

    Matrix operator*(const Matrix &other_matrix) const;

    Matrix operator+=(const Matrix &other_matrix);

    Matrix operator-=(const Matrix &other_matrix);

    Matrix operator*=(const Matrix &other_matrix);

    Row operator[](int row_index) const;

    ~Matrix();
};

#endif // MATRIX_H