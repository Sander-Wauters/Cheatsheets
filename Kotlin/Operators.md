# Operators

Standard arithmetic:<br>
`+`, `-`, `*`, `/`, `%` and `..`

`a + b` or `a.plus(b)`<br>
`a - b` or `a.minus(b)`<br>
`a * b` or `a.times(b)`<br>
`a / b` or `a.div(b)`<br>
`a % b` or `a.rem(b)`<br>
`a .. b` or `a.rangeTo(b)`<br>
___
Unary operators:<br>
`+a` or `a.unaryPlus()`
`-a` or `a.unaryMinus()`
`!a` or `a.not()`
___
Bitwise operations:<br>
```kt
val x = (1 shl 2)  // 'shl' signed shift left
val x = (1 shr 2)  // 'shr' signed shift right
val x = (1 ushr 2) // 'ushr' unsigned shift right
val x = (1 and 2)  // 'and' bitwise and
val x = (1 or 2)   // 'or' bitwise or
val x = (1 xor 2)  // 'xor' bitwise xor
val x = inv(5)     // 'inv' bitwise inversion
```
Note:<br>
Only applicable for `Int`and `Long`.
___
