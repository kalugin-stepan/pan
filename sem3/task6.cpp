#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main() {
    std::cout << "Удаление значений высоты ниже 10 м" << std::endl;

    std::vector<double> heights = { 45.0, 12.0, 8.0, 23.0, 5.0, 10.0, 9.5, 30.0 };

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Исходные высоты:" << std::endl;
    for (size_t i = 0; i < heights.size(); ++i) {
        std::cout << heights[i] << " ";
    }
    std::cout << std::endl;

    std::vector<double>::iterator new_end =
        std::remove_if(heights.begin(), heights.end(), [](double h) { return h < 10.0; });

    heights.erase(new_end, heights.end());

    std::cout << "После удаления значений ниже 10 м:" << std::endl;
    if (heights.empty()) {
        std::cout << "(вектор пуст)" << std::endl;
    } else {
        for (size_t i = 0; i < heights.size(); ++i) {
            std::cout << heights[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
