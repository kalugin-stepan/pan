// Дополнительная задача 4. Вычисление суммарного пути ракеты
// (std::adjacent_difference + std::accumulate по модулю смещений).

#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>
#include <cmath>

int main() {
    std::cout << "Суммарный путь ракеты вдоль оси y" << std::endl;

    std::vector<double> y = { 0.0, 10.0, 25.0, 15.0, 40.0, 40.0, 30.0 };

    if (y.size() < 2) {
        std::cout << "Недостаточно данных." << std::endl;
        return 0;
    }

    // Смещения между соседними координатами
    std::vector<double> diff(y.size());
    std::adjacent_difference(y.begin(), y.end(), diff.begin());

    // Суммарный путь = сумма модулей смещений (первый элемент diff равен y[0])
    double total_path = 0.0;
    for (size_t i = 1; i < diff.size(); ++i) {
        total_path += std::fabs(diff[i]);
    }

    // Проверка через accumulate по модулю смещений
    std::vector<double> abs_diff;
    abs_diff.reserve(diff.size() - 1);
    for (size_t i = 1; i < diff.size(); ++i) {
        abs_diff.push_back(std::fabs(diff[i]));
    }
    double total_path_stl = std::accumulate(abs_diff.begin(), abs_diff.end(), 0.0);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Суммарный путь: " << total_path << " м" << std::endl;
    std::cout << "(через accumulate): " << total_path_stl << " м" << std::endl;

    return 0;
}
