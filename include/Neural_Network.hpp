#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include "linear_layer.hpp"
#include "mean_squared_error.hpp"
#include "optimisasi_neuron.hpp"
#include "print_output.hpp"
#include <iostream>
#include <vector>

class latihan_deeplearning {
    private:
    Linear linear;
    Mean_Squared_Error mse;
    Optimisasi_Adam optimizer;
    Print_Vektor printer;
    
    // Ini berguna untuk bagian mencari loss
    std::vector<float> y_actual;
    std::vector<float> y_pred;

    // Ini berguna untuk bagian mencari bobot dan bias pada model linear
    std::vector<float> x;
    std::vector<float> y;
    float w;
    float b;

    // Ini versi pada penyimpanan backward
    float w_grad;
    float b_grad;

    public:
    latihan_deeplearning();

    void forward_model(const std::vector<float>& x,
                       const std::vector<float>& y);

    void backward_model(const std::vector<float>& x,
                        const std::vector<float>& y);
     
    void pelatihan_model(const std::vector<float>& x_train,
                         const std::vector<float>& y_train,
                         int epoch = 100);

    void evaluasi_model(const std::vector<float>& x_test,
                        const std::vector<float>& y_test);

    void pembersihan_memori();
};

#endif