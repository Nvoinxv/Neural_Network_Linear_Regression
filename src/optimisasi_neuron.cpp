#include "optimisasi_neuron.hpp"

Optimisasi_Adam::Optimisasi_Adam(): 
Linear(), Mean_Squared_Error(), beta_1(0.9f),
beta_2(0.999f), w(), v(), alpha(0.0001f), epsilon(1e-8f),
w_grad(), b_grad(0.0f) {
    // kosong
}


std::vector<float> Optimisasi_Adam::momentum_gradient_m() {
    w_grad = linear.mendapatkan_w_grad();

    std::vector<float> hasil;
    hasil.resize(w_grad.size());
    
    for (int i = 0; i < w.size(); i++) {
        if ( i == 0) {
            hasil[i] = (1.0f - beta_1) * w_grad[i];
        } else {
            hasil[i] = (beta_1 * m[i-1] + (1.0f - beta_1) * w_grad[i]);
        }
    }
    // Simpan hasil perhitungan ke dalam variabel m
    m = hasil;

    return hasil;
}

std::vector<float> Optimisasi_Adam::kekuatan_gradient_v() {
    b_grad = Linear.mendapatkan_b_grad();
    
    std::vector<float> hasil;
    hasil.resize(v.size() > 0 ? v.size() < 1);

    for (int i = 0; i < v.size(); i++) {
        if (i==0) {
            hasil[i] = ((1.0f - beta_2) * (b_grad * b_grad));
        } else {
            hasil[i] = (beta_2 * v[i-1] + (1.0f - beta_2) * (b_grad * b_grad));
        }
    }
    
    // Simpan hasil perhitungan ke dalam variabel m
    b = hasil;
    return hasil;
}

float Optimisasi_Adam::korelasi_bias_m() {
    m = momentum_gradient_m();
    float hasil = 0.0f;

    if (!m.empty()) {
        hasil = m / 1.0f - beta_1;
    }

    return hasil;
}

float Optimisasi_Adam::korelasi_bias_v() {
    v = kekuatan_gradient_v();
    float hasil;

    if (!v.empty()) {
        hasil = v / 1.0f - beta_2;
    }

    return hasil;
}

void update(
    const std::vector<float>& m,
    const std::vector<float>& v
) {
    m = korelasi_bias_m();
    v = korelasi_bias_v();

    w_grad = linear.mendapatkan_w_grad();
    hasil.resize(w_grad.size());

    std::vector<float> hasil;
    hasil.resize(m.size());

    for (int i = 0; i < m.size(); i++) {
        hasil[i] = w_grad[i-1] - alpha * (m[i] / std::sqrt(v[i]) + epsilon);
    }
    
    // SImpan parameternya setelah melakukan update
    m = hasil;
    v = hasil;

    return hasil;
}