# Queries For Calculations Involving Real Numbers

## Arithmetic Operations

- **Addition**: $a+b$ --> `ADD a,b`
- **Subtraction**: $a-b$ --> `SUBTRACT a,b`
- **Multiplication**: $a\times b$ --> `MUTIPLY a,b`
- **Division**: $a÷b$ --> `DIVIDE a,b`
- **Exponentiation**: $a^b$ --> `POWER a,b`
- **Root**: $\sqrt[n]{a}$ --> `ROOT a,n`
- **Modulus**: $a \ mod\ b$ --> `MOD a,b`
- **Ceiling**: $\lceil a \rceil$ --> `CEILING a`
- **Floor**: $\lfloor a \rfloor$ --> `FLOOR a`

## Combinatorial Operations

- **Factorial**:   $n!$ --> `FACTORIAL n` *such that* $n\in (-1,44787927]$
- **Permutation**: $P^n_r$ --> `PERMUTATION n,r`
- **Combination**: $C^n_r$ --> `COMBINATION n,r`

## Logarithmic Operations

- **General Logarithm**: $\log_b{a}$ --> `LOGARITHM a,b`
- **Common Logarithm**: $\log_{10}{a}$ --> `COMMON_LOGARITHM a`
- **Natural Logarithm**: $\ln{a}$ --> `NATURAL_LOGARITHM a`
- **Binary Logarithm**: $\log_2{a}$ --> `BINARY_LOGARITHM a`

## Trigonometric Operations

- **Sin**: $\sin(x)$ where x is degrees of the angle --> `SINE x`
- **Cos**: $\cos(x)$ where x is degrees of the angle --> `COSINE x`
- **Tan**: $\tan(x)$ where x is degrees of the angle --> `TANGENT x`
- **Cot**: $\cot(x)$ where x is degrees of the angle --> `COTANGENT x`
- **Sec**: $\sec(x)$ where x is degrees of the angle --> `SECANT x`
- **Csc**: $\csc(x)$ where x is degrees of the angle --> `COSECANT x`

## Inverse Trigonometric Operations

- **Arc Sin**: $\sin^{-1}(x)$ where x is the parameter of function --> `INVERSE_SINE x`
- **Arc Cos**: $\cos^{-1}(x)$ where x is the parameter of function --> `INVERSE_COSINE x`
- **Arc Tan**: $\tan^{-1}(x)$ where x is the parameter of function --> `INVERSE_TANGENT x`
- **Arc Cot**: $\cot^{-1}(x)$ where x is the parameter of function --> `INVERSE_COTANGENT x`
- **Arc Sec**: $\sec^{-1}(x)$ where x is the parameter of function --> `INVERSE_SECANT x`
- **Arc Csc**: $\csc^{-1}(x)$ where x is the parameter of function --> `INVERSE_COSECANT x`

## Hyperbolic Trigonometric Operations

- **Sinh**: $\sinh(x)$ where x is the parameter of function --> `HYP_SINE x`
- **Cosh**: $\cosh(x)$ where x is the parameter of function --> `HYP_COSINE x`
- **Tanh**: $\tanh(x)$ where x is the parameter of function --> `HYP_TANGENT x`
- **Coth**: $\coth(x)$ where x is the parameter of function --> `HYP_COTANGENT x`
- **Sech**: $\text{sech}(x)$ where x is the parameter of function --> `HYP_SECANT x`
- **Csch**: $\text{csch}(x)$ where x is the parameter of function --> `HYP_COSECANT x`

## Inverse Hyperbolic Trigonometric Operations

- **Arc Sinh**: $\sinh^{-1}(x)$ where x is the parameter of function --> `INVERSE_HYP_SINE x`
- **Arc Cosh**: $\cosh^{-1}(x)$ where x is the parameter of function --> `INVERSE_HYP_COSINE x`
- **Arc Tanh**: $\tanh^{-1}(x)$ where x is the parameter of function --> `INVERSE_HYP_TANGENT x`
- **Arc Coth**: $\coth^{-1}(x)$ where x is the parameter of function --> `INVERSE_HYP_COTANGENT x`
- **Arc Sech**: $\text{sech}^{-1}(x)$ where x is the parameter of function --> `INVERSE_HYP_SECANT x`
- **Arc Csch**: $\text{csch}^{-1}(x)$ where x is the parameter of function --> `INVERSE_HYP_COSECANT x`

## Want to have more control over queries with the help of variables ?

Read [**this**](VARIABLES.md).