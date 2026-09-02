#include "pembagian_pelatihan.hpp"

Pembagian_Pelatihan::Pembagian_Pelatihan() :
x(), y(), ukuran_test(0.2f), ukuran_pelatihan(0.8f) {
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
    int jumlah_pelatihan = static_cast<int>(total_data * ukuran_pelatihan);
    int jumlah_test = total_data - jumlah_pelatihan;

    for (int i = 0; i < jumlah_pelatihan; i++) {
        hasil.hasil_pelatihan_x.push_back(x[i]);
        hasil.hasil_pelatihan_y.push_back(y[i]);
    }

    for (int i = jumlah_pelatihan; i < total_data; i++) {
        hasil.hasil_test_x.push_back(x[i]);
        hasil.hasil_test_y.push_back(y[i]);
    }

    return hasil;
}