#include "algebra.h"

using namespace algebra;

template<typename T>
static MATRIX<T> creat_matrix_by_value(std::size_t rows, std::size_t columns, T value);

template<typename T>
static MATRIX<T> creat_matrix_by_random(std::size_t rows, std::size_t columns, T lowerBound, T upperBound);

template<typename T>
static MATRIX<T> creat_matrix_identity(std::size_t rank);

template<typename T>
MATRIX<T> create_matrix(std::size_t rows, std::size_t columns,
                        std::optional<MatrixType> type = MatrixType::Zeros,
                        std::optional<T> lowerBound = std::nullopt, std::optional<T> upperBound = std::nullopt) {
    if (rows <= 0 || columns <= 0) {
        return nullptr;
    }
    MATRIX<T> retMatrix;
    switch (type.value()) {

        case MatrixType::Zeros:
            retMatrix = creat_matrix_by_value<T>(rows, columns, 0);
            break;
        case MatrixType::Ones:
            retMatrix = creat_matrix_by_value<T>(rows, columns, 0);
            break;
        case MatrixType::Identity:
            if (rows != columns) {
                return nullptr;
            }
            retMatrix = creat_matrix_identity<T>(rows);
            break;
        case MatrixType::Random:
            if (!lowerBound.has_value() || !upperBound.has_value()) {
                return nullptr;
            }
            retMatrix = creat_matrix_by_random(rows, columns, lowerBound, upperBound);
            break;
        default:
            return nullptr;
    }
    return retMatrix;
}

template<typename T>
MATRIX<T> algebra::create_matrix(std::size_t rows, std::size_t columns, std::optional<MatrixType> type,
                                 std::optional<T> lowerBound, std::optional<T> upperBound) {
    return MATRIX<T>();
}

template<typename T>
double determinant(const MATRIX<T> &matrix) {
    return 0;
}

template<typename T>
void display(const MATRIX<T> &matrix) {

}

template<typename T>
MATRIX<T> hadamard_product(const MATRIX<T> &matrixA, const MATRIX<T> &matrixB) {
    return MATRIX<T>();
}

template<typename T>
MATRIX<T> inverse(const MATRIX<T> &matrix) {
    return MATRIX<T>();
}

template<typename T>
MATRIX<T> multiply(const MATRIX<T> &matrixA, const MATRIX<T> &matrixB) {
    return MATRIX<T>();
}

template<typename T>
MATRIX<T> algebra::multiply(const MATRIX<T> &matrixA, T scalar) {
    return MATRIX<T>();
}

template<typename T>
MATRIX<T> sum_sub(const MATRIX<T> &matrixA, const MATRIX<T> &matrixB, std::optional<std::string> operation) {
    return MATRIX<T>();
}

template<typename T>
T trace(const MATRIX<T> &matrix) {
    return nullptr;
}

template<typename T>
MATRIX<T> transpose(const MATRIX<T> &matrix) {
    return MATRIX<T>();
}

template<typename T>
static MATRIX<T> creat_matrix_by_value(std::size_t rows, std::size_t columns, T value) {
    std::vector<T> line(rows, value);
    MATRIX<T> retMatrix(columns, line);
    return retMatrix;
}

template<typename T>
static MATRIX<T> create_matrix_random(std::size_t rows, std::size_t columns,
                                      T lowerBound, T upperBound) {
    if (lowerBound >= upperBound) {
        return nullptr;
    }
    std::random_device rd; // 用于生成种子
    std::default_random_engine eng(rd()); // 使用随机种子初始化引擎
    // 指定随机数的范围
    std::uniform_int_distribution<T> genRandom(lowerBound, upperBound); // 生成1到100之间的整数
    MATRIX<T> retMatrix;
    for (const auto &line: retMatrix) {
        for (const auto &item: line) {
            item = genRandom(eng);
        }
    }
    return retMatrix;
}

template<typename T>
static MATRIX<T> create_matrix_identity(std::size_t rank) {
    MATRIX<T> retMatrix = creat_matrix_by_value(rank, rank, 0);
    for (std::size_t i = 0; i < rank; i++) {
        for (std::size_t j = 0; j < rank; ++j) {
            if (i == j) {
                retMatrix[i, j] = 1;
            }
        }
    }
    return retMatrix;
}

