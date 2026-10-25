// Принятые допущения:
// 1) если ракета не упала в пределах таблицы (нет h <= 0),
//    считаем, что она всё ещё в воздухе (время падения — «—»);
// 2) при одинаковой максимальной высоте выводится, что высоты равны.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>

const double dt = 1.0;

// Заполняет times и heights по формуле h = v0*t - 0.5*g*t^2 до падения
void buildTrajectory(double v0, std::vector<double>& times, std::vector<double>& heights) {
    const double g = 9.8;
    for (double t = 0.0; ; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        times.push_back(t);
        heights.push_back(h);
        if (h < 0.0) {
            break; // включаем первый отрицательный отсчет
        }
    }
}

int main() {
    const double INF = std::numeric_limits<double>::infinity();

    std::cout << "Сравнение траекторий двух ракет" << std::endl;

    std::vector<double> times1, heights1;
    std::vector<double> times2, heights2;

    buildTrajectory(50.0, times1, heights1);
    buildTrajectory(60.0, times2, heights2);

    // Ракета 1
    double max1 = *std::max_element(heights1.begin(), heights1.end());
    size_t idx_max1 = std::distance(heights1.begin(),
        std::max_element(heights1.begin(), heights1.end()));
    double t_max1 = times1[idx_max1];

    // Ищем момент падения после старта (пропускаем t = 0)
    std::vector<double>::iterator it1 =
        std::find_if(heights1.begin() + 1, heights1.end(), [](double h) { return h <= 0.0; });
    double t_fall1 = (it1 != heights1.end()) ? times1[std::distance(heights1.begin(), it1)] : INF;

    // Ракета 2
    double max2 = *std::max_element(heights2.begin(), heights2.end());
    size_t idx_max2 = std::distance(heights2.begin(),
        std::max_element(heights2.begin(), heights2.end()));
    double t_max2 = times2[idx_max2];

    std::vector<double>::iterator it2 =
        std::find_if(heights2.begin() + 1, heights2.end(), [](double h) { return h <= 0.0; });
    double t_fall2 = (it2 != heights2.end()) ? times2[std::distance(heights2.begin(), it2)] : INF;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "| Ракета | Макс. высота, м | Время макс., с | Время падения, с |" << std::endl;
    std::cout << "|--------|-----------------|----------------|------------------|" << std::endl;

    std::cout << "|      1 | " << std::setw(15) << max1
              << " | " << std::setw(14) << t_max1
              << " | " << std::setw(16);
    if (t_fall1 == INF) {
        std::cout << "—";
    } else {
        std::cout << t_fall1;
    }
    std::cout << " |" << std::endl;

    std::cout << "|      2 | " << std::setw(15) << max2
              << " | " << std::setw(14) << t_max2
              << " | " << std::setw(16);
    if (t_fall2 == INF) {
        std::cout << "—";
    } else {
        std::cout << t_fall2;
    }
    std::cout << " |" << std::endl;

    std::cout << std::endl;
    if (max1 > max2) {
        std::cout << "Ракета 1 поднялась выше." << std::endl;
    } else if (max2 > max1) {
        std::cout << "Ракета 2 поднялась выше." << std::endl;
    } else {
        std::cout << "Ракеты поднялись на одинаковую высоту." << std::endl;
    }

    if (t_fall1 == INF && t_fall2 == INF) {
        std::cout << "Обе ракеты всё ещё в воздухе." << std::endl;
    } else if (t_fall1 == INF) {
        std::cout << "Ракета 1 дольше находится в воздухе (ещё не упала)." << std::endl;
    } else if (t_fall2 == INF) {
        std::cout << "Ракета 2 дольше находится в воздухе (ещё не упала)." << std::endl;
    } else if (t_fall1 > t_fall2) {
        std::cout << "Ракета 1 дольше находилась в воздухе." << std::endl;
    } else if (t_fall2 > t_fall1) {
        std::cout << "Ракета 2 дольше находилась в воздухе." << std::endl;
    } else {
        std::cout << "Ракеты находились в воздухе одинаковое время." << std::endl;
    }

    return 0;
}
