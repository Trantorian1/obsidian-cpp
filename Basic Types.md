## Variable length integers

*These are types whose length in bytes has a defined minimum but can be platform dependent.*

> `int` for  example historically had a range of 2 bytes on older systems but is now commonly 4 bytes long, bringing it on par with `long`

| Type      | Bytes | Range          |
| --------- | ----- | -------------- |
| `short`     | ~2    | -2^15 to 2^15-1 |
| `int`       | ~4    | -2^31 to 2^31-1 |
| `long`      | ~4    | -2^31 to 2^31-1 |
| `long long` | ~8    | -2^64 to 2^64-1 | 

## Fixed length integers

> ⚠️ Using fixed-length integers requires you to include the `<cstdint>` header.

*These are types defined as part of the C++ standard library that have a fixed length in bytes, regardless of the platform.*

As much as possible, fixed-length integers should be used above variable length integers as this contractually guarantees the range of values you are working on, thus ensuring that any overflow or bitwise logic you have set up stays consistent across systems.

> Note that on platforms that do not support the length of the integer used, the code will  still work using the maximum integer length available under the hood but at a greater performance cost (ex: running 64-bit computations on a 42-bit system)

| Type         | Bytes | Range           |
| ------------ | ----- | --------------- |
| `int8_t`     | 1     | -2^8 to 2^8-1   |
| `uint8_t`    | 1     | 0 to 2^16-1     |
| `int16_t`    | 2     | -2^16 to 2^16-1 |
| ``uint16_t`` | 2     | 0 to 2^32-1     |
| `int32_t`    | 4     | -2^32 to 2^32-1 |
| `uint32_t`   | 4     | 0 to 2^64-1     |
| `int64_t`    | 8     | -2^64 to 2^64-1 |
| `uint64_t`   | 8     | 0 to 2^128-1    | 

## Floating point types

*These are types used to represent decimal numbers. `float` are faster with greater loss of precision, while `double` is slightly slower.*

> Note that such a difference in speed can be negligible, especially on modern systems. Choice of data type should therefore priorities precision as the main concern.

| Type          | Bytes | Range                |
| ------------- | ----- | -------------------- |
| `float`       | 4     | -3.4E38 to 3.4E38    |
| `double`      | 8     | -1.7E308 to 1.7E308  |
| `long double` | 8     | -3.4E932 to 1.7E4832 |

## Other basic types

> Note that `bool` as a memory type is particularly **not** memory-dense, and on systems  with limited memory or a high number of possibilities to encode, it is highly preferable to use fixed-length integers along with bitwise operations to encode state.

| Type   | Bytes | Range         |
| ------ | ----- | ------------- |
| `char` | 1     | -2^8 to 2^8-1 |
| `bool` | 1     | 0 or 1        | 

*related* [[Operator priority]]