// Дополнительная задача 1. Нахождение максимальной высоты ракеты
// (использование std::max_element).

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    std::cout << "Максимальная высота ракеты (std::max_element)" << std::endl;

    std::vector<double> heights;

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) {
            break;
        }
        heights.push_back(h);
    }

    if (heights.empty()) {
        std::cout << "Данных нет." << std::endl;
        return 0;
    }

    std::vector<double>::iterator it = std::max_element(heights.begin(), heights.end());
    size_t idx = std::distance(heights.begin(), it);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Максимальная высота: " << *it << " м" << std::endl;
    std::cout << "Достигнута в момент: " << idx * dt << " с" << std::endl;

    return 0;
}
