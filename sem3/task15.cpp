// Дополнительная задача 5. Сортировка и удаление дубликатов траекторий
// (std::sort + std::unique).

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Сортировка и удаление дубликатов координат x" << std::endl;

    std::vector<double> x = { 12.0, 5.0, 12.0, 7.0, 5.0, 3.0, 9.0, 12.0, 3.0 };

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Исходный вектор:" << std::endl;
    for (size_t i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    std::sort(x.begin(), x.end());

    std::vector<double>::iterator new_end = std::unique(x.begin(), x.end());
    x.erase(new_end, x.end());

    std::cout << "Итоговый вектор (отсортирован, без дубликатов):" << std::endl;
    for (size_t i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
