#ifndef LINEAR_LAYER_HPP
#define LINEAR_LAYER_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Linear {
    private:
    float w;
    float b;

    float w_grad;
    float b_grad;

    public:
    Linear();

    std::vector<float> forward_layer(
        const std::vector<float>& x
    );

    void backward_layer(
        const std::vector<float>& x,
        const std::vector<float>& y_actual,
        const std::vector<float>& y_pred
    );

    float mendapatkan_w() const {
        return w;
    }

    float mendapatkan_b() const {
        return b;
    }

    float mendapatkan_w_grad() const {
        return w_grad;
    }
    
    float mendapatkan_b_grad() const {
        return b_grad;
    }

    void perbarui_bobot_bias(float w_baru, float b_baru) {
        w = w_baru;
        b = b_baru;
    }
};

#endif