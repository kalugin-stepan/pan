#include <iostream>

int main() {
    const double g = 9.81;

    double m, T, L, D;

    std::cout << "Определение ускорения ЛА" << std::endl;
    std::cout << "Введите массу ЛА m (кг): ";
    std::cin >> m;
    std::cout << "Введите тягу двигателя T (Н): ";
    std::cin >> T;
    std::cout << "Введите подъемную силу L (Н): ";
    std::cin >> L;
    std::cout << "Введите силу сопротивления D (Н): ";
    std::cin >> D;

    if (m <= 0.0) {
        std::cout << "Ошибка: масса должна быть положительной." << std::endl;
        return 1;
    }

    double a = (T - D) / m;
    double ay = (L - m * g) / m;

    std::cout << "Ускорение по направлению движения: a = " << a << " м/с2" << std::endl;
    std::cout << "Вертикальное ускорение:            ay = " << ay << " м/с2" << std::endl;
    return 0;
}