Namespaces in C++ are a way to control function and class visibility, avoid name conflicts and organize your code.

> ℹ️ Namespaces can essentially be seen as an additional prefix to function and classes which guarantees their uniqueness.
> 
> *ex:* `std::string` is not the same as `helper::string`

*syntax:*
```cpp
namespace someNamespace {
	// code goes here
}
```

> ⚠️ Namespace declaration needs to be part of both code **source** and code **declaration**.
> 
> *ex:* if you define a function inside the namespace `helper`, then it's definition inside the corresponding header also need to be defined inside the same namespace.

---
## `using namespace` directive

> ⚠️ **DO NOT USE** the `using namespace` directive. It is considered bad practice.

`using namespace` allows you to use any function, class or variable defined inside the specified namespace. However, this removes and conflict protection associated with the specified namespace.

---

## Nested Namespaces

Namespaces are a powerful tool for organizing your code. Especially useful is the ability to chain or nest namespaces.

*syntax:*
```cpp
namespace outer {
	namespace inner {
		// code
	}
}
```

In the above example, any code in `inner` will have to be accessed as `outer::inner`. This allows to compartmentalize how you want your code to be accessed, by for example specifying a general outer namespace and then narrowing it down to more specific namespaces.

> ⚠️ Do not overly rely on nested namespaces as they increase the complexity for accessing code.

---
## Anonymous Namespaces

Anonymous namespaces are namespaces that are local to the file in which they are created. This means that any code defined inside them will not be able to be accessed from outside. This is especially useful when grouping helper or internal library code which is only relevant from withing the scope of the file in which it is 'helping'.

*syntax:*
```cpp
namespace {
	// code
}
```

> ℹ️ Anonymous namespaces are unique to the file in which they are defined. This means that even if two separate files have an anonymous namespace with exactly the same code, that code will still be considered unique and not generate any build conflict as long as it is within it's own `namespace`.

---
*related* [[Functions]]