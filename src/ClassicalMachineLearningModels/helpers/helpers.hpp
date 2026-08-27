#include<iostream>
#include<vector>
using namespace std;

#include "../../datatypes.hpp"

template <typename T, typename U>
bool validateDataType(U& value) {
    return typeid(T) == typeid(value);
}

double toDouble(const DataType& value) {
    return visit([](auto v) {
        return static_cast<double>(v);
    }, value);
}

vector<double> serializeVector(const vector<DataType>& vec) {
    if (vec.empty()) return {};

    vector<double> result(vec.size(), 0.0);
    for (size_t i = 0; i < vec.size(); i++) {
        result[i] = toDouble(vec[i]);
    }

    return result;
}

vector<vector<double>> serializeMatrix(const vector<vector<DataType>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return {};

    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    vector<vector<double>> result(rows, vector<double>(cols, 0.0));
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result[i][j] = toDouble(matrix[i][j]);
        }
    }

    return result;
}

double sum(const vector<double>& vec) {
    if (vec.empty()) return 0;

    double result = 0;
    for (double n: vec) {
        result += n;
    }

    return result;
}

vector<double> nPowerVector(const vector<double>& vec, const int& n = 2) {
    if (vec.empty()) return {};

    vector<double> result(vec.size(), 0.0);
    for (size_t i = 0; i < vec.size(); i++) {
        for (int n = 0; i < n; i++) {
            result[i] += vec[i];
        }
    }

    return result;
}

vector<double> addDoubleVector(const vector<double>& vec, const double& data) {
    vector<double> result(vec.size(), 0.0);

    for (size_t i = 0; i < vec.size(); i++) {
        result[i] = vec[i] + data;
    }

    return result;
}

vector<double> subtractDoubleVector(const vector<double>& vec, const double& value) {
    if (vec.empty()) return {};

    vector<double> result(vec.size(), 0.0);
    for (size_t i = 0; i < vec.size(); i++) {
        result[i] = vec[i] - value;
    }

    return result;
}

vector<double> multiplyDoubleVector(const vector<double>& vec, const double& val) {
    if (vec.empty()) return {};

    vector<double> result(vec.size(), 0.0);
    for (size_t i = 0; i < vec.size(); i++) {
        result[i] = vec[i] * val;
    }

    return result;
}

vector<double> subtractVectors(const vector<double>& vec1, const vector<double>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw invalid_argument("vector sizes does not match");
    }

    vector<double> result(vec1.size(), 0.0);
    for (size_t i = 0; i < result.size(); i++) {
        result[i] = vec1[i] - vec2[i];
    }

    return result;
}

double multiplyVectors(const vector<double>& vec1, const vector<double>& vec2) {
    if (vec1.size() != vec2.size()) {
        throw invalid_argument("Vectors must have same size");
    }

    double result = 0.0;
    for (int i = 0; i < vec2.size(); i++) {
        result += (toDouble(vec1[i]) * toDouble(vec2[i]));
    }

    return result;
}

vector<double> multiplyMatrixVector(const vector<vector<double>>& mat, const vector<double>& vec) {
    if (mat.empty()) {
        throw invalid_argument("X cannot be empty");
    }

    if (mat[0].size() != vec.size()) {
        throw invalid_argument("matrix columns must match vector size in multiplyMatricVector function");
    }

    vector<double> result(mat.size(), 0.0);

    for (size_t i = 0; i < mat.size(); ++i) {
        for (size_t j = 0; j < vec.size(); ++j) {
            result[i] += mat[i][j] * vec[j];
        }
    }

    return result;
}

vector<vector<double>> transposeMatrix(const vector<vector<double>>& matrix) {
    if (matrix.empty()) return {{}};

    vector<vector<double>> result(matrix[0].size(), vector<double>(matrix.size(), 0.0));
    for(size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j < matrix[0].size(); j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}