Structures can essentially be seen as a continuous in-memory array of mixed data. 

> ⚠️ **Alignment rules for data still need to be respected!**. 

For example, an 8-byte double needs to be 8-byte aligned, while a 4-byte integer needs to be 4-byte aligned. To maintain alignment between values in a structure and to allow for faster search, the compile might introduce **padding** inside the structure.

> 📚 **Padding** refers to extra space added by the compile inside a structure to meet alignment requirements between values.

*ex:*
```cpp
struct Padded {
	int n; // 4-byte aligned

	// 4 bytes missing for 'percent' to be 8-byte alligned
	// the compiler therefore add 4 bytes of padding

	double percent; // 8-byte aligned
};
```

Due to padding, the above structure will be 16 bytes long instead of 12 (4 bytes int + 4 bytes padding + 8 bytes double), which is equivalent to:

```cpp
// will have the same size in memory as 'padded'
struct NoPadding {
	int x; // 4-byte aligned
	int y; // 4-byte aligned

	// 2 variables, each 4-byte aligned, meaning we are now 8-byte
	// aligned, so no padding is needed for 'percent'

	double percent; // 8-byte aligned
};
```

In contrast, the following structure does not require any padding:

```cpp
struct NoPadding2 {
	int x; // 4-byte aligned
	float percent; // 4-byte aligned
};
```

> ℹ️ Pay close attention to how you organize your structure to avoid structure padding and reduce the size of your structure in memory. **This is important because of how RAM is copied to CPU L1, L2 and L3 cache**. In general, you want your structure's size to be a power of 2 (up to 64 bytes) to guarantee as many structures can be read in a single **page read**. If your structure is over 64 bytes in size, make sure the most commonly accessed elements are in the first 64 bytes to avoid unnecessary cache misses.

---

## Unpacking Structures `C++17`

Since structures are essentially in-memory arrays of mixed types, they still adhere to unpacking or **structure binding** rules, allowing for easy extractions of their member values.

*ex:*
```cpp
struct MyStruct {
	int x;
	int y;
	std::string name;
	short age;
};

MyStruct myStruct;
myStruct.x = 0;
myStruct.y = 0;
myStruct.name = "Trantorian";
myStruct.age = 42;

// x = 0
// y = 0
// name = "Trantorian"
// age = 42
auto [ x, y, name, age ] { myStruct };
```

---
*related:* [[Structures]] [[Structure Methods]] [[Classes]]