#ifndef MEAN_SQUARED_ERROR
#define MEAN_SQUARED_ERROR

#include <vector>
#include <cmath>
#include <algrotihm>
#include "linear_layer.hpp"

class Mean_Squared_Error {
    private:
    Linear();

    std::vector<float> y_actual;
    std::vector<float> y_pred;

    int n;
    int m;

    float b;

    std::vector<float> y_actual_grad;
    std::vector<float> y_pred_grad;

    public:
    Mean_Squared_Error();

    void forward(const std::vector<float>& y_actual,
    const std::vector<float>& y_pred);

    void backward(
        const std::vector<float>& y_actual,
        const std::vector<float>& y_pred
    )

    const std::vector<float> mendapatkan_y_actual_grad const {
        return y_actual_grad;
    } 

    const std::vector<float> mendapatkan_y_pred_grad const {
        return y_pred_grad;
    }

};

#endif