> 📚 **Inheritance** is a process by which a **child** class takes over some of the properties of it's **parent** class.

> 📚 A **child** is a class which inherits from another class.

> 📚 A **parent** is a class whose functionality is inherited by other classes.

Inheritance is a powerful tool for avoiding code duplication by grouping the functionality of related / similar classes in a single parent class. It should however be used with care, as excessive inheritance can lead to code that is over-generalized and difficult to read. Try to keep your class inheritance **simple** and **shallow** (that is to say, limit the number of successive parents a child can have).

OOP and inheritance has often been presented as a convenient way to model programming problems in a way which more closely resembles the real world, thus making projects more easy to understand, debug and reuse. This is not the case. 

> I highly suggest you use OOP as a tool for **data abstraction** rather than abstraction of *concepts*. 

This means you should use classes and inheritance to **model the data** you are working on in ways that make it easy to manipulate. Do not go down the traditional OOP rabbit hole of modelling your *problem* in terms of real-world counterparts. **TLDR**: think of your code in terms of data, not in terms of concepts, objects and abstractions.

*ex:*
	You do not need a class Worker, from which inherits `Manager`, and `SimpleEmployee`, from which inherits `InternEmployee`, `FulltimeEmployee` and `PartTimeEmployee`. Instead, create a class `EmployeeData` which generalizes the data of each of these classes. This follows the logic that while these objects are distinct in the real world, they are most likely manipulated the same way in our program. 

Following this principles, you will get better performance, a simpler codebase and a flat inheritance tree.

For more about the usage of OOP and inheritance in C++, you can refer to Mike Acton's legendary CppCon 2014 presentation on Data Oriented Design in C++ [here](https://yewtu.be/watch?v=rX0ItVEVjHc)

---
## Inheritance Qualifiers

The basic syntax for inheriting a class in C++ is as follows:
```cpp
class A {
public:
	int x;
	
protected:
	int y;
	
private:
	int x;
}

class B : A {
	// has access to `x` and `y`
} 
```

When inheriting from another class, the child has access to any parent attributes which are not `private` (that is to say any `public` or `protected` attribute).

Contrary to other OOP programming languages, in C++, the way in which you inherit from a class determines the visibility of it's attributes.

> 📚 **Inheritance Qualifiers** specify the maximum visibility of inherited class attributes.
> 
> - `public`: all inherited class attributes are visible.
> - `protected`: any public inherited attribute become protected.
> - `private` (default): any public or protected inherited attribute becomes private.
>   
>   This means that only the `public` instance qualifier allows for inherited class attributes to be accessed from outside the class. 

As a general rule, you will almost always be using the `public` inheritance qualifier except maybe in some very specific internal / wrapper classes in which you do not want to expose the functionality of the parent class.

*ex:*
```cpp
class A {
public:
	int    doSomething(void);
	
protected:
	int    protectedFunc(void);
	
private:
	// cannot be accessed from any child
    int    sneakyCode(void);
};

class B : public A {
	// no visibility changes, doSomething can
	// still be called from outside the class
};

class C : protected A {
	// doSomething becomes protected and can
	// only be access from this and child classes
}

class D : A {
	// doSomething and protectedFunc become private
	// and can only be accessed from this class
	// and not from any subclass
}
```

---

## Order of Construction and Destruction

When a class is inherited, constructors are applied as follows:

1) Highest parent constructor
2) Other parent constructors, in order of inheritance
3) Child constructor

*ex:*
```cpp
class A {
	A(void) {
		std::cout << "Constructor A" << std::endl;
	}
}

class B : public A {
	B(void) {
		std::cout << "Constructor B" << std::endl;
	}
}

class C : public B {
	C(void) {
		std::cout << "Constructor C" << std::endl;
	}
}

int main(void) {
	C c;
	
	return (0);
}
```

*output:*
```bash
Constructor A
Constructor B
Constructor C
```

On the contrary, destructors are applied in the reverse order:

1) Child destructor.
2) Other parent destructors, in order of reverse inheritance.
3) Highest parent destructor.

*ex:*
```cpp
class A {
	~A(void) {
		std::cout << "Destructor A" << std::endl;
	}
}

class B : public A {
	~B(void) {
		std::cout << "Destructor B" << std::endl;
	}
}

class C : public B {
	~C(void) {
		std::cout << "Destructor C" << std::endl;
	}
}

int main(void) {
	C c;
	
	return (0);
}
```

*output:*
```sh
Destructor C
Destructor B
Destructor D
```

---

## Overriding methods

> 📚 **Override** refers to the ability of child classes to redefine functions defined in a parent class. To be able to be overridden in a child class, a parent function should be marked as `virtual` while overridden function in the child class should be marked with `override`.

*ex:*
```cpp
// ================================[ Class A ]================================ //

class A {
public:
	virtual int    doSomething(void);
}

int    A::doSomething(void) {
	std::cout << "A does something" << std::endl;
}

// ================================[ Class B ]================================ //

class B {
public:
	int    doSomething(void) override;
}

int    B:doSomething(void) {
	std::cout << "B does something" << std::endl;
}
```

> ❓ However, how does C++ determine which function to call between `A::doSomething` and `B::doSomething` ?

---

## Function Call Resolution

 > 📚 In C++, a **binding** refers to the strategy used by the language to determine which function to call on an object.
 
There are two types of bindings available in C++:

- **static** or **early** bindings: these are done at compile time and depend solely in the type of the variable. So if a variable is of type A, the function being called will be from the A class.

	*ex:*
	```cpp
	// ==============================[ Class A ]============================== //
	
	class A {
	public:
		int    doSomething(void);
	}
	
	int    A::doSomething(void) {
		std::cout << "A does something" << std::endl;
	}

	// ==============================[ Class B ]============================== //
	
	class B {
	public:
		int    doSomething(void);
	}
	
	int    B:doSomething(void) {
		std::cout << "B does something" << std::endl;
	}

	// ================================[ MAIN ]=============================== //
	
	int    main(void) {
		B b;
		A disguisedB = b;
	
		disguisedB.doSomething();
	
		return (0);
	}
	```
	
	*output*
	```sh
	A does something
	```
	
	This is because the function `doSomething` is bound **statically** at compile time. For a function to be resolved based on the object, not it's type, a function must be bound **dynamically**, which is done using the `virtual` keyword.

- **dynamic** or **late** binding: these are done at runtime and depend on the object, not it's type. So if an object is created using a constructor from `B` then cast to `A`, it will still use the functions from it's original type `B`.
  
  	*ex:*
	```cpp
	// ==============================[ Class A ]============================== //
	
	class A {
	public:
		virtual int    doSomething(void);
	}
	
	int    A::doSomething(void) {
		std::cout << "A does something" << std::endl;
	}

	// ==============================[ Class B ]============================== //
	
	class B {
	public:
		int    doSomething(void) override;
	}
	
	int    B:doSomething(void) {
		std::cout << "B does something" << std::endl;
	}

	// ================================[ MAIN ]=============================== //
	
	int    main(void) {
		B b;
		A disguisedB = b;
	
		disguisedB.doSomething();
	
		return (0);
	}
	```
	
	*output*
	```sh
	A does something
	```
	
	This is because the function `doSomething` is bound **dynamically** as specified by the keyword `virtual`. The variable `disguisedB` is created as an instance of `B`, therefore it keeps using the functionality of the `B` class even after having been cast.
 
 > ⚠️ When redefining a function inside a child class, you should **always** use **dynamic binding** through the use of the `virtual` keyword to avoid any unexpected behavior when casting your class to a parent type. This becomes especially important in the context of [[Polymorphism]] and passing class instances to functions. ---

---

## Forcing override: abstract methods and classes

🚧 **under construction** 🚧

 ---
 
*related:* [[Polymorphism]] [[Classes]]
  



