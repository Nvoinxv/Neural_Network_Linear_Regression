#include "optimisasi_neuron.hpp"

Optimisasi_Adam::Optimisasi_Adam(): 
    beta_1(0.9f),
    beta_2(0.999f),
    alpha(0.01f),
    epsilon(1e-8f),
    m_w(0.0f),
    v_w(0.0f),
    m_b(0.0f),
    v_b(0.0f),
    t(0)
{
    // Inisialisasi parameter optimisasi ADAM
}

void Optimisasi_Adam::update(
    float& w,
    float& b,
    float w_grad,
    float b_grad
) {
    t++;

    // 1. Momentum Gradient (m)
    m_w = (beta_1 * m_w) + ((1.0f - beta_1) * w_grad);
    m_b = (beta_1 * m_b) + ((1.0f - beta_1) * b_grad);

    // 2. Kekuatan Varians Gradient (v)
    v_w = (beta_2 * v_w) + ((1.0f - beta_2) * (w_grad * w_grad));
    v_b = (beta_2 * v_b) + ((1.0f - beta_2) * (b_grad * b_grad));

    // 3. Koreksi Bias (Bias Correction)
    float koreksi_m1 = 1.0f - std::pow(beta_1, static_cast<float>(t));
    float koreksi_v2 = 1.0f - std::pow(beta_2, static_cast<float>(t));

    float m_w_topi = m_w / (koreksi_m1 > 0.0f ? koreksi_m1 : 1.0f);
    float m_b_topi = m_b / (koreksi_m1 > 0.0f ? koreksi_m1 : 1.0f);

    float v_w_topi = v_w / (koreksi_v2 > 0.0f ? koreksi_v2 : 1.0f);
    float v_b_topi = v_b / (koreksi_v2 > 0.0f ? koreksi_v2 : 1.0f);

    // 4. Update Parameter Bobot (w) dan Bias (b)
    w = w - (alpha * m_w_topi / (std::sqrt(v_w_topi) + epsilon));
    b = b - (alpha * m_b_topi / (std::sqrt(v_b_topi) + epsilon));
}