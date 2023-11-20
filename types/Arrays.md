## Creating Arrays

*Same syntax as in C:*
```cpp
int    array[] = { 1, 2, 3, 4 };

int    matrix[2][3] = {
	{ 1, 2, 3 },
	{ 4, 5, 6 }
};
```

---
## Determining the size of an Array

For statically allocated arrays (arrays whose size is known at compile time), it can still be necessary to retrieve their size for iteration:

#### Using `sizeof`

```cpp
int    array[] = { 1, 2, 3, 4 };

for (size_t i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	std::cout << array[i] << std::endl;
```

> 💡 `sizeof(array)` returns the size of the variable `array` in memory, while `sizeof(array[0])` returns the size of each element in `array`, which allows us to retrieve the number of elements in `array` through division.

#### Using `std::size` `C++17`

```cpp
int    array[] = { 1, 2, 3, 4 };

for (size_t i = 0; i < std::size(array); i++)
	std::cout << array[i] << std::endl;
```

**✏️ TODO:** I have no idea how the std::size code works under the hood, need to learn more about templates before I can explain this. ^e65964

---
## Unpacking arrays

> 📚 **Unpacking an array** refers to the act of retrieving it's values and storing them in single variables.

#### Manually

```cpp
int    array[] = { 1, 2, 3 };

int    x = array[0];
int    y = array[1];
int    z = array[2];
```

#### Structured Bindings `C++17`

```cpp
int    array[] = { 1, 2, 3 };

int    [x, y, z] = array;
```

> ℹ️ C++17 structured bindings provide a way to unpack arrays and containers automatically (can be defined by custom classes as well)

---
## Iterating over an array

Always, always, **always** use **unsigned** data types to iterate over your arrays. Preferably, use `size_t` as it is guaranteed to be the largest possible type, with no risk of overflow should your index be too big. In general, make sure:

1. Your index type does allow for any negative values
2. Your index type does not risk any overflows
3. You do not pass any out-of-bounds index to your array

> ℹ️ A safer alternative to traditional arrays is [[Vector]]

*ex:*
```cpp
int    array[] = { 1, 2, 3, 4 };

for (size_t i; i < std::size(array), i++)
	std::cout << array[i] << std::endl;
```

---
*related* [[Vector]] [[Basic Types]] [[Loops]]