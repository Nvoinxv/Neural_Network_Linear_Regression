#ifndef PEMBAGIAN_PELATIHAN_HPP
#define PEMBAGIAN_PELATIHAN_HPP

#include <iostream>
#include <vector>

struct pembagian_pelatihan_test {
    std::vector<float> hasil_pelatihan_x;
    std::vector<float> hasil_pelatihan_y;
    std::vector<float> hasil_test_x;
    std::vector<float> hasil_test_y;
};

class Pembagian_Pelatihan {
    private:
    std::vector<float> x;
    std::vector<float> y;

    float ukuran_test;
    float ukuran_pelatihan;

    public:
    Pembagian_Pelatihan();

    pembagian_pelatihan_test fit_pembagian(
        std::vector<float>& x,
        std::vector<float>& y,
        float ukuran_test,
        float ukuran_pelatihan
    );
};

#endif