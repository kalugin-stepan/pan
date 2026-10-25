// Дополнительная задача 3. Очистка данных от шумов
// (использование std::remove_if для удаления значений < -100 или > 200).

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Очистка показаний температуры двигателя" << std::endl;

    std::vector<double> temp = { 120.0, -150.0, 80.0, 250.0, 60.0, -50.0, 300.0, 150.0, 40.0 };

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Исходные показания:" << std::endl;
    for (size_t i = 0; i < temp.size(); ++i) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;

    std::vector<double>::iterator new_end =
        std::remove_if(temp.begin(), temp.end(),
            [](double t) { return t < -100.0 || t > 200.0; });

    temp.erase(new_end, temp.end());

    std::cout << "Очищенные показания:" << std::endl;
    for (size_t i = 0; i < temp.size(); ++i) {
        std::cout << temp[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
