// Принятые допущения:
// 1) ракета движется без ускорения (равномерно) с начальными
//    скоростями vx = 30, vy = 20, vz = 40 м/с;
// 2) шаг времени dt = 1.0 с, длительность t_max = 5.0 с;
// 3) координаты вычисляются как x = vx*t, y = vy*t, z = vz*t.

#include <iostream>
#include <iomanip>
#include <vector>

struct Point {
    double x;
    double y;
    double z;
};

int main() {
    const double vx = 30.0;
    const double vy = 20.0;
    const double vz = 40.0;
    const double dt = 1.0;
    const double t_max = 5.0;

    std::cout << "Траектория ракеты в 3D" << std::endl;

    std::vector<Point> traj;
    traj.reserve(static_cast<int>(t_max / dt) + 1);

    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    for (double t = 0.0; t <= t_max; t += dt) {
        x = vx * t;
        y = vy * t;
        z = vz * t;
        traj.push_back({ x, y, z });
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "| Время t, с |   x, м |   y, м |   z, м |" << std::endl;
    std::cout << "|------------|--------|--------|--------|" << std::endl;

    double t = 0.0;
    for (size_t i = 0; i < traj.size(); ++i, t += dt) {
        std::cout << "| " << std::setw(10) << t
                  << " | " << std::setw(6) << traj[i].x
                  << " | " << std::setw(6) << traj[i].y
                  << " | " << std::setw(6) << traj[i].z << " |" << std::endl;
    }

    return 0;
}
