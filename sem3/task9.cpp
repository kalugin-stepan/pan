// Принятые допущения:
// 1) границы (первый и последний элемент) сглаживаются средним
//    из двух соседних значений;
// 2) внутренние элементы — среднее из трёх соседних.

#include <iostream>
#include <iomanip>
#include <vector>

int main() {
    std::cout << "Сглаживание траектории (скользящее среднее)" << std::endl;

    // Измеренная высота с шумом
    std::vector<double> h = { 10.0, 12.0, 11.5, 13.0, 12.8, 40.0, 13.2, 12.7, 13.1, 12.9 };

    size_t n = h.size();
    std::vector<double> smoothed(n);

    if (n == 0) {
        std::cout << "Данных нет." << std::endl;
        return 0;
    }

    // Границы
    if (n == 1) {
        smoothed[0] = h[0];
    } else {
        smoothed[0] = (h[0] + h[1]) / 2.0;
        smoothed[n - 1] = (h[n - 2] + h[n - 1]) / 2.0;
    }

    // Основной цикл: среднее из трёх соседних
    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "| Индекс | Исходная h, м | Сглаженная h, м |" << std::endl;
    std::cout << "|--------|---------------|-----------------|" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << "| " << std::setw(6) << i
                  << " | " << std::setw(13) << h[i]
                  << " | " << std::setw(15) << smoothed[i] << " |" << std::endl;
    }

    return 0;
}
