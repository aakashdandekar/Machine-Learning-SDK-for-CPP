#include<iostream>
#include<vector>
using namespace std;

#include "helpers/helpers.hpp"
#include "../datatypes.hpp"

class LinearRegression {
    private:
        double lr;
        long long n_iters;
        double lambda_;

        vector<double> weight;
        double bias;

        vector<double> loss_history;

    public:
        LinearRegression(double lr = 0.0001,  long long n_iters = 10000, double lambda_ = 0.01) {
            this->lr = lr;
            this->n_iters = n_iters;
            this->lambda_ = lambda_;
        }

        void fit(vector<vector<DataType>> x, vector<DataType> y) {
            int n_samples, n_features;

            n_samples = x.size();
            n_features = x[0].size();

            vector<vector<double>> X = serializeMatrix(x);
            vector<double> Y = serializeVector(y);

            this->weight.assign(n_features, 0.0);
            this->bias = 0.0;

            for (long long i = 0; i < this->n_iters; i++) {
                vector<double> y_pred = addDoubleVector(multiplyMatrixVector(X, this->weight), this->bias);
                vector<double> error = subtractVectors(y_pred, Y);

                // Gradient Descent

                vector<vector<double>> transpose_X = transposeMatrix(X);
                vector<double> dw = multiplyDoubleVector(multiplyMatrixVector(transpose_X, error), 1.0 / n_samples);
                double db = (1.0 / n_samples) * sum(error);

                for (size_t j = 0; j < this->weight.size(); j++) {
                    this->weight[j] -= this->lr * dw[j];
                }

                this->bias -= this->lr * db;

                double mse = sum(nPowerVector(error, 2)) / error.size();
                double penalty = this->lambda_ * sum(nPowerVector(this->weight, 2));
                this->loss_history.push_back(mse + penalty);
            }
        }

        vector<double> predict(const vector<vector<DataType>>& X) {
            vector<vector<double>> x = serializeMatrix(X);
            return addDoubleVector(multiplyMatrixVector(x, this->weight), this->bias);
        }

        double score(const vector<vector<DataType>>& X, const vector<DataType>& Y) {
            vector<double> y = serializeVector(Y);

            vector<double> y_pred = this->predict(X);
            double ss_res = sum(nPowerVector(subtractVectors(y, y_pred), 2));
            double ss_tot = sum(nPowerVector(subtractDoubleVector(y, sum(y)/y.size()), 2));

            return 1 - (ss_res / ss_tot);
        }
};