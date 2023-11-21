> 📚 **Structures** in C++ are a way of representing simple data, or **POD**. Unlike C, structures in C++ also support member functions and operator overloading.

> 📚 **POD** or **P**lain **O**ld **D**ata refers to data that is simple and straightforwards, without any complex accessor logic or behavior. For more complex behavior, please use classes [[About Classes]]. Examples of **POD** would be simple vectors, quaternions, or any other data that does not require verification of fields on update (a date is a good counter-example as it is necessary to check the date is valid upon updating it).

*Structure syntax is similar to C:*
```cpp
struct Vec2D {
	double x;
	double y;
};
```

---

## Structures in-memory

Structures can essentially be seen as a continuous in-memory array of mixed data. 

> ⚠️ **Alignment rules for data still need to be respected!**. 

For example, an 8-byte double needs to be 8-byte aligned, while a 4-byte integer needs to be 4-byte aligned. To maintain alignment between values in a structure and to allow for faster search, the compile might introduce **padding** inside the structure.

> 📚 **Padding** refers to extra space added by the compile inside a structure to meet alignment requirements between values.

*ex:*
```cpp
struct Padded {
	int n; // 4-byte aligned

	// 4 bytes missing for 'percent' to be 8-byte alligned
	// the compiler therefore add 4 bytes of padding

	double percent; // 8-byte aligned
};
```

Due to padding, the above structure will be 16 bytes long instead of 12 (4 bytes int + 4 bytes padding + 8 bytes double), which is equivalent to:

```cpp
// will have the same size in memory as 'padded'
struct NoPadding {
	int x; // 4-byte aligned
	int y; // 4-byte aligned

	// 2 variables, each 4-byte aligned, meaning we are now 8-byte
	// aligned, so no padding is needed for 'percent'

	double percent; // 8-byte aligned
};
```

In contrast, the following structure does not require any padding:

```cpp
struct NoPadding2 {
	int x; // 4-byte aligned
	float percent; // 4-byte aligned
};
```

> ℹ️ Pay close attention to how you organize your structure to avoid structure padding and reduce the size of your structure in memory. **This is important because of how RAM is copied to CPU L1, L2 and L3 cache**. In general, you want your structure's size to be a power of 2 (up to 64 bytes) to guarantee as many structures can be read in a single **page read**. If your structure is over 64 bytes in size, make sure the most commonly accessed elements are in the first 64 bytes to avoid unnecessary cache misses.

---

## Unpacking Structures `C++17`

Since structures are essentially in-memory arrays of mixed types, they still adhere to unpacking or **structure binding** rules, allowing for easy extractions of their member values.

*ex:*
```cpp
struct MyStruct {
	int x;
	int y;
	std::string name;
	short age;
};

MyStruct myStruct;
myStruct.x = 0;
myStruct.y = 0;
myStruct.name = "Trantorian";
myStruct.age = 42;

// x = 0
// y = 0
// name = "Trantorian"
// age = 42
auto [ x, y, name, age ] { myStruct };
```

---

## Generalized initializers `C++11`

> ℹ️ Unlike C, C++ structures cannot be initialized using the `{}` syntax prior to C++11

*syntax:*
```cpp
struct MyStruct {
	int x;
	int y;
	std::string name;
	short age;
};

MyStruct myStruct = { 0, 0, "Trantorian", 42 };
```

---

## Default Member Values `C++11`

As of C++11, it is possible to give member variables a default value.

*syntax:*
```cpp
struct MyStruct {
	int x = 0;
	int y = 0;
	std::string name = "Trantorian";
	short age = 42;
};
```

---
## Structure Constructors

> ℹ️ C++ structures have essentially the same functionality as classes, with the only difference that any member value is public by default.

*syntax:*
```cpp
struct Point {
	int x;
	int y;

	Point(int xVal = 0, int yVal = 0) {
		x = xVal;
		y = yVal;
	}
};

Point p = Point();
Point p = Point(1, 2);
```

It is also possible to use **member initializer lists** to initialize member variables directly.

*syntax:*
```cpp
struct Point {
	int x;
	int y;

	// x and y initialized using member 
	// initializers x(...) and y(...)
	Point(int xVal = 0, int yVal = 0): x(xVal), y(yVal) {}
};

Point p = Point();
Point p = Point(1, 2);
```

---

## Structure Methods

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