#include "pembagian_pelatihan.hpp"

Pembagian_Pelatihan::Pembagian_Pelatihan() :
x(), y() {
    // Kosong
}

pembagian_pelatihan_test Pembagian_Pelatihan::fit_pembagian(
    std::vector<float>& x,
    std::vector<float>& y,
    float ukuran_test,
    float ukuran_pelatihan
) {
    pembagian_pelatihan_test hasil;
    
    int total_data = x.size();
    int jumlah_test = total_data * ukuran_test;
    int jumlah_pelatihan = total_data * ukuran_pelatihan;

    hasil.hasil_pelatihan.resize(jumlah_pelatihan);
    hasil.hasil_test.resize(jumlah_test);

    for (int i = 0; i < jumlah_pelatihan; i++) {
        hasil.hasil_pelatihan[i] = x[i] / y[i];
    }

    for (int i = 0; i < jumlah_test; i++) {
        hasil.hasil_test[i] = x[i + jumlah_pelatihan] / y[i + jumlah_pelatihan];
    }

    return hasil;
}