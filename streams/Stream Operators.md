**Stream operators** *in  C++ are special operators that allow to control input/output to the Console.*

## Toggleable Operators   

| Operator                  | Effect                                                                                                           |
| ------------------------- | ---------------------------------------------------------------------------------------------------------------- |
| `boolalpha` `noboolalpha` | switches between textual and numeric representation of booleans                                                  |
| `showbase` `noshowbase`   | whether prefix is used to indicate numeric base                                                                  |
| `showpoint` `noshowpoint` | whether decimal point is always included in floating-point representation                                        |
| `showpos` `noshowpos`     | whether the `+` sign used with non-negative numbers                                                              |
| `skipws` `noskipws`       | whether leading whitespace is skipped on input                                                                   |
| `uppercase` `nouppercase` | whether uppercase characters are used with some output formats, such as hexedecimal or scientific representation |
| `unitbuf` `nounitbuf`     | whether output is flushed after each operation                                                                   |                                                                  |

## General Operators

| Operator                  | Effect                                               |
| ------------------------- | ---------------------------------------------------- |
| `setfill`                 | sets the type of fill character to use               |
| `internal` `left` `right` | sets the placement of fill characters                |
| `ws`                      | discards leading whitespace from an input stream     |
| `ends`                    | outputs `\0`                                         |
| `endl`                    | outputs `\n`                                         |
| `flush`                   | flushes the output stream                            |

## Number Operators

| Operator                                       | Effect                                               |
| ---------------------------------------------- | ---------------------------------------------------- |
| `dec` `hex` `oct`                              | the base used for integer I/O                        |
| `setbase`                                      | sets a custom base for integer I/O                   |
| `fixed` `scientific` `hexfloat` `defaultfloat` | formatting used for floating-point I/O               |
| `setprecision`                                 | floating point precision                             |
| `setioflags`                                   | sets io base flags for more control over base output |
| `resetioflags`                                 | resets io base flags                                                     |
