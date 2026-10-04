#include <iostream>

int main() {
    double S, V, rho, CL;

    std::cout << "Расчет подъемной силы" << std::endl;
    std::cout << "Введите площадь крыла S (м2): ";
    std::cin >> S;
    std::cout << "Введите скорость полета V (м/с): ";
    std::cin >> V;
    std::cout << "Введите плотность воздуха rho (кг/м3): ";
    std::cin >> rho;
    std::cout << "Введите коэффициент подъемной силы CL: ";
    std::cin >> CL;

    if (S <= 0.0 || V <= 0.0 || rho <= 0.0 || CL <= 0.0) {
        std::cout << "Ошибка: параметры должны быть положительными числами." << std::endl;
        return 1;
    }

    double L = 0.5 * rho * V * V * S * CL;

    std::cout << "Подъемная сила L = " << L << " Н" << std::endl;
    return 0;
}