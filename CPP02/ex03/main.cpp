#include "Point.hpp"

int main() {
	Point a1(0.0f, 0.0f);
    Point b1(4.0f, 0.0f);
    Point c1(0.0f, 3.0f);
    Point p1(1.0f, 1.0f);

    std::cout << "Testing if P is inside the triangle: \n";
    bsp(a1, b1, c1, p1);

	return 0;
}
