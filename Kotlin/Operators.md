# Operators

Standard arithmetic:<br>
`+`, `-`, `*`, `/`, `%` and `..`

```kt
a + b  // or a.plus(b)
a - b  // or a.minus(b)
a * b  // or a.times(b)
a / b  // or a.div(b)
a % b  // or a.rem(b)
a .. b // or a.rangeTo(b)
```
___
Augmented assignment:<br>
```kt
a += b // or a.plusAssign(b)
a -= b // or a.minusAssign(b)
a *= b // or a.timeAssign(b)
a /= b // or a.divAssign(b)
a %= b // or a.remAssign(b)
```
___
Increments and decrements:<br>
```kt
a++ // or a.inc()
++a // or a.inc()
a-- // or a.dec()
--a // or a.dec()
```
___
Equality and inequality:<br>
```kt
a == b // or a?.equals(b) ?: (b === null)
a != b // or !(a?.equals(b) ?: (b === null))
```
Note:<br>
`a === b` and `a !== b` are used to compare the reference of two variables.
___
Comparison operators:<br>
```kt
a > b  // or a.compareTo(b) > 0
a < b  // or a.compareTo(b) < 0
a >= b // or a.compareTo(b) >= 0
a <= b // or a.compareTo(b) <= 0
```
___
Indexed access operator:<br>
```kt
a[i]             // or a.get(i)
a[i, j]          // or a.get(i, j)
a[i_1, ..., i_n] // or a.get(i_1, ..., i_n)

a[i] = b             // or a.set(i, b)
a[i, j] = b          // or a.set(i, j, b)
a[i_1, ..., i_n] = b // or a.set(i_1, ..., i_n, b)
```
___
Unary operators:<br>
```kt
+a // or a.unaryPlus()
-a // or a.unaryMinus()
!a // or a.not()
```
___
Bitwise operations:<br>
```kt
val x = (1 shl 2)  // 'shl()' signed shift left
val x = (1 shr 2)  // 'shr()' signed shift right
val x = (1 ushr 2) // 'ushr()' unsigned shift right
val x = (1 and 2)  // 'and()' bitwise and
val x = (1 or 2)   // 'or()' bitwise or
val x = (1 xor 2)  // 'xor()' bitwise xor
val x = inv(5)     // 'inv()' bitwise inversion
```
Note:<br>
Only applicable for `Int`and `Long`.
___
