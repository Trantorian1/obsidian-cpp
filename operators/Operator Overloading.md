> ℹ️ Operator Overloading in C++ is a very powerful feature that should however be used **sparingly**. It allows custom classes to behave much closer to builtin types by supporting basic operations such as *comparison*, *arithmetics* , *stream insertion*... Note however that overusing operator overloading can lead to obfuscated and counter-intuitive code. **You should only overload an operator if it's use makes ABSOLUTE sense and has NO ambiguity in the context of the class is it being applied to.**

---

## Equality Operator `==`

*syntax:*
```cpp
bool    operator==(const Object& other) const;
```

---

## Inequality Operator `!=`

> ℹ️ Note that on most modern C++ compilers, overloading the `==` operator automatically overloads the `!=` operator.

*syntax*
```cpp
bool    operator!=(const Object& other) const;
```

> ⚠️ When overloading interdependent operators such as `==` and `!=`, you should make sure that their functions call each other to avoid duplicate code.

*ex:*
```cpp
bool    Object::operator==(const Object& other) const {
	return (Object::attribute == other.attribute);
}

// calls `operrator==`, only relying on 
// the above implementation of equality
bool    Object::operator!=(const Object& other) const {
	return (!(*this == other));
}
```

---

## Comparison Operators `<` `<=` `>` `>=`

*syntax:*
```cpp
bool    operator<(const Object& other) const;
bool    operator<=(const Object& other) const;
bool    operator>(const Object& other) const;
bool    operator>=(const Object& other) const;
```

*ex:*
```cpp
bool    Object::operator<(const Object& other) const {
	return (Object::attribute < other.attribute);
}

bool    Object::operator>(const Object& other) const {
	return (Object::attribute > other.attribute);
}

// only relies on the`>` operator,
// avoiding duplicate code
bool    Object::operator<=(const Object& other) const {
	return (!(*this > other));
}

// only relies on the`<` operator,
// avoiding duplicate code
bool    Object::operator>=(const Object& other) const {
	return (!(*this < other));
}
```

---

## Spaceship Operator `<=>` `C++20`

> ℹ️ `<=>` was a new operator added to `C++20` that simplifies comparison overloading.

*syntax:*
```cpp
std::strong_ordering    operator<=>(const Object& other) const;
```

*ex:*
```cpp
std::strong_ordering    Object::operator<=>(const Object& other) const {
	return (Object::attribute <=> other.attribute);
}
```

> ℹ️ Overloading `<=>` provides automatic overload for the other `<` `<=` `>` `>=` operators.

---

## Stream Insertion Operator `<<`

> ⚠️ Contrarily to other operators, `<<` must be overloaded **outside** of the class it affects. This is because in this case `object` is no longer the left-operand of the operation but instead the parameter passed to it, meaning the function will not have any references to `this`.

*syntax:*
```cpp
std::ostream&    operator<<(std::ostream& os, const Object& object);
```

*ex:*
```cpp
std::ostream&    operator<<(std::ostream& os, const Object& object) {
	os << "[attribute:" << Object::attribute << "]";
	return (os); // return os to be able to chain insertion operations
}
```

> ⚠️ I **highly** suggest you override the `<<` operator in any class you used during development if only for debugging purposes. More advanced use cases can include data serialization to formats such as [JSON](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/JSON) or [XML](https://developer.mozilla.org/en-US/docs/Web/XML/XML_introduction).

---

## Stream Extraction Operator

> ⚠️ Similarly to `<<`, `>>` must be overloaded **outside** the class it affects.

*syntax:*
```cpp
std::istream&    operator>>(std::istream& is, Object& object);
```

*ex:*
```cpp
std::istream&    operator>>(std::istream& is, Object& object) {
	object.deserialise(is);
	return (is);
}
```

> ⚠️ You should only overload `>>` for:
> 
> a) data which is trivial to parse, ie: 1 continuous argument in the input stream.
> b) data that follows a clearly established serialized format.
> 
> You **should NOT** overload `>>` for:
> 
> a) data with multiple variable format arguments, such as user-entered coordinates.
> b) data which does not follow an exact and clearly pre-defined structure.
> 
> In general, you should overload `>>` **only for data of which you know the format with absolute certainty**. Remember that the use of `>>` should **remain clear and intuitive** and ==**NOT SERVE AS A JACK OF ALL TRADES TO RETRIEVE DATA !!!**==.

*ex:*
```cpp
XmlData          xml;
std::ifilestream file;

file.open("filepath");
if (file.is_open() == false)
	return ;

file >> xml;
file.close()
```

---
## Arithmetic Operators 
`+` `-` `*` `/` `%` `~` `&` `|` `^` `<<`(lshift) `>>`(rshift)

*syntax:*
```cpp
Object    operator+(const Object& other) const;
```

*ex:*
```cpp
Object    Object::operator+(const Object& other) const {
	return (Object(Object::attribute + other.attribute));
}
```

---

## Compound Assignment Operators
`+=` `-=` `*=` `/=` `%=` `~=` `&=` `|=` `^=` `<<=` `>>=`

*syntax:*
```cpp
Object&    operator+=(const Object& other);
```

*ex:*
```cpp
Object&    Object::operator+=(const Object& other) {
	Object::attribute + other.attribute;
	return (*this);
}
```

> ⚠️ **DO NOT** overload any compound assignment operator without overloading the  associated arithmetic operator.

---

## Assignment Operator `=`

*syntax:*
```cpp
Object&    operator=(const Object& other);
```

*ex:*
```cpp
Object&    Object::operator=(const Object& other) {
	Object::attribute = other.attribute;
	return (*this);
}
```

> ⚠️ **DO NOT** overload `=` without creating a copy constructor!!! This is because C++ will use the copy constructor or the assignment operator depending on whether the object in question has not been initialized yet.

---

## Unary Operators `++val` `--val` `val++` `val--`

*syntax:*
```cpp
Object&    operator++(void); // prefix (ie: ++val)
Object     operator++(int);  // postfix (ie: val++);
```

*ex:*
```cpp
// pre-incrementation
Object&    Object::operator++(void) {
	Object::attribute++:
	return (*this);
}

// post-incrementation
Object     Object::operator++(int) {
	Object copy = *this;
	this->operator++(); // re-uses the incrementation logic from ++val
	return (copy);
}
```

> ⚠️ You **SHOULD NOT** override unary operators without overriding their associated arithmetic operators.

---

## Subscript Operator `[]`

> ⚠️ You should **ONLY** override `[]` for custom collection or containers. For any other class with a finite amount of data associated, refer to custom getters / setters instead.

*syntax:*
```cpp
datatype&    operator[](std::size_t index);
```

*ex:*
```cpp
datatype&    Object::operator[](std::size_t index) {
	if (index >= Object::_size)
		throw (std::out_of_range())
	
	return (Object::attribute[index]);
}
```

---

## Indirection Operator `*`

> ⚠️ You should **ONLY** override `*` for data structures holding pointers as their primary data source (ex: smart pointers).

*syntax:*
```cpp
datatype&    operator*(void);
```

*ex:*
```cpp
datatype&    Object::operator*(void) {
	return (*Object::attribute); // attribute should be a pointer !!!
}
```

> ⚠️ **DO NOT** use `*` as a way to get a pointer to otherwise non-pointer class members!

---

## Type Conversion Overload

While strictly speaking not an operator, it is also possible to override casting operations in a class, so calls to functions such as `static_cast<>()` will evaluate to a custom result.

*syntax:*
```cpp
operator int(void) const; // int can be replace by any cast type
```

*ex:*
```cpp
Object::operator int(void) const {
	return (Object::attribute); // attribute should be an int!
}
```

> ⚠️ You should **ONLY** override type conversion for **strongly associated types**, such as in the case of a class that acts as a wrapper around another type (ex: a height class might have a custom conversion to double). Remember that it still might just be a better idea to **make such functionalities accessible behind a getter instead**.

---
*related:* [[Operator priority]] [[Classes]] [[Streams]]