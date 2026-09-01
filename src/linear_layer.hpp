#include "linear_layer.hpp"

Linear::Linear(): w(), x(), y(),
b(0.0f), x_grad(), w_grad(), y_grad()
{
    // KOSONG
}

void Linear::forward_layer(
   const std::vector<float>& x,
    const std::vector<float>& y
) {
    float n = x.size();
    std::vector<float> hasil;
    for (int i = 1; i < n; i++) {
        hasil += (x[i] * w[i]) + b;
    }

    return hasil;
}

void Linear::backward_layer (
    
)