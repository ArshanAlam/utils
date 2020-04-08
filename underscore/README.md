# Underscore Calculator ( ' _ ' )

Underscore_Calculator is a command line interface (CLI) calculator for basic
arithmetics (+, -, \*, /), using double-precision floating point numbers.


**NOTE:** The asterisk ( \* ) symbol is 'NOT' used for multiplication because it conflicts with BASH syntax, where executing \*, serves as a wildcard, hence this calculator uses the 'x' character for multiplication.

To compile Underscore execute `gcc calc.c -o _`

##### Example of using Underscore:

Executing:
```
_ + 1 -2 3.14159265359 $(_ - 2 $(_ / 8 2) $(_ x 3 2.0) 2)
```

should yield **-7.858407**

## Prefix Notation

Notice the above example uses prefix notation.

So, the command `_ - 2 1` is (2 - 1) and something more complex: `_ - 2 1 3 2` is actually [ 2 - 1 - 3 - 2]

## Export Environment Variable

If executing an underscore command gives a *command not found* message, then
add the directory that contains the underscore executable to the `$PATH` environment variable: `export PATH=.:$PATH`

**Lastly**, Underscore does not, by default, read from *stdin*, thus (currently) the only way to use underscore is through command line arguments.
