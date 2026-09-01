#ifndef PRINT_VEKTOR_HPP
#define PRINT_VEKTOR_HPP

#include <vector>
#include <iostream>
#include <string>

class Print_Vektor {
private:
    std::vector<float> x;

public:
    Print_Vektor();

    void Mencetak_Hasil_Output(
        std::vector<float>& x
    );

    void Mencetak_Hasil_Output_Sama_Dengan();
};

#endif
