#include <cmath>
#include <iostream>
#include <memory>

class Point {
public:
    Point(double i, double j) : x{i}, y{j} { }
    double getLength() { return std::pow(x*x+y*y, 0.5); }
private:
    double x, y;
};

void f_r(Point *r_p) {
    // do sth
}

void f_s(std::shared_ptr<Point> s_p) { 
    // do sth
}

void f_w(std::weak_ptr<Point> w_p) { 
    // do sth
}

void f_u(std::unique_ptr<Point> u_p) { 
    // do sth
}


int main() {
    auto r_p = new Point(3, 4);
    auto s_p = std::make_shared<Point>(3, 4);
    auto w_p = std::weak_ptr<Point>(s_p);
    auto u_p = std::make_unique<Point>(3, 4);

    std::cout << r_p->getLength() << "\n";
    std::cout << s_p->getLength() << "\n";
    std::shared_ptr<Point> lockedPointer = w_p.lock();
    std::cout << lockedPointer->getLength() << "\n";
    std::cout << u_p->getLength() << "\n";

    auto s_p_copy = s_p;
    // auto u_p_copy = u_p;
    auto w_p_copy = w_p;

    auto s_p_copyconstruct = std::shared_ptr<Point>(s_p);
    // auto u_p_copyconstruct = std::unique_ptr<Point>(u_p);
    auto w_p_copyconstruct = std::weak_ptr<Point>(w_p);

    f_r(r_p);
    f_s(s_p);
    f_w(w_p);
    f_u(u_p); 
}

