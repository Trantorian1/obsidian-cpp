#include "point.hpp"

Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

Point			Point::translate(const Point& p) const {
	return (Point(x + p.x, y + p.y));
}

std::ostream&	operator<<(std::ostream& os, const Point& p) {
	os << "x:" << p.x << " y:" << p.y;
	return (os);
}
