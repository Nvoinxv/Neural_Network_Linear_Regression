#include "mean_squared_error.hpp"

Mean_Squared_Error::Mean_Squared_Error(): 
y_actual(), y_pred(), n(0), m(0), y_actual_grad(), 
y_pred_grad(), w_grad(), linear() {
    // kosong
}

void Mean_Squared_Error::forward(
    const std::vector<float>& y_actual,
    const std::vector<float>& y_pred
) {
    m = y_pred.size();
    float hasil_pertama = 1.0f / m;

    float hasil_kedua = 0.0f;

    for (int i = 0; i < m; i++) {
        hasil_kedua += std::pow(y_pred[i] - y_actual[i], 2);
    }

    float hasil = hasil_pertama * hasil_kedua;

    return hasil;
}

void Mean_Squared_Error::backward(
    const std::vector<float>& y_actual,
    const std::vector<float>& y_pred
) {
    m = y_pred.size();
    
    float hasil_pertama = 1.0f / m;
    float hasil_loss = 0.0f;
    
    // Gradient berat
    for (int i = 0; i < m; i++) {
        hasil_loss += (y_pred[i] - y_actual[i]);
    }

    float hasil_linear_gradient = hasil_pertama * hasil_loss;
    
    y_pred_grad.push_back(hasil_linear_gradient);
    y_actual_grad.push_back(hasil_linear_gradient);
    w_grad.push_back(hasil_linear_gradient)

    return hasil_linear_gradient;
}