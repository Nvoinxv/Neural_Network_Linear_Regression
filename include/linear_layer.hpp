#ifndef LINEAR_LAYER_HPP
#define LINEAR_LAYER_HPP

#include <vector>
#include <algrotihm>
#include "mean_squared_error.hpp"

class Linear {
    private:
    Mean_Squared_Error mse;
    std::vector<float> x;
    std::vector<float> w;
    std::vector<float> y;

    float b;

    std::vector<float> x_grad;
    std::vector<float> w_grad;
    std::vector<float> y_grad;
    float b_grad;

    public:
    Linear linear;

    void forward_layer(const std::vector<float>& x,
        const std::vector<float>& y
    );

    void backward_layer(const std::vector<float>& x,
    const std::vector<float>& y);

    const std::vector<float> mendapatkan_x_grad() const {
        return x_grad;
    }

    const std::vector<float> mendapatkan_y_grad() const {
        return y_grad;
    }

    const std::vector<float> mendapatkan_w_grad() const {
        return w_grad;
    }
    
    const float mendapatkan_b_grad() const {
        return b_grad;
    }
    
};

#endif