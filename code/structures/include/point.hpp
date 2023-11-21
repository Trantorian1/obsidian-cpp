#include <iostream>
#include <ostream>

struct Point {
	int	x;
	int	y;

	Point(int xVal = 0, int yVal = 0);

	Point	translate(const Point& p) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
