*Because there are only two hard things in computer science: cache invalidations and naming things.*
`- PythonPizzaDE, Reddit, circa 2023`

\-

> 📚 The **Orthodox Canonical Class Form**, or **OCCF**, is a standard for creating classes so as to avoid common mistakes associated to the lack of core class functions such as custom destructors and copy constructors.

Essentially, the Orthodox Canonical Class Form should be seen as a standard for the minimal required capabilities of a class.

## Requirements:

Classes that adhere to the **Orthodox Canonical Class Form** must implement the following:

- **default constructor**
- **copy constructor**
- **destructor**
- **copy assignment operator**

*example of an Orthodox Canonical Class:*
```cpp
class Person {
public: 
	Person();                         // default constructor
	Person(Person& person);           // copy constructor
	~Person();                        // destructor
	Person&	operator=(Person& other); // copy asignment operator
};
```

---

## Also suggested

I also strongly suggest you implement the following:

- **parametric constructor**
- **stream input operator** (<<)

*example of a Trantorian Canonical Class :)*
```cpp
class Person {
public:
	std::string		name;

	Person();
	// parametric constructor [+]
	Person(std::string name, unsigned short age, unsigned short height);
	Person(Person& person);
	~Person();
	Person&	operator=(Person& other);

private:
	unsigned short	_age;
	unsigned short	_height;
};

// stream input operator [+]
std::ostream&	operator<<(std::ostream& os, Person& person);
```

---
*related:* [[Classes]] [[Inheritance]] [[Operator Overloading]]

