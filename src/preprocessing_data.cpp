#include "preprocessing_data.hpp"

preprocessing::preprocessing() : x(), u(0.0f),
s(0.0f), Q1(), Q3(), printer() {
    // Kosong
}

float preprocessing::median(
    std::vector<float>& x
) {
    if (x.empty()) {
        return 0.0f;
    }

    std::vector<float> sorted_x = x;
    std::sort(sorted_x.begin(), sorted_x.end());

    float hasil;

    if (sorted_x.size() % 2 == 0) {
        int tengah = sorted_x.size() / 2;

        hasil = (sorted_x[tengah - 1] + sorted_x[tengah]) / 2.0f;
    } 
    else {
        int tengah = sorted_x.size() / 2;

        hasil = sorted_x[tengah];
    }

    return hasil;
}

void preprocessing::penghapusan_outlier(
    std::vector<float>& x
) {
    std::cout << "Sebelum melakukan penghapusan outlier: " << x.size() << std::endl;

    float perhitungan_median = median(x);

    std::vector<float> bagian_bawah;
    std::vector<float> bagian_atas;

    int tengah = x.size() / 2;

    for (int i = 0; i < tengah; i++) {
        bagian_bawah.push_back(x[i]);
    }

    for (int i = tengah + 1; i < x.size(); i++) {
        bagian_atas.push_back(x[i]);
    }

    float Q1 = median(bagian_bawah);
    float Q3 = median(bagian_atas);

    float IQR = Q3 - Q1;

    float bagian_bawah_outlier = Q1 - (1.5f * IQR);
    float bagian_atas_outlier = Q3 + (1.5f * IQR);

    x.erase(
        std::remove_if(
            x.begin(),
            x.end(),
            [&](float nilai) {
                return nilai < bagian_bawah_outlier ||
                       nilai > bagian_atas_outlier;
            }
        ),
        x.end()
    );

    std::cout << "Hasil Preprocessing Penghapusan Outlier: " << x.size() << std::endl;
}


void preprocessing::standard_scaler(
    std::vector<float>& x
) {
    // hitung mean
    u = 0.0f;

    for (int i = 0; i < x.size(); i++) {
        u += x[i];
    }

    u = u / x.size();


    // hitung standard deviation
    s = 0.0f;

    for (int i = 0; i < x.size(); i++) {
        s += std::pow(x[i] - u, 2.0f);
    }

    s = std::sqrt(s / x.size());


    // standard scaling
    for (int i = 0; i < x.size(); i++) {
        x[i] = (x[i] - u) / s;
    }
    
    std::cout << "HASIL PREPROCESSING SKALAR STANDARISASI.\n";
    printer.Mencetak_Hasil_Output(x);
}
