#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include "linear_layer.hpp"
#include "mean_squared_error.hpp"
#include "optimisasi_neuron.hpp"

class latihan_deeplearning {
    private:
    Linear();
    Mean_Squared_Error();
    
    // Ini berguna untuk bagian mencari loss
    std::vector<float> y_actual;
    std::vector<float> y_pred;

    // Ini berguna untuk bagian mencari bobot dan bias pada model linear
    std::vector<float> x;
    std::vector<float> y;
    float b;

    // Ini versi pada penyimpanan backward
    std::vector<float> x_grad;
    std::vector<float> w_grad;
    std::vector<float> y_grad;
    float b_grad;

    public:
    latihan_deeplearning();

    void forward_model();
    void backward_model();
     
    void pelatihan_model();
};

#endif