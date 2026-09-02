#ifndef MEAN_SQUARED_ERROR
#define MEAN_SQUARED_ERROR

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

class Mean_Squared_Error {
    private:
    std::vector<float> y_actual;
    std::vector<float> y_pred;

    int m;
    float loss;

    std::vector<float> y_actual_grad;
    std::vector<float> y_pred_grad;

    public:
    Mean_Squared_Error();

    float forward(const std::vector<float>& y_actual,
                  const std::vector<float>& y_pred);

    void backward(
        const std::vector<float>& y_actual,
        const std::vector<float>& y_pred
    );

    const std::vector<float>& mendapatkan_y_actual_grad() const {
        return y_actual_grad;
    } 

    const std::vector<float>& mendapatkan_y_pred_grad() const {
        return y_pred_grad;
    }

};

#endif