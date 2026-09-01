#ifndef OPTIMISASI_NEURON
#define OPTIMISASI_NEURON

#include <vector>
#include "linear_layer.hpp"
#include "mean_squared_error.hpp"

class Optimisasi_Adam {
    private:
    Linear();
    Mean_Squared_Error();

    float beta_1;
    float beta_2;

    std::vector<float> 

    std::vector<float> m;
    std::vector<float> v;

    std::vector<float> w_grad;
    float b_grad;

    float alpha;
    float epsilon;
    
    public:
    Optimisasi_Adam()

    std::vector<float> momentum_gradient_m();
    std::vector<float> kekuatan_gradient_v();

    float korelasi_bias_m();
    float korelasi_bias_v();

    void update(
        const std::vector<float>& m,
        const std::vector<float>& v
    );
}

#endif