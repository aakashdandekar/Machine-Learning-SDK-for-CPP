#include <iostream>
#include <vector>
using namespace std;

#include "file_ops.hpp"
#include "ClassicalMachineLearningModels/linear_regression.hpp"

int main(int argc, char **argv) {
    File file("./dataset/LinearRegression/train.csv");
    vector<vector<DataType>> content = file.getData();

    vector<vector<DataType>> X;
    vector<DataType> y;

    for (const auto& row : content) {
        if (row.size() == 2) {
            X.push_back({row[0]});
            y.push_back(row[1]);
        }
    }

    LinearRegression model;
    model.fit(X, y);

    cout << "Model Training Successfull" << endl;

    File test_File("./dataset/LinearRegression/test.csv");
    vector<vector<DataType>> test_content = test_File.getData();

    vector<vector<DataType>> test_X;
    vector<DataType> test_y;

    for (const auto& row : test_content) {
        if (row.size() == 2) {
            test_X.push_back({row[0]});
            test_y.push_back(row[1]);
        }
    }

    cout << "Model Score: " << model.score(test_X, test_y) << endl;

    return 0;
}

