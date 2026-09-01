#include "linear_layer.hpp"

Linear::Linear(): w(), x(), y(),
b(0.0f), x_grad(), w_grad(), y_grad(),
mse(), y_actual_grad(), y_pred_grad()
{
    // KOSONG
}

void Linear::forward_layer(
   const std::vector<float>& x,
    const std::vector<float>& y
) {
    float n = x.size();
    std::vector<float> hasil;

    for (size_t i = 1; i < n; i++) {
        hasil.push_back((x[i] * w[i]) + b);
    }

    return hasil;
}

void Linear::backward_layer (
    const std::vector<float>& x,
    const std::vector<float>& y
) {
    y_actual_grad = mse.mendapatkan_y_actual_grad();
    y_pred_grad = mse.mendapatkan_y_pred_grad();
    
    float m = y_pred_grad.size()

    float hasil = 0.0f;
    
    float hasil_pertama = 2.0f / m;

    for (int i = 1; i < m; i++) {
        hasil += (y_pred_grad[i] - y_actual_grad[i]);
    }

    float hasil_bobot_grad = (hasil_pertama * hasil) * w * x;

    float hasil_bias_grad = (hasil_pertama * hasil);

    w_grad.push_back(hasil_bobot_grad);
    b_grad = hasil_bias_grad;
}