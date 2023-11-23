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
> - 



