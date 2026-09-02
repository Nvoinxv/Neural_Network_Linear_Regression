#include "Neural_Network.hpp"

latihan_deeplearning::latihan_deeplearning():
    linear(),
    mse(),
    optimizer(),
    printer(),
    y_actual(),
    y_pred(),
    x(),
    y(),
    w(0.0f),
    b(0.0f),
    w_grad(0.0f),
    b_grad(0.0f)
{
    // Kosong
}

void latihan_deeplearning::forward_model(const std::vector<float>& x,
                                        const std::vector<float>& y) {
    this->x = x;
    this->y_actual = y;
    this->y_pred = linear.forward_layer(x);
}

void latihan_deeplearning::backward_model(const std::vector<float>& x,
                                         const std::vector<float>& y) {
    linear.backward_layer(x, y, y_pred);
    mse.backward(y, y_pred);

    // Lalu menyimpan setiap perhitungan backward ke dalam variabel
    w_grad = linear.mendapatkan_w_grad();
    b_grad = linear.mendapatkan_b_grad();
}

void latihan_deeplearning::pelatihan_model(const std::vector<float>& x_train,
                                         const std::vector<float>& y_train,
                                         int epoch) {
    std::cout << "Memulai pelatihan model AI" << std::endl;

    for (int i = 0; i < epoch; i++) {
        forward_model(x_train, y_train);
        backward_model(x_train, y_train);

        float w_sekarang = linear.mendapatkan_w();
        float b_sekarang = linear.mendapatkan_b();

        optimizer.update(w_sekarang, b_sekarang, w_grad, b_grad);
        linear.perbarui_bobot_bias(w_sekarang, b_sekarang);

        float loss_sekarang = mse.forward(y_train, y_pred);

        if ((i + 1) % 10 == 0 || i == 0 || i == epoch - 1) {
            std::cout << "Epoch ke-" << (i + 1) 
                      << " | Loss: " << loss_sekarang 
                      << " | Bobot (w): " << w_sekarang 
                      << " | Bias (b): " << b_sekarang << std::endl;
        }
    }

    std::cout << "Pelatihan Model AI berakhir!" << std::endl;
}

void latihan_deeplearning::evaluasi_model(const std::vector<float>& x_test,
                                        const std::vector<float>& y_test) {
    printer.Mencetak_Hasil_Output_Sama_Dengan();
    std::cout << "HASIL EVALUASI MODEL PADA DATA TEST:" << std::endl;
    
    std::vector<float> y_test_pred = linear.forward_layer(x_test);
    float test_loss = mse.forward(y_test, y_test_pred);
    std::cout << "Total Test Loss (MSE): " << test_loss << std::endl;

    int sample_komperasi_target_dan_aktual = 5;
    float hasil_persenan_kompreasi = 0.0f;

    for (int j = 0; j < sample_komperasi_target_dan_aktual && j < static_cast<int>(y_test_pred.size()) && j < static_cast<int>(y_test.size()); j++) {
        std::cout << "Data ke-" << (j + 1) 
                  << " | Input (X): " << x_test[j]
                  << " | Prediksi: " << y_test_pred[j] 
                  << " | Actual: " << y_test[j] << std::endl;

        if (y_test[j] != 0.0f) {
            hasil_persenan_kompreasi = (y_test_pred[j] / y_test[j]) * 100.0f;
        } else {
            hasil_persenan_kompreasi = 0.0f;
        }
        std::cout << "Hasil rasio persentase prediksi dan aktual: " << hasil_persenan_kompreasi << "%" << std::endl;
    }
    printer.Mencetak_Hasil_Output_Sama_Dengan();
}

void latihan_deeplearning::pembersihan_memori() {
    y_actual.clear();
    y_pred.clear();
    x.clear();
    y.clear();
    std::cout << "Pembersihan memori selesai." << std::endl;
}