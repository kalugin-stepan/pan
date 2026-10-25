#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    std::cout << "Хранение траектории ракеты" << std::endl;

    if (v0 <= 0.0) {
        std::cout << "Предупреждение: начальная скорость должна быть больше нуля." << std::endl;
        return 1;
    }

    std::vector<double> times;
    std::vector<double> heights;

    // Резервируем примерный размер, чтобы избежать перераспределений
    times.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);
    heights.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);

    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0.0) {
            break; // ракета упала
        }
        times.push_back(t);
        heights.push_back(h);
        if (t >= 1000.0) {
            break; // ограничение по времени
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "| Время t, с | Высота h, м |" << std::endl;
    std::cout << "|------------|-------------|" << std::endl;
    for (size_t i = 0; i < times.size(); ++i) {
        std::cout << "| " << std::setw(10) << times[i]
                  << " | " << std::setw(11) << heights[i] << " |" << std::endl;
    }

    return 0;
}
