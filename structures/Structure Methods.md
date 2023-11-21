*point.hpp:* (declarations)
```cpp
struct Point {
	int x;
	int y;

	Point(int xVal = 0, int yVal = 0);
	Point    translate(const Point& p) const;
};
```

*Point.cpp:* (definitions)
```cpp
#include "point.hpp"

Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

Point    Point::translate(const Point& p) const {
	return { .x = x + p.x, .y = y + p.y };
}
```

*main.cpp*
```cpp
#include "point.hpp"

int    main(void) {
	Point p1 = Point();
	Point p2 = Point(3, -1);
	Point p3 = p1.translate(p2);
	return (0);
}
```

Note that for clarity, the actual **declaration** and **definition** of the function have been separated, which follows good C++ practices for readability.

---

## Operator Overloading

> ℹ️ Unline in C, it is possible to add operator overloading to structures

For more information on **operator overloading**, see [[Operator Overloading]].

*ex:*

*point.hpp:* (declarations)
```cpp
struct Point {
	int x;
	int y;

	Point(int xVal = 0, int yVal = 0);
	Point    translate(const Point& p) const;
};

std::ostream& operator<<(std::ostream& os, const Point& p);
```

*Point.cpp:* (definitions)
```cpp
#include "point.hpp"

Point::Point(int xVal, int yVal) : x(xVal), y(yVal) {}

Point           Point::translate(const Point& p) const {
	return { .x = x + p.x, .y = y + p.y };
}

td::ostream&    operator<<(std::ostream& os, const Point& p) {
	os << "x:" << p.x << " y:" << p.y;
	return (os);
}
```

*main.cpp*
```cpp
#include <iostream>
#include "point.hpp"

int    main(void) {
	Point p1 = Point();
	Point p2 = Point(3, -1);
	Point p3 = p1.translate(p2);

	// "x:3 y:-1""
	std::cout << p3 << std::endl;

	return (0);
}
```