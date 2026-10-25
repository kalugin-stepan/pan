#include <iostream>
#include <iomanip>
#include <vector>
#include <numeric>

int main() {
    const double v0 = 50.0;
    const double g = 9.8;
    const double dt = 1.0;

    std::cout << "Средняя скорость ракеты за полёт" << std::endl;

    std::vector<double> velocities;

    velocities.reserve(static_cast<int>(v0 * 2.0 / g / dt) + 1);

    double t_max = 2.0 * v0 / g;
    for (double t = 0.0; t <= t_max; t += dt) {
        velocities.push_back(v0 - g * t);
    }

    if (velocities.empty()) {
        std::cout << "Данных нет: вектор скоростей пуст." << std::endl;
        return 0;
    }

    double sum = std::accumulate(velocities.begin(), velocities.end(), 0.0);
    double avg = sum / velocities.size();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Средняя (арифметическая) скорость: " << avg << " м/с" << std::endl;

    // Вариант: интегральное среднее за весь полёт
    // avg = (1/T) * integral v(t) dt, v(t) = v0 - g*t
    double T = t_max;
    double avg_integral = (v0 * T - 0.5 * g * T * T) / T;

    std::cout << "Средняя (интегральная) скорость:  " << avg_integral << " м/с" << std::endl;

    return 0;
}
