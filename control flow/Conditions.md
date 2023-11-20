
---
## If Statements

*Same as in C*
```c++
if (condition_a) {
	// some code
} else if (condition_b) {
	// some more code
} else {
	// default
}
```

---
## Ternary operator

> ⚠️ Use the ternary operator sparingly as it can make code quite hard to read!

*Same as in C*
```c++
int n = condition ? val_if_true : val_if_false;
```

---
## Switch case

> ⚠️ Prioritize the usage of `switch` statements over `if` statements in case with multiple defined `int` states as they are generally easier to read (or try to rethink your  algorithms to represent  conditions as multiple defined `int` states). 

*Same as in C*
```c++
int n;

switch  (n) {
	case 0:
		// code
		break;
	case 1:
		// code
		break;
	default:
		// code
		break;
}
```

> ⚠️ Note that if you omit the `break` keyword, the `switch` will keep executing subsequent code until a `break` statement is reached. This can be sometime used to regroup several states as one but is generally less readable.

*example*
```c++
int n;

switch (n) {
	case 0:
	case 1:
		// case 0 and case 1 share the same code
		break;
	default:
		// code
		break;
}
```
