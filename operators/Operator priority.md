
*Priorities listed from highest to lowest. Groups should still be read from top to bottom in terms of priorities.*

---
## 1. Postfix Operators

| Operator                     | Symbols            | Priority |
| ---------------------------- | ------------------ | -------- |
| Accessors                    | `()` `[]` `->` `.` | 1        |
| Post increment and decrement | `++` `--`          | 1        | 


---
## 2. Prefix Operators

| Operator                    | Symbols   | Priority |
| --------------------------- | --------- | -------- |
| Pre-increment and decrement | `++` `--` | 2        |
| Unary plus and minus        | `+` `-`   | 2        |
| Logical and bitwise not     | `!` `~`   | 2        |
| Dereference and address-of  | `*` `&`   | 2        |

---
## 3. Mathematical Operators

| Operator                 | Symbols     | Priority |
| ------------------------ | ----------- | -------- |
| Multiplicative operators | `*` `/` `%` | 3        |
| Additive operators       | `+` `-`     | 4         |

---
## 4. Bitwise Shift Operators

| Operator             | Symbols   | Priority |
| -------------------- | --------- | -------- |
| Shift left and right | `<<` `>>` | 5         |

---
## 5. Boolean Operators

| Operator             | Symbols           | Priority |
| -------------------- | ----------------- | -------- |
| Relational operators | `<` `>` `<=` `>=` | 6        |
| Equality operators   | `==` `!=`         | 7         |

---
## 6. Bitwise Operators

| Operator    | Symbols | Priority |
| ----------- | ------- | -------- |
| Bitwise and | `&`     | 8        |
| Bitwise xor | `^`     | 9        |
| Bitwise or  | `|`     | 10       |
| Bitwise and | `&&`    | 11       |
| Bitwise or  | `||`    | 12       |

---
## 6. Assignment operators

| Operator                 | Symbols                         | Priority |
| ------------------------ | ------------------------------- | -------- |
| Ternary                  | `?:`                            | 13       |
| Mathematical assignments | `=` `+=` `-=` `*=` `/=`         |  14      |
| Binary assignments       | `%=` `<<=` `>>=` `&=` `^=` `|= | 14         |

---
*related* [[Basic Types]]