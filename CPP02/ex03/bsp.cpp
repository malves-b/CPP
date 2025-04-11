#include "./Point.hpp"

float area(const Point &a, const Point &b, const Point &c) {
    float a1, b1, c1;

    a1 = a.getX().toFloat() * b.getY().toFloat();
    b1 = b.getX().toFloat() * c.getY().toFloat();
    c1 = c.getX().toFloat() * a.getY().toFloat();

    float area1 = a1 + b1 + c1;

    a1 = a.getX().toFloat() * c.getY().toFloat();
    b1 = b.getX().toFloat() * a.getY().toFloat();
    c1 = c.getX().toFloat() * b.getY().toFloat();

    float area = 0.5f * std::abs(area1 - (a1 + b1 + c1));

    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float totalArea = area(a, b, c);
	std::cout << "Triangle area: " << totalArea << std::endl;

    float area1 = area(point, b, c);
	std::cout << "T1 area: " << area1 << std::endl;
	
    float area2 = area(a, point, c);
	std::cout << "T2 area: " << area2 << std::endl;
    
	float area3 = area(a, b, point);
	std::cout << "T3 area: " << area3 << std::endl;

	if (totalArea == (area1 + area2 + area3)){
		std::cout << "The point is inside the triangle! " << std::endl;
		return true;
	}
	std::cout << "The point is NOT inside the triangle! " << std::endl;
    return false;
}
