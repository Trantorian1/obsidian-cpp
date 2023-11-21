#include "point.hpp"
#include <iostream>

int	main(void) {
	Point p1 = Point();
	Point p2 = Point(3, -1);
	Point p3 = p1.translate(p2);

	std::cout << p3 << std::endl;
}
