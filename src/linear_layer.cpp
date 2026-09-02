#include "linear_layer.hpp"

Linear::Linear(): 
    w(0.5f), b(0.0f), w_grad(0.0f), b_grad(0.0f)
{
    // Inisialisasi bobot awal secara manual
}

std::vector<float> Linear::forward_layer(
    const std::vector<float>& x
) {
    int n = x.size();
    std::vector<float> hasil;
    hasil.resize(n);

    for (int i = 0; i < n; i++) {
        hasil[i] = (x[i] * w) + b;
    }

    return hasil;
}

void Linear::backward_layer(
    const std::vector<float>& x,
    const std::vector<float>& y_actual,
    const std::vector<float>& y_pred
) {
    int m = y_pred.size();
    if (m == 0) {
        return;
    }

    float hasil_pertama = 2.0f / static_cast<float>(m);

    float grad_w_total = 0.0f;
    float grad_b_total = 0.0f;

    for (int i = 0; i < m; i++) {
        float selisih = y_pred[i] - y_actual[i];
        grad_w_total += selisih * x[i];
        grad_b_total += selisih;
    }

    w_grad = hasil_pertama * grad_w_total;
    b_grad = hasil_pertama * grad_b_total;
}
