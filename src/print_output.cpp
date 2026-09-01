#include "print_output.hpp"

Print_Vektor::Print_Vektor()
    : x()
{
}

void Print_Vektor::Mencetak_Hasil_Output(
    std::vector<float>& x
) {
    for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << " ";
    }

    std::cout << std::endl;
}

void Print_Vektor::Mencetak_Hasil_Output_Sama_Dengan()
{
    for (int i = 0; i < 30; i++) {
        std::cout << "=";
    }

    std::cout << std::endl;
}
