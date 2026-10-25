// Дополнительная задача 2. Подсчет «нулевых» измерений датчика
// (использование std::count).

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Подсчет нулевых показаний датчика ускорения" << std::endl;

    std::vector<double> sensor = { 0.0, 1.2, 0.0, 3.4, 0.0, 0.0, 5.6, -0.8, 0.0 };

    long long zeros = std::count(sensor.begin(), sensor.end(), 0.0);

    std::cout << "Всего измерений: " << sensor.size() << std::endl;
    std::cout << "Нулевых показаний: " << zeros << std::endl;

    return 0;
}
