// Принятые допущения:
// 1) в перечне параметров второй "C_D" — это на самом деле C_L;
// 2) плотность rho и скорость V дополнительно вводятся с клавиатуры
//    (в условии они не заданы);
// 3) время набора высоты t = sqrt(2*h/ay), ay = (L - m*g)/m;
//    самолеты с ay <= 0 набрать высоту не могут (в таблице "—").

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

const double g = 9.81;

struct Aircraft {
    const char* name;
    double mass;
    double wingArea;
    double thrust;
    double CL;
    double CD;
};

int main() {
    const int N = 3;
    Aircraft planes[N] = {
        {"Самолет A", 3000.0, 30.0, 20000.0, 0.35, 0.030},
        {"Самолет B", 5000.0, 40.0, 35000.0, 0.50, 0.040},
        {"Самолет C", 4000.0, 45.0, 25000.0, 0.45, 0.035}
    };

    double rho, V, h;

    std::cout << "Сравнение конфигураций ЛА" << std::endl;
    std::cout << "Введите плотность воздуха rho (кг/м3): ";
    std::cin >> rho;
    std::cout << "Введите скорость полета V (м/с): ";
    std::cin >> V;
    std::cout << "Введите заданную высоту h (м): ";
    std::cin >> h;

    if (rho <= 0.0 || V <= 0.0 || h <= 0.0) {
        std::cout << "Ошибка: параметры должны быть положительными." << std::endl;
        return 1;
    }

    const double INF = std::numeric_limits<double>::infinity();

    double L[N], D[N], a[N], ay[N], t[N];
    int best = 0;

    for (int i = 0; i < N; ++i) {
        L[i] = 0.5 * rho * V * V * planes[i].wingArea * planes[i].CL;
        D[i] = 0.5 * rho * V * V * planes[i].wingArea * planes[i].CD;
        a[i] = (planes[i].thrust - D[i]) / planes[i].mass;
        ay[i] = (L[i] - planes[i].mass * g) / planes[i].mass;
        t[i] = (ay[i] > 0.0) ? std::sqrt(2.0 * h / ay[i]) : INF;

        if (t[i] < t[best]) {
            best = i;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "|    ЛА     | Подъемная сила L, Н | Сопротивление D, Н | Ускорение a, м/с2 | Ускорение ay, м/с2 | Время набора, с |" << std::endl;

    for (int i = 0; i < N; ++i) {
        std::cout << "| " << std::setw(9) << planes[i].name
                  << " | " << std::setw(18) << L[i]
                  << " | " << std::setw(18) << D[i]
                  << " | " << std::setw(17) << a[i]
                  << " | " << std::setw(18) << ay[i]
                  << " | " << std::setw(15);
        if (t[i] == INF) {
            std::cout << "—";
        } else {
            std::cout << t[i];
        }
        std::cout << " |" << std::endl;
    }

    if (t[best] == INF) {
        std::cout << std::endl << "Ни один самолет не может набрать высоту (ay <= 0)." << std::endl;
    } else {
        std::cout << std::endl << "Быстрее всех наберет высоту: "
                  << planes[best].name << " за " << t[best] << " с" << std::endl;
    }
    return 0;
}