#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    std::cout << "Максимальная высота ракеты" << std::endl;

    std::vector<double> times;
    std::vector<double> heights;

    times.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);
    heights.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) {
            break;
        }
        times.push_back(t);
        heights.push_back(h);
    }

    if (heights.empty()) {
        std::cout << "Данных нет: вектор высот пуст." << std::endl;
        return 0;
    }

    // Поиск индекса максимального значения
    size_t idx_max = 0;
    for (size_t i = 1; i < heights.size(); ++i) {
        if (heights[i] > heights[idx_max]) {
            idx_max = i;
        }
    }

    // Вариант с STL (возвращает первый максимум при плато)
    std::vector<double>::iterator it = std::max_element(heights.begin(), heights.end());
    size_t idx_stl = std::distance(heights.begin(), it);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Максимальная высота: " << heights[idx_max] << " м" << std::endl;
    std::cout << "Момент времени:      " << times[idx_max] << " с" << std::endl;
    std::cout << "(проверка через std::max_element: индекс " << idx_stl
              << ", высота " << heights[idx_stl] << " м)" << std::endl;

    return 0;
}
