#include <iostream>
#include <cmath>

int main() {
    double h = 0.0;
    double ay = 0.0;

    std::cout << "Расчет времени набора высоты" << std::endl;

    while (h <= 0.0) {
        std::cout << "Введите заданную высоту h (м): ";
        std::cin >> h;
        if (h <= 0.0) {
            std::cout << "Ошибка: высота должна быть больше нуля. Повторите ввод." << std::endl;
        }
    }

    while (ay <= 0.0) {
        std::cout << "Введите вертикальное ускорение ay (м/с2): ";
        std::cin >> ay;
        if (ay <= 0.0) {
            std::cout << "Ошибка: ускорение должно быть больше нуля. Повторите ввод." << std::endl;
        }
    }

    double t = std::sqrt(2.0 * h / ay);

    std::cout << "Время набора высоты: t = " << t << " с" << std::endl;
    return 0;
}