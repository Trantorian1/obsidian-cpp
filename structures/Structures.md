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
*related:* [[Structures In Memory]] [[Structure Methods]] [[Operator Overloading]] [[Classes]] 
