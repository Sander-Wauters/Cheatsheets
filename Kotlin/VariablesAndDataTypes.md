# Variables

Ways to declare variables.
```kt
var myVar // mutable variable
val myVal // immutable variable, acts like a const only at compile time
const val myConstVal // const only in combination with "val"
```
___
Variable initialization
```kt
val a: Int = 1 // immediate assignment
val b = 2 // 'Int' type is inferred

val c: Int // type required when no initializer is provided
c = 3      // deferred assignment
```
# Data types
Integer
```kt
val myByte: Byte     // Byte   | 8 bit  | min: -128   | max: 127
val myUByte: UByte   // UByte  | 8 bit  | min: 0      | max: 255B
val myShort: Short   // Short  | 16 bit | min: -32768 | max: 32767
val myUShort: UShort // UShort | 16 bit | min: 0      | max: 65535

val myInt: Int       // Int    | 32 bit | min: -2^31  | max: 2^31 - 1
val myUInt: UInt     // UInt   | 32 bit | min: 0      | max: 2^32-1

val myLong: Long     // Long   | 64 bit | min: -2^63  | max: 2^63-1
val myULong: ULong   // ULong  | 64 bit | min: 0      | max: 2^64-1
``` 
___
Floating-point
```kt
val myFloat: Float   // Float  | 32 bit | decimal digits: 6-7
val myDouble: Double // Double | 64 bit | decimal digits: 15-16
```
___
Literal constants
```kt
val myInt = 1_000_000 // underscores for readability
val myLong = 1L // "Long" is tagged with capital 'L'
val myHexBytes = 0xFF_EC_DE_5E // hexadecimals prefixed with "0x"
val myBytes = 0b11010010_01101001_10010100_10010010 // binary prefixed with "0b"
```
Note:<br>
unsigned integers can be tagged by `u` or `U`<br>
unsigned long can be tagged by `ul` or `UL`
___
Booleans
```kt
val myBool: Boolean // does not really need an explanation now does it
```
___
Characters
```kt
val myChar: Char 
```
Supported escape sequences:<br>
`\t`, `\b`, `\n`, `\'`, `\"`, `\\` and `\$`
___
Strings
```kt
val myString: String
``` 
Note:<br>
String concatenation can be dont with prefixing `$` to another variable
```kt
val myInt: Int = 5
val myString: String = "$myInt" // myString = "5"
```
___

















