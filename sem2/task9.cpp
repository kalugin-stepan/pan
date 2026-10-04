// Принятые допущения:
// 1) в перечне параметров второй "C_D" — это на самом деле C_L;
// 2) плотность rho и скорость V дополнительно вводятся
//    (в условии их нет);
// 3) лидер определяется по наибольшему ускорению a = (T - D) / m.

#include <iostream>
#include <iomanip>
#include <vector>

struct Aircraft {
    double mass;
    double wingArea;
    double thrust;
    double CL;
    double CD;
};

int main() {
    int N;
    double rho, V;

    std::cout << "Интерактивный расчет аэродинамических характеристик" << std::endl;
    std::cout << "Введите количество самолетов N: ";
    std::cin >> N;
    if (N < 1) {
        std::cout << "Ошибка: количество самолетов должно быть не меньше 1." << std::endl;
        return 1;
    }

    std::cout << "Введите плотность воздуха rho (кг/м3): ";
    std::cin >> rho;
    std::cout << "Введите скорость полета V (м/с): ";
    std::cin >> V;
    if (rho <= 0.0 || V <= 0.0) {
        std::cout << "Ошибка: параметры должны быть положительными." << std::endl;
        return 1;
    }

    std::vector<Aircraft> planes(N);

    for (int i = 0; i < N; ++i) {
        std::cout << std::endl << "Самолет " << i + 1 << ":" << std::endl;
        std::cout << "  масса (кг): ";
        std::cin >> planes[i].mass;
        std::cout << "  площадь крыла (м2): ";
        std::cin >> planes[i].wingArea;
        std::cout << "  тяга (Н): ";
        std::cin >> planes[i].thrust;
        std::cout << "  коэффициент подъемной силы CL: ";
        std::cin >> planes[i].CL;
        std::cout << "  коэффициент сопротивления CD: ";
        std::cin >> planes[i].CD;
    }

    std::vector<double> L(N), D(N), a(N);
    int leader = 0;

    for (int i = 0; i < N; ++i) {
        L[i] = 0.5 * rho * V * V * planes[i].wingArea * planes[i].CL;
        D[i] = 0.5 * rho * V * V * planes[i].wingArea * planes[i].CD;
        a[i] = (planes[i].thrust - D[i]) / planes[i].mass;

        if (a[i] > a[leader]) {
            leader = i;
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "| Самолет | Подъемная сила, Н | Сопротивление, Н | Ускорение, м/с2 |" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << "| " << std::setw(7) << i + 1
                  << " | " << std::setw(17) << L[i]
                  << " | " << std::setw(16) << D[i]
                  << " | " << std::setw(15) << a[i] << " |" << std::endl;
    }

    std::cout << std::endl << "Наибольшее ускорение имеет самолет " << leader + 1
              << ": a = " << a[leader] << " м/с2" << std::endl;
    return 0;
}