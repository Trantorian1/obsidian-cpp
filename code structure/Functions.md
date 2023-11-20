## Function Syntax

*Same as in C*

> ℹ️ Additional complexity can be added with class return types and polymorphism.

```cpp
double    mult(double x, double y) {
	return (x * y);
}
```

---
## Reference Parameters

Reference parameters allow to pass a reference to a variable. If the variable is then mutated inside the function, these change will persist outside of the scope of the function.

> ℹ️ Contrary to C pointers, variable references do not need to be dereferenced, and the variable can be passed directly without taking it's address in memory.

*syntax:*
```cpp
void    update(int& n) {
	n = 42;
}

int    main(void) {
	int n = 12;

	update(n);
	std::cout << n << std::endl; // will display 42

	return EXIT_SUCCESS;
}
```

*using pointers:*
```cpp
void    update(int* n) {
	*n = 42;
}

int    main(void) {
	int n = 12;

	update(&n);
	std::cout << n << std::endl; // will display 42

	return EXIT_SUCCESS;
}
```

---
## Default Parameters

Unlike C, C++ supports functions with default arguments. This means you can define a function with multiple arguments and call it with only the required arguments.

> ⚠️ The order of arguments still needs to be respected, and as such optional arguments do not have any use if they are not at the end of the function.

```cpp
void    greet(std::string name, std::string greeter = "Hello") {
	std::cout << greeter << " " << name << "!" << std::endl;
}
```

---
## Arrays as parameters

Arrays as function parameters introduce extra complexity. When passed as an argument, an array is automatically cast to a pointer and looses any size information it might have, even using `C++17` `std::size`.

> ⚠️ Unless the array itself contains information about it's size, as is the case with a null-terminated string, you should always pass the size of the array as a function parameter to be able to iterate over it.

*ex:*
```cpp
void    put(int array[], std::size_t len) {
	for (std::size_t i = 0; i < len; i++)
		std::cout << array[i] << std::endl
}
```

> ⚠️ Always pass a size of type `std::size_t` as it is contractually guaranteed to be the largest possible type on the platform being used, thus insuring your index will fit, regardless of it's size. If you **for certain** know the range of your index lands within the bounds of a smaller type, you might use that instead. In general though, make sure your index type doesn't cause an overflow and **always use unsigned values**.

---
## Function Overloading

C++ function overloading allows one function to have multiple definitions, each with different arguments.

> ⚠️ This only works as long as each function definition has a unique *signature*.

> 📚 A function's **signature** is defined by it's name and arguments, so that two functions need to have a different name and arguments to be considered unique.

^757803

*syntax*
```cpp
void    greet(std::string name) {
	std::cout << "Hello " << name << "!" << std::endl;
}

void    greet(std::string name, std::string greeter) {
	std::cout << greeter << " " << name << "!" << std::endl;
}
```

---
## Calling order

As in C, functions cannot access other functions defined *after* them. These instead need to be defined in prototypes beforehand to be accessible before their definition.

> 📚 A function's **declaration** is where that function's *signature* [[#^757803]] is first defined, such as in a header file or at the top of a source file.

^69cb00

> 📚 A function's **definition** is where a function's code is specified as part of it's *body* [[#^608730]].

^b3954f

> 📚 A function's **body** is the part of a function between curly braces `{}` which defines the code executed by the function.

^608730

*ex:*
```cpp
int    functionB(void);

int    functionA(void) {
	// this works because functionB was DECLARED before functionA
	return (functionB());
}

int    functionB(void) {
	// the following code would throw a compilation error because
	// functionC was not declared before functionB
	// return (functionC());
}

int    functionC(void) {
	// code
}
```

---
*related* [[Namespaces]]

