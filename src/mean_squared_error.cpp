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
    m = y_ppred.size();
    int hasil_pertama = 1.0 / m;

    float hasil_kedua;

    for (int i = 0; i < m; i++) {
        hasil_kedua += std::pow(y_pred - y_actual, 2);
    }

    float hasil = hasil_pertama * hasil_kedua;

    return hasil;
}

void Mean_Squared_Error::backward(
    const std::vector<float>& y_actual,
    const std::vector<float>& y_pred
) {
    m = y_pred.size();
    
    int hasil_pertama = 2 / m;
    float hasil_loss;

    for (int i = 0; i < m; i++) {
        hasil_loss += (y_pred - y_actual) 
    }

    float hasil_linear_gradient = hasil_pertama * hasil_loss * w * x;

    return hasil_linear_gradient;
}