// Считать, что формула с коэффициентом C_D описывает сопротивление D
// (в условии она ошибочно подписана как "L =").

#include <iostream>

double dragForce(double rho, double V, double S, double CD) {
    return 0.5 * rho * V * V * S * CD;
}

int main() {
    double rho, V, S, CD;

    std::cout << "Расчет аэродинамического сопротивления" << std::endl;
    std::cout << "Введите плотность воздуха rho (кг/м3): ";
    std::cin >> rho;
    std::cout << "Введите скорость полета V (м/с): ";
    std::cin >> V;
    std::cout << "Введите площадь крыла S (м2): ";
    std::cin >> S;
    std::cout << "Введите коэффициент сопротивления CD: ";
    std::cin >> CD;

    if (rho <= 0.0 || V <= 0.0 || S <= 0.0 || CD <= 0.0) {
        std::cout << "Ошибка: параметры должны быть положительными числами." << std::endl;
        return 1;
    }

    double D = dragForce(rho, V, S, CD);

    std::cout << "Сила аэродинамического сопротивления D = " << D << " Н" << std::endl;
    return 0;
}