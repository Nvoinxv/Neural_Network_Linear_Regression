#ifndef PEMBAGIAN_PELATIHAN_HPP
#define PEMBAGIAN_PELATIHAN_HPP

#include <iostream>

struct pembagian_pelatihan_test {
    std::vector<float> hasil_pelatihan,
    std::vector<float> hasil_test
};

class Pembagian_Pelatihan {
    private:
    std::vector<float> x;
    std::vector<float> y;

    float ukuran_test;
    float ukuran_pelatihan;

    public:
    Pembagian_Pelatihan();

    void fit_pembagian(
        std::vector<float>& x,
        std::vector<float>& y,
        float ukuran_test,
        float ukuran_pelatihan
    );
};

#endif