## For loop

*Same as in C*
```cpp
for (int i = 0; i < 3; i++)
	std::cout << "i:" << i << std::endl;
```

*output*
```sh
i:0
i:1
i:2
```

---
## Range-based for loop `C++11`

> Allows for simpler/safer iteration over basic array types that does not rely on the programmer knowing the size of the array in advance.

*Syntax*
```cpp
int values[] = { 0, 1, 2 };

for (number: values)
	std::cout << "i:" << i << std::endl;
```

*output*
```sh
i:0
i:1
i:2
```

---
## While loops

*Same as in C*
```cpp
int n = 2;

while (n >= 0) {
	std::cout << "i:" << i << std::endl;
	n--;
}
```

*output*
```sh
i:0
i:1
i:2
```

---

## Do-while loops

> Allows to run code in a loop that might otherwise require prior initialization (loop code will always run at least once).

*Same as in C*
```cpp
do {
	// loop code
} while (condition);
```

