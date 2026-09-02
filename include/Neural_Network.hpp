#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include "linear_layer.hpp"
#include "mean_squared_error.hpp"
#include "optimisasi_neuron.hpp"
#include <iostream>

class latihan_deeplearning {
    private:
    Linear();
    Mean_Squared_Error();
    Optimisasi_Adam();
    
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
    
    // Variabel dan parameter pada optimisasi update learning ADAM
    float alpha;
    float epsilon;
    float g_t;
    float g_t2;
    float beta_1;
    float beta_2;

    public:
    latihan_deeplearning();

    void forward_model();
    void backward_model();
     
    void pelatihan_model();

    void pembersihan_memori();
};

#endif