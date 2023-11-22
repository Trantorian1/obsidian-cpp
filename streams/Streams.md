*There are two main types of streams in C++: **input** and **output**.*

## Writing to a Stream (output)

> 📚 **Output** streams can *write* to a data recipient.

Writing to a stream is done using the `<<` operator.

*ex:*
```cpp
#include <iosream>

std::cout << "Message" << std::endl;
```

> ⚠️ `std::endl` automatically flushes the stream buffer. When sending multiple lines of data to a stream, it is more efficient to use `\n` to represent a newline as this will not necessarily trigger a buffer flush.

---
## Reading from a Stream

> 📚 **Input** streams can *read* from a data source.

Reading from a stream is done using the `>>` operator.

*ex:*
```cpp
#include <iostream>

int n;

std::cout << "Enter a number" << std::endl;
std::cin >> n;
```

> ⚠️ Streams have an inner buffer that is progressively filled and consumed. Because of how stream output with `>>` works, output will stop at the first invalid character.

*ex:*
```cpp
int n1;
int n2;

std::cout << "Enter a number" << std::endl; // user enters 12 42
std::cin >> n1; // 12 is consumed
std::cin >> n2; // 42 is consumed
```

> ⚠️ The `>>` operator stops at the first delimiter encountered (see `man isspace`).

> ⚠️ As long as the stream buffer is not empty it will keep being consumed without further reading from the stream source.

In case where invalid input is possible, it is necessary to validate stream output between stream reads.

---

## Input Validation

- In case of any logical internal error, an `iostream` will set it's internal `failbit` flag to `true`.
- In case of any data integrity loss, an `iostream` will set it's internal `badbit` flag to `true`

> ℹ️ Errors in an `iostream` can be checked using for using the `fail` function, which will return true if either the `failbit` or `badbit` have been set. You can also check for `badbit` exclusively using the `bad` function.

> ⚠️ After checking for stream errors, you should reset any stream error flags using the `clear` function. You should also flush stream content using the `ignore` function.

*ex:*
```cpp
#include <iostream>

int n;

std::cout << "Enter a number" << std::endl;
std::cin >> n;

// checks for stream errors
if (std::cin.fail()) {
	// resets error flags
	std::cin.clear();
	// flushes user input in stream
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
```

> ℹ️ Use `numeric_limits<streamsize>::max()` to remove **all** stream contents up to the desired delimiter char (here `\n`).

This is a rather simple example of input validation. More complex (and much more common) checks might include steps such as parsing, splitting input and pattern matching with regex.

---

