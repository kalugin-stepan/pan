#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    std::cout << "Вектор скоростей ракеты" << std::endl;

    // Момент, когда скорость меняет знак (вершина траектории)
    double t_top = v0 / g;

    std::vector<double> times;
    std::vector<double> velocities;

    times.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);
    velocities.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);

    // Цикл до момента падения (примерно 2*t_top)
    double t_max = 2.0 * t_top;
    for (double t = 0.0; t <= t_max; t += dt) {
        double v = v0 - g * t;
        times.push_back(t);
        velocities.push_back(v);
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "| Время t, с | Скорость v, м/с |" << std::endl;
    std::cout << "|------------|-----------------|" << std::endl;
    for (size_t i = 0; i < times.size(); ++i) {
        std::cout << "| " << std::setw(10) << times[i]
                  << " | " << std::setw(15) << velocities[i] << " |" << std::endl;
    }

    std::cout << std::endl << "Скорость меняет знак в момент t = " << t_top << " с" << std::endl;

    return 0;
}
