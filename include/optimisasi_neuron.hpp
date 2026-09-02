#ifndef OPTIMISASI_NEURON
#define OPTIMISASI_NEURON

#include <vector>
#include <cmath>
#include <iostream>

class Optimisasi_Adam {
    private:
    float beta_1;
    float beta_2;
    float alpha;
    float epsilon;
    
    // Momentum (m) dan kekuatan varians gradient (v) untuk bobot (w) dan bias (b)
    float m_w;
    float v_w;
    float m_b;
    float v_b;

    int t; // Langkah iterasi waktu (time step)
    
    public:
    Optimisasi_Adam();

    void update(
        float& w,
        float& b,
        float w_grad,
        float b_grad
    );
};

#endif