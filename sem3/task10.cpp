// Принятые допущения:
// 1) класс Rocket описывает движение по одной оси (высоте) под
//    действием постоянного ускорения (например, силы тяжести);
// 2) конструктор принимает (масса, x, y, v0) — пример из условия;
//    здесь используются x, y, z как координаты и v0 как начальная
//    вертикальная скорость;
// 3) симуляция длится T = 10 с с шагом dt = 0.5 с.

#include <iostream>
#include <iomanip>
#include <vector>

struct Point {
    double x;
    double y;
    double z;
};

class Rocket {
public:
    Rocket(double mass, double x, double y, double v0)
        : m_mass(mass), m_x(x), m_y(y), m_z(0.0), m_v(v0) {}

    void updatePosition(double dt) {
        m_y += m_v * dt;   // вертикальное перемещение
        m_x += 5.0 * dt;   // горизонтальная скорость принята постоянной
        m_z += 0.0;
    }

    void changeVelocity(double dv) {
        m_v += dv;
    }

    Point getPosition() const {
        return Point{ m_x, m_y, m_z };
    }

    double getVelocity() const {
        return m_v;
    }

private:
    double m_mass;
    double m_x;
    double m_y;
    double m_z;
    double m_v;
};

int main() {
    const double dt = 0.5;
    const double T = 10.0;
    const double g = 9.8;

    std::cout << "Моделирование отряда ракет" << std::endl;

    std::vector<Rocket> squad;
    squad.reserve(5);

    squad.emplace_back(1000.0, 10.0, 0.0, 50.0);
    squad.emplace_back(900.0, 15.0, -5.0, 40.0);
    squad.emplace_back(1100.0, 20.0, 0.0, 60.0);
    squad.emplace_back(950.0, 5.0, 2.0, 35.0);
    squad.emplace_back(1050.0, 12.0, -2.0, 45.0);

    std::vector<std::vector<Point>> trajectories(squad.size());

    for (double t = 0.0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); ++i) {
            trajectories[i].push_back(squad[i].getPosition());
            squad[i].updatePosition(dt);
            squad[i].changeVelocity(-g * dt); // влияние силы тяжести
        }
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl << "Конечные положения ракет:" << std::endl;
    std::cout << "| Ракета |    x, м |    y, м |    z, м | Точки траектории |" << std::endl;
    std::cout << "|--------|---------|---------|---------|-------------------|" << std::endl;

    for (size_t i = 0; i < squad.size(); ++i) {
        Point p = squad[i].getPosition();
        std::cout << "| " << std::setw(6) << i + 1
                  << " | " << std::setw(7) << p.x
                  << " | " << std::setw(7) << p.y
                  << " | " << std::setw(7) << p.z
                  << " | " << std::setw(17) << trajectories[i].size() << " |" << std::endl;
    }

    return 0;
}
