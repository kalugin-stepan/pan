#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    std::cout << "Нахождение момента падения ракеты" << std::endl;

    std::vector<double> times;
    std::vector<double> heights;

    times.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);
    heights.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (h < 0.0) {
            break; // включаем первый отрицательный отсчет (момент пересечения нуля)
        }
    }

    // Ищем момент падения после старта (пропускаем t = 0,
    // где высота равна 0 — это точка запуска, а не падение)
    std::vector<double>::iterator it =
        std::find_if(heights.begin() + 1, heights.end(), [](double h) { return h <= 0.0; });

    if (it == heights.end()) {
        std::cout << "Падения не было в рассматриваемом диапазоне времени." << std::endl;
    } else {
        size_t idx = std::distance(heights.begin(), it);
        double t_fall = times[idx];

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Момент падения: t = " << t_fall << " с" << std::endl;
        std::cout << "Высота в этот момент: " << heights[idx] << " м" << std::endl;
    }

    return 0;
}
