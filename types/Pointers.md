> 📚 **Pointers** in C++ represent an address in RAM memory, typically that of a variable.

## Creating a pointer

> ℹ️ C++ supports not only **constant pointers** but also **pointers to constant data** which cannot modify the data they are pointing to.
#### Constant pointer

A constant pointer cannot have it's address reassigned.

*syntax:*
```cpp
int x = 42;
int y = 12;
int* const ptr;

ptr = &x;
// the following line would throw a compilation error
// ptr = &y;

// the value pointed to by ptr can still be mutated
*p = 0;

// will display 0
std::cout << x << std::endl
```

#### Pointer to constant value

A pointer to a constant value cannot reassign the value it is pointing to.

*syntax:*
```cpp
int x = 42;
int y = 12;
const int* ptr;

ptr = &x;
// ptr can still have it's address reassigned
ptr = &y;

// the following line would throw a compilation error
// *p = 0;

// will display 42
std::cout << x << std::endl
```

#### Constant pointer to constant value

A constant pointer to a constant value can neither have it's address reassigned nor can it reassign the value it is pointing to.

*syntax:*
```cpp
int x = 42;
int y = 12;
const int* ptr;

ptr = &x;
// the following lines would throw a compilation error
// ptr = &y;
// *p = 0;

// will display 42
std::cout << x << std::endl
```

---

## NULL pointer

> 📚 `NULL`, or address `0x0`, is an out-of-bounds address that is neither part of programs stack or heap. It therefore cannot be read, addressed or modified. It typically denotes an empty or uninitialized pointer.

> 📚 `nullptr` is a new keyword introduced as of `C++11` that provides a more type-safe way of declaring a null pointer. It works in the same way as `NULL` but cannot be cast to any non-pointer type except for `bool`

---

## Dynamic allocation

> ⚠️ **DO NOT USE `malloc`, `calloc`, `realloc`, `free` or any other C allocation function in C++**

Dynamic memory allocation in C++ is handled using the `new` and `delete` keywords.

#### Allocating memory

Like in C, dynamically allocated memory is stored on the head and should be used for data whose's size is not known at compile-time. A typical example of this is dynamic arrays

*note that C++ provides it's own implementations of dynamic arrays as part of the standard library with the `Vector` class template.*

*syntax:*
```cpp
int array[];

// dynamically allocates an array of size 10
array = new int[10];
```

> ⚠️ Dynamically allocated memory will not be automatically freed when exiting the current scope and instead needs to be freed manually using `delete`.

#### Deallocating memory

To avoid **memory leaks** dynamically allocated memory must then be manually freed before it goes out of scope.

*syntax:*
```cpp
int array[]

array = new int[10];

// to free a non-array value, use 'delete' without '[]'
delete[] array;
```

---

## Smart Pointer `C++11`

> 📚 **Smart Pointers** are generic classes designed to automatically handle the life-cycle of a raw pointer, including it's deallocation.

*Smart pointer can also be used for more complex data management and freeing, such as network socket*

> ℹ️ Smart Pointers are implemented as classes which store an allocated raw pointer, which they then free up upon exiting scope. 
> 
> *(this can be easily implemented even in prior versions of C++ as a helper class)*.

#### Unique Pointer

> 📚 **Unique Pointers** cannot share their memory address with any other pointer and cannot be copied. This is because it will automatically free the allocated object it holds when it goes out of scope, regardless of if references still exists towards that object.

Unique pointers are simple enough that they introduce little to no overhead as compared to raw pointers.

*syntax:*
```cpp
int    foo(void) {
	auto array = make_unique<int[]>(10);
	
	// array will not cause any leak when exiting the scope of foo
	return (EXIT_SUCCESS);
}
```

#### Shared Pointer

> 📚 **Shared Pointer** can share the same memory address across multiple instances. This is because the class keeps track internally of the number of instances associated to a given address and only frees it when the number of references reaches 0.

Compared to unique pointers, shared pointers can introduce noticeable overhead due to their reference tracking capabilities, making them slower than raw pointers.

*syntax*
```cpp
int    foo(void) {
	auto x = make_shared<int>();
	auto y = shared_ptr<int>(x);

	// both x and y will be updated. Deleting x will not cause
	// y to have it's reference freed
	*x = 42;
	return (EXIT_SUCCESS);
}
```

---
*related* [[Arrays]] [[Basic Types]]