> 📚 **Inheritance** is a process by which a **child** class takes over some of the properties of it's **parent** class.

> 📚 A **child** is a class which inherits from another class.

> 📚 A **parent** is a class whose functionality inherited by other classes.

Inheritance is a powerful tool for avoiding code duplication by grouping the functionality of related / similar classes in a single parent class. It should however be used with care, as excessive inheritance can lead to code that is over-generalized and difficult to read.

An example of over-generalized code might be the existence of a class such as `Node`, which as of it's name indicates a very (too) broad scope of usage and inheritance. Try to keep your class inheritance **simple** and **shallow** (that is to say, limit the number of successive parents a child can have).

OOP and inheritance has often been presented as a convenient way to model programming problems in a way which more closely resembles the real world, thus making projects more easy to understand, debug and reuse. This is not the case. I highly suggest you use OOP as a tool for **data abstraction** rather than abstraction of *concepts*. 
This means you should use classes and inheritance to **model the data** you are working as best befits your problem. Do not go down the traditional OOP rabbit hole of modelling your *problem* in terms of real-world counterparts. 

*ex:*
	You do not need a class Worker, from which inherits Manager, and `SimpleEmployee`, from which inherits `InternEmployee`, `FulltimeEmployee` and `PartTimeEmployee`. Instead, create a class `EmployeeData` which contains a bit mask of employee permission and ranks, pack that into a `vector` for better cache locality and add functions to operate on `EmployeeData`.

For more about the usage of OOP and inheritance in C++, you can refer to Mike Acton's legendary CppCon 2014 presentation on Data Oriented Design in C++ [here](https://yewtu.be/watch?v=rX0ItVEVjHc)