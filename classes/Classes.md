Classes are C++'s way of representing abstract data in an easily manipulable way.

---

## Member variables

> 📚 **Member Variables** are variables which are part of a class as either class instance variables or static variables.

> ⚠️ C++ class member variables are **private by default**, as compared to structure member variables which are public by default.

*myClass.hpp:*
```cpp
class MyClass {
	int x;
	int y;
	std::string uid;
	// ...
}
```

*main.cpp*
```cpp
#include "myClass.hpp"

MyClass myClass;

// Compilation error!
myClass.x;
```

---

## Access modifiers

> 📚 **Access modifiers** allow to modify the visibility of class attributes.

> 📚 **Class attributes** are the individual components which make up a class. This include member variables, member function, constructors, destructors...

- **public**: public attributes are accessible from anywhere in the program. They should only be used for exposing constant data, or simple data with no verification logic.

- **protected**: protected attributes are accessible from inside the class and any derived class (see [[Inheritance]]) and nowhere else in the program. They should be used for data which can be mutated across subclasses or whose functionality can change as a result of inheritance.

- **private**: private attributes are only accessible from within the class itself. They should be used as part of encapsulation to hide the inner workings of a class. If needed, they can be exposed publicly through the use of **getters** and **setters** (see [[Accessors]]).

> ℹ️ By convention, member variables that are not public are prefaced with `_`

*ex:*
```cpp
class Person {
public:
	std::string		name;

private:
	unsigned short	_age;
	unsigned short	_height;
};
```

---

## Getters

> 📚 **Getters** are functions that allow to *retrieve* the values of private member variables without exposing them publicly. (see *setters* [[#^bb44f2]])

^b10b31

*person.hpp:*
```cpp
class Person {
public:
	std::string		name;

	unsigned short	getAge(void) const;
	unsigned short	getHeight(void) const;

private:
	unsigned short	_age;
	unsigned short	_height;
};
```

*peson.cpp:*
```cpp
// ==============================[ GETTERS ]================================= //

unsigned short	Person::getAge(void) const {
	return Person::_age;
}

unsigned short	Person::getHeight(void) const {
	return Person::_height;
}
```

---

## Setters

> 📚 **Setters** are functions that allow to *mutate* the values of private member variables without exposing them publicly. (see *getters* [[#^b10b31]])

^bb44f2

*person.hpp*
```cpp
class Person {
public:
	std::string		name;

	unsigned short	getAge(void) const;
	unsigned short	getHeight(void) const;
	void			setAge(unsigned short age);
	void			setHeight(unsigned short height);

private:
	unsigned short	_age;
	unsigned short	_height;
};
```

*person.cpp*
```cpp
// ==============================[ SETTERS ]================================= //

void	Person::setAge(unsigned short age) {
	if (age > 110)
		return;
	Person::_age = age;
}

void	Person::setHeight(unsigned short height) {
	if (height > 300)
		return;
	Person::_height = height;
}
```

---

## Member Functions

> 📚 **Member Functions** are functions that are internal to a class, giving it it's core functionality.

*person.hpp*
```cpp
class Person {
public:
	std::string		name;

	unsigned short	getAge(void) const;
	unsigned short	getHeight(void) const;
	void			setAge(unsigned short age);
	void			setHeight(unsigned short height);

	void			impersonate(Person& other);

private:
	unsigned short	_age;
	unsigned short	_height;
};
```

*person.cpp*
```cpp
// =============================[ FUNCTIONS ]================================ //

void	Person::impersonate(Person& other) {
	Person::name = other.name;
	Person::_age = other._age;
}
```

---

## Constructors

> 📚 **Constructors** allow for an easier way to create classes by specifying directly the values used to initialize them.

There are 3 main types of constructors in C++:

- **default constructor**: no arguments, this constructor creates a new class instance with default member variable values.

- **parametric constructor**: has arguments for the necessary member variables, initializing them following any logic defined in custom accessors.

- **copy constructor**: creates a new class instance from an existing class instance. Should perform a deep-copy on any object member variables (this includes `std::string`, `std::vector`, arrays...).

> ℹ️ The **default constructor** and **parametric constructor** are part of the [[Orthodox Canonical Class Form]].

*person.hpp*
```cpp
class Person {
public:
	std::string		name;

	Person();
	Person(std::string name, unsigned short age, unsigned short height);
	Person(Person& person);

	unsigned short	getAge(void) const;
	unsigned short	getHeight(void) const;
	void			setAge(unsigned short age);
	void			setHeight(unsigned short height);

	void			impersonate(Person& other);

private:
	unsigned short	_age;
	unsigned short	_height;
};
```

*person.cpp*
```cpp
// ============================[ CONSTRUCTORS ]============================== //

// default constructor
Person::Person(): name(""), _age(0), _height(0) {}

// parametric constructor
Person::Person(std::string name, unsigned short age, unsigned short height):
	name(name), _age(age), _height(height) {}

// copy constructor
Person::Person(Person& person): 
	name(person.name), _age(person._age), _height(person._height) {}

```

---

## Destructors

> 📚 **Destructors** specify a custom way to destroy a class instance, performing any necessary steps, including freeing up any allocated memory.

> ℹ️ A custom **destructor** is required by the [[Orthodox Canonical Class Form]].

*person.hpp:*
```cpp
class Person {
public:
	std::string		name;

	Person();
	Person(std::string name, unsigned short age, unsigned short height);
	Person(Person& person);
	~Person();

	unsigned short	getAge(void) const;
	unsigned short	getHeight(void) const;
	void			setAge(unsigned short age);
	void			setHeight(unsigned short height);

	void			impersonate(Person& other);

private:
	unsigned short	_age;
	unsigned short	_height;
};
```

*person.cpp:*
```cpp
// =============================[ DESTRUCTOR ]=============================== //

Person::~Person() {
	// custom destruction code goes here
}
```

---
*related:* [[Inheritance]] [[Operator Overloading]] [[Orthodox Canonical Class Form]]




