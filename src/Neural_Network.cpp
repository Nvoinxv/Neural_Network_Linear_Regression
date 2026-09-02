#include "Neural_Network.hpp"

latihan_deeplearning::latihan_deeplearning():
Linear(), Mean_Squared_Error(), 
Optimisasi_Adam(), y_actual(),
y_pred(), x(), y(), b(0.0f),
x_grad(), w_grad(), y_grad(),
b_grad(0.0f), epsilon(1e-8f), alpha(0.0001f), g_t(),
g_t2, beta_1(0.9f), beta_2(0.999f), m, v {
    // Kosong
}

void latihan_deeplearning::forward_model() {
    std::cout << "Memulai Program dari Forward" << std::endl;
    Linear.forward_layer(x, y);
    Mean_Squared_Error.forward(y_actual, y_pred);
}

void latihan_deeplearning::backward_model() {
    std::cout << "Selanjutnya Memulai Backward" << std::endl;
    Linear.backward_layer(x, y);
    Mean_Squared_Error.backward(y_actual, y_pred);

    // Lalu menyimpan setiap perhitungan backward ke dalam variabel
    w = Linear.mendapatkan_w_grad();
    b = Linear.mendapatkan_b_grad();

    y_actual = Mean_Squared_Error.mendapatkan_y_actual_grad();
    y_pred = Mean_Squared_Error.mendapatkan_y_pred_grad();
}

void latihan_deeplearning::pelatihan_model() {
    std::cout << "Memulai pelatihan model AI" << std::endl;

    int epoch = 20;
    for (int i = 0; i < epoch; i++) {
        forward_model();
        backward_model();

        optimizer.update(w_grad, b_grad);
        
        std::cout << "Epoch ke " << epoch[i] << std::endl;
        std::cout << "Loss: " << mse.forward(y_actual, y_pred) << std::endl;
    }

    std::cout << "Pelatihan Model AI berakhir!" << std::endl;
}

void latihan_deeplearning::pembersihan_memori() {
    y_actual.clear();
    y_pred.clear();
    x_grad.clear();
    w_grad.clear();
    y_grad.clear();
    m.clear();
    v.clear()
}