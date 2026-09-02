#include "mean_squared_error.hpp"

Mean_Squared_Error::Mean_Squared_Error(): 
y_actual(), y_pred(), m(0), loss(0.0f), y_actual_grad(), y_pred_grad() {
    // kosong
}

float Mean_Squared_Error::forward(
    const std::vector<float>& y_actual,
    const std::vector<float>& y_pred
) {
    m = y_pred.size();
    if (m == 0) {
        return 0.0f;
    }

    float hasil_pertama = 1.0f / static_cast<float>(m);
    float hasil_kedua = 0.0f;

    for (int i = 0; i < m; i++) {
        hasil_kedua += std::pow(y_pred[i] - y_actual[i], 2.0f);
    }

    loss = hasil_pertama * hasil_kedua;
    return loss;
}

void Mean_Squared_Error::backward(
    const std::vector<float>& y_actual,
    const std::vector<float>& y_pred
) {
    m = y_pred.size();
    if (m == 0) {
        return;
    }
    
    y_pred_grad.clear();
    y_actual_grad.clear();

    float hasil_pertama = 2.0f / static_cast<float>(m);

    for (int i = 0; i < m; i++) {
        float grad = hasil_pertama * (y_pred[i] - y_actual[i]);
        y_pred_grad.push_back(grad);
        y_actual_grad.push_back(-grad);
    }
}