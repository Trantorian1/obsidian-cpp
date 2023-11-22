C++ `std::string` are a wrapper around C's implementation of strings which allow for extra functionality and easier handling.

*syntax:*
```cpp
std::string fullName = "Trantorian 1"
std::string firstName = fullName.substr(0, 10); // Trantorian
```

A C++ `std::string` is aware of it's length, automatically handles growing and shrinking as well as the life-cycle of it's internal C string.

> ℹ️ `std::string` also provides several useful operator overloads such as `==` for string equality checks and `+` for string concatenation.

---

## Manipulating Strings using Streams

String can also be easily manipulated using `std::stringstream` to benefit from the formatting capabilities of C++ streams.

> ℹ️ There are 3 types of string streams:
> 
> - `std::istringstream` for string input
> - `std::ostringstream` for string output
> - `std::stringstream` for string input & output

*ex:*
```cpp
std::istringstream stream;
std::string str;

// saving data to string stream
stream << setw(20) << "Column1" << setw(20) << "Column2\n"
       << setw(20) << "data1" << setw(20) << "data2"

// converting string stream to string
str = stream.str();

std::cout << str << std::endl;
```

---

## String to number `C++11`

> ℹ️ `std::string` also provides multiple functions to convert a string to a number.

| Function | Converts To          |
| -------- | -------------------- |
| `stoi`   | `int`                |
| `stol`   | `long`               |
| `stoll`  | `long long`          |
| `stoul`  | `unsigned long`      |
| `stoull` | `unsigned long long` |
| `stof`   | `float`              |
| `stod`   | `double`             |
| `stold`  | `long double`                     |

---

## Number to String `C++11`

> ℹ️ `std::string` also provides the `to_string` function to convert any number to it's string representation by providing overloads for each number type.

---
*related* [[Classes]] [[Operator Overloading]] [[Streams]]
