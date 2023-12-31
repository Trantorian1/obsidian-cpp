There are 3 types of streams for dealing with files:

- `std::ifstream` can **write** to a file.
- `std::ofstream` can **read** from a file.
- `std::fstream` **read** and **read** from a file.

---

## Writing to a file

0. Create a `std::ofstread` or `fstream` object.
1. Open file using `file.open(filePath)`
2. Check file was successfully opened using `file.is_open()`
3. Write to file
4. Close file using `file.close()`

*ex:*
```cpp
#include <cstdlib>
#include <iostream>
#include <fstream>

int	main(void) {
	std::ofstream	file;

	file.open("lorem_ipsum.txt");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	// Using `\n` to avoid unecessary buffer flushes
	file << "Lorem Ipsum dolor si amet\n"
		 << "consectetur adipiscing elit\n";

	file.close();

	return (EXIT_SUCCESS);
}
```

---

## Reading from a file

0. Create a `std::ofstread` or `fstream` object.
1. Open file using `file.open(filePath)`
2. Check file was successfully opened using `file.is_open()`
3. Check for file end using `file.eof()`
4. Read file contents using `getline(...)`
5. Close file using `file.close()`

*ex:*
```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int	main(void) {
	std::ifstream	file;
	std::string		line;

	file.open("./poem.txt");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	// priting as long as file still has lines
	while (file.eof() == false) {
		std::getline(file, line);
		std::cout << line << '\n';
	}

	file.close();

	return (EXIT_SUCCESS);
}
```

---

## Binary Files

> 📚 **Binary files** are a type of file where data is stored as it would be in memory instead of in ascii format. So for example an `int` will be code in 4 bytes, instead of 1 byte per digit. This leads to much smaller file sizes, although the resulting output is not human readable.

---

## Writing to binary files

> ℹ️ Writing to binary files is done using the `write` stream function.

*ex:*
```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>

int	main(void) {
	std::ofstream	file;
	int				data[] = { 100, 200, 300 };

	file.open("data.dat");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	// we need to cast data to 'char *' to get 
	// it's representation in memory
	file.write(reinterpret_cast<char *>(data), sizeof(data));
	file.close();

	return (EXIT_SUCCESS);
}
```

*data.dat:*
```bash
d   �   ,  
```

---

## Read from binary file

> ℹ️ Reading from a binary file is done using the `read` stream function.

*ex:*
```cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>

int	main(void) {
	std::ifstream	file;
	int				n;

	file.open("data.dat");
	if (file.is_open() == false)
		return (EXIT_FAILURE);

	while (true) {
		file.read(reinterpret_cast<char *>(&n), sizeof(n));

		// 'file.read' mutates 'file.eof()'
		// so the check needs to happen here
		if (file.eof() == true)
			break;

		std::cout << n << std::endl;
	}

	return (EXIT_SUCCESS);
}
```

*output:*
```bash
100
200
300
```

> ℹ️ **TLDR**: use binary files in production or whenever it becomes necessary to reduce file size and output readability and debugability is no longer a concern.

