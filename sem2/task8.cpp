// Принятые допущения:
// 1) плотность rho, скорость V и площадь крыла S заданы общими
//    константами (в структуре Aircraft их нет);
// 2) тяга не влияет на вертикальное ускорение ay = (L - m*g)/m,
//    поэтому выводится только дополнительная колонка a = (T - D)/m;
// 3) при ay <= 0 набрать высоту невозможно, время выводится как «—».

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>

const double g = 9.81;
const double rho = 1.225;
const double V = 70.0;
const double S = 30.0;

struct Aircraft {
    std::string name;
    double mass;
    double thrust;
    double CL;
    double CD;
};

struct Result {
    std::string name;
    double a;
    double ay;
    double t;
};

int main() {
    const int N = 4;
    Aircraft planes[N] = {
        {"Л-1", 3000.0, 20000.0, 0.35, 0.03},
        {"Л-2", 5000.0, 35000.0, 0.50, 0.04},
        {"Л-3", 4000.0, 25000.0, 0.80, 0.03},
        {"Л-4", 6500.0, 30000.0, 0.60, 0.05}
    };

    double h;
    std::cout << "Расчет времени набора высоты" << std::endl;
    std::cout << "Введите заданную высоту h (м): ";
    std::cin >> h;
    if (h <= 0.0) {
        std::cout << "Ошибка: высота должна быть больше нуля." << std::endl;
        return 1;
    }

    const double INF = std::numeric_limits<double>::infinity();

    Result results[N];
    for (int i = 0; i < N; ++i) {
        double L = 0.5 * rho * V * V * S * planes[i].CL;
        double D = 0.5 * rho * V * V * S * planes[i].CD;

        results[i].name = planes[i].name;
        results[i].a = (planes[i].thrust - D) / planes[i].mass;
        results[i].ay = (L - planes[i].mass * g) / planes[i].mass;
        results[i].t = (results[i].ay > 0.0) ? std::sqrt(2.0 * h / results[i].ay) : INF;
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (results[j].t > results[j + 1].t) {
                Result tmp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = tmp;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "Результаты (отсортированы по времени набора высоты):" << std::endl;
    std::cout << "|  ЛА  | Ускорение a, м/с2 | Вертикальное ускорение ay, м/с2 | Время набора, с |" << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << "| " << std::setw(4) << results[i].name
                  << " | " << std::setw(17) << results[i].a
                  << " | " << std::setw(35) << results[i].ay
                  << " | " << std::setw(15);
        if (results[i].t == INF) {
            std::cout << "—";
        } else {
            std::cout << results[i].t;
        }
        std::cout << " |" << std::endl;
    }

    return 0;
}