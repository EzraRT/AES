#include "Matrix.h"
#include "MatrixException.h"

void Row::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
}

Row::Row(const unsigned char *new_data, size_t data_size)
        : size(data_size) {
    data = new unsigned char[size];
    memcpy(data, new_data, sizeof(unsigned char) * size);
}

Row::Row(std::initializer_list<unsigned char> list)
        : size(list.size()) {
    data = new unsigned char[size];
    std::copy(list.begin(), list.end(), data);
}

Row::Row(const Row &row)
        : size(row.size) {
    data = new unsigned char[size];
    memcpy(data, row.data, sizeof(unsigned char) * size);
}

Row::Row(Row &&row) {
    clear();
    data = row.data;
    row.data = nullptr;
    size = row.size;
}

Row::~Row() {
    clear();
}

unsigned char Row::operator[](int index) const {
    return data[index];
}


Matrix::Matrix(size_t _row, size_t _col)
        : row(_row), col(_col) {
    data = new unsigned char *[row];
    for (size_t i = 0; i < row; ++i) {
        data[i] = new unsigned char[col];
    }
}

Matrix::Matrix(
        const Matrix &other_matrix)
        : row(other_matrix.row), col(other_matrix.col) {
    data = new unsigned char *[row];
    for (size_t i = 0; i < row; ++i) {
        data[i] = new unsigned char[col];
    }
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            data[i][j] = other_matrix.data[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&other_matrix) noexcept
        : row(other_matrix.row), col(other_matrix.col), data(other_matrix.data) {
    other_matrix.data = nullptr;
}

Matrix Matrix::operator+(const Matrix &other_matrix) const {
    if (this->row != other_matrix.row) {
        throw MatrixException("mat1.row!=mat2.row");
    }
    if (this->col != other_matrix.col) {
        throw MatrixException("mat1.col!=mat2.col");
    }
    Matrix mat(row, col);
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            mat.data[i][j] = data[i][j] + other_matrix.data[i][j];
        }
    }
    return mat;
}

Matrix Matrix::operator-(const Matrix &other_matrix) const {
    if (this->row != other_matrix.row) {
        throw MatrixException("mat1.row!=mat2.row");
    }
    if (this->col != other_matrix.col) {
        throw MatrixException("mat1.col!=mat2.col");
    }
    Matrix mat(row, col);
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            mat.data[i][j] = data[i][j] - other_matrix.data[i][j];
        }
    }
    return mat;
}

Matrix Matrix::operator*(const Matrix &other_matrix) const {
    if (this->col != other_matrix.row) {
        throw MatrixException("mat1.col!=mat2.row");
    }
    Matrix mat(row, other_matrix.col);
    for (int i = 0; i < mat.row; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            for (int k = 0; k < col; ++k) {
                mat.data[i][j] += data[i][k] * other_matrix.data[k][j];
            }
        }
    }
    return mat;
}

Matrix Matrix::operator+=(const Matrix &other_matrix) {
    if (this->row != other_matrix.row) {
        throw MatrixException("mat1.row!=mat2.row");
    }
    if (this->col != other_matrix.col) {
        throw MatrixException("mat1.col!=mat2.col");
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] += other_matrix.data[i][j];
        }
    }
}

Matrix Matrix::operator-=(const Matrix &other_matrix) {
    if (this->row != other_matrix.row) {
        throw MatrixException("mat1.row!=mat2.row");
    }
    if (this->col != other_matrix.col) {
        throw MatrixException("mat1.col!=mat2.col");
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            data[i][j] -= other_matrix.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < row; ++i) {
        delete[] data[i];
    }
    delete[] data;
}
