# Queries For Calculation Involving Complex Numbers

## Arithmetic Operations

- **Addition**: $z_1+z_2$ --> `ADD a+bi,c+di`
- **Subtraction**: $z_1-z_2$ --> `SUBTRACT a+bi,c+di`
- **Multiplication**: $z_1\cdot z_2$ --> `MULTIPLY a+bi,c+di`
- **Division**: $\large \frac{z_1}{z_2}$ --> `DIVIDE a+bi,c+di`
- **Modulus**: $\left|z\right|$ --> `MODULUS a+bi`
- **Argument**: $\arg(z)$ --> `ARGUMENT a+bi`
- **Complex Conjugate**: $\overline{z}$ --> `CONJUGATE a+bi`

## Algebraic Operations

- **Exponentiation**: $z^n$ --> `POWER a+bi,n+0i`
- **Nth Root**: $\sqrt[n]{z}$ --> `ROOT a+bi,n+0i`
- **Complex Exponentiation**: ${z_1}^{z_2}$ --> `POWER a+bi,c+di`
- **Complex Root**: $\sqrt[z_1]{z_2}$ --> `ROOT a+bi,c+di`
- **Complex Natural Logarithm**: $\ln(z)$ --> `NATURAL_LOGARITHM a+bi`
- **Base $e$ Exponentiation**: $e^{z}$ --> `POWER_E a+bi`

## Trigonometric Operations

- **Sin(z)**: $\sin(z)$ --> `SINE a+bi`
- **Cos(z)**: $\cos(z)$ --> `COSINE a+bi`
- **Tan(z)**: $\tan(z)$ --> `TANGENT a+bi`
- **Cot(z)**: $\cot(z)$ --> `COTANGENT a+bi`
- **Sec(z)**: $\sec(z)$ --> `SECANT a+bi`
- **Csc(z)**: $\csc(z)$ --> `COSECANT a+bi`

## Inverse Trigonometric Operations

- **Arc Sin(z)**: $\sin^{-1}(z)$ --> `INVERSE_SINE a+bi`
- **Arc Cos(z)**: $\cos^{-1}(z)$ --> `INVERSE_COSINE a+bi`
- **Arc Tan(z)**: $\tan^{-1}(z)$ --> `INVERSE_TANGENT a+bi`
- **Arc Cot(z)**: $\cot^{-1}(z)$ --> `INVERSE_COTANGENT a+bi`
- **Arc Sec(z)**: $\sec^{-1}(z)$ --> `INVERSE_SECANT a+bi`
- **Arc Csc(z)**: $\csc^{-1}(z)$ --> `INVERSE_COSECANT a+bi`

## Hyperbolic Trigonometric Operations

- **Sinh(z)**: $\sinh(z)$  --> `HYP_SINE a+bi`
- **Cosh(z)**: $\cosh(z)$ --> `HYP_COSINE a+bi`
- **Tanh(z)**: $\tanh(z)$ --> `HYP_TANGENT a+bi`
- **Coth**: $\coth(z)$ --> `HYP_COTANGENT a+bi`
- **Sech**: $\text{sech}(z)$ --> `HYP_SECANT a+bi`
- **Csch**: $\text{csch}(z)$ --> `HYP_COSECANT a+bi`

## Inverse Hyperbolic Trigonometric Operations

- **Arc Sinh(z)**: $\sinh^{-1}(z)$ --> `INVERSE_HYP_SINE a+bi`
- **Arc Cosh(z)**: $\cosh^{-1}(z)$ --> `INVERSE_HYP_COSINE a+bi`
- **Arc Tanh(z)**: $\tanh^{-1}(z)$ --> `INVERSE_HYP_TANGENT a+bi`
- **Arc Coth**: $\coth(z)$ --> `INVERSE_HYP_COTANGENT a+bi`
- **Arc Sech**: $\text{sech}(z)$ --> `INVERSE_HYP_SECANT a+bi`
- **Arc Csch**: $\text{csch}(z)$ --> `INVERSE_HYP_COSECANT a+bi`

## Want to have more control over queries with the help of variables ?

Read [**this**](VARIABLES.md).