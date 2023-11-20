## Function Syntax

*Same as in C*

> ℹ️ Additional complexity can be added with class return types and polymorphism.

```cpp
double    mult(double x, double y) {
	return (x * y);
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

