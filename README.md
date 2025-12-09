<!--toc:start-->
- [MmQL - The Mathematical Query Language](#mmql-the-mathematical-query-language)
  - [What is MmQL ?](#what-is-mmql)
  - [What is MmQLC ?](#what-is-mmqlc)
  - [Key Features](#key-features)
  - [Why Choose MmQL?](#why-choose-mmql)
  - [Dependencies](#dependencies)
  - [Setting Up The Environment for Building From Source](#setting-up-the-environment-for-building-from-source)
  - [Supported Queries](#supported-queries)
    - [[Queries For Calculations Involving Real Numbers](DetailedDocs/REAL_NUMBERS.md)](#queries-for-calculations-involving-real-numbersdetaileddocsrealnumbersmd)
    - [[Queries For Calculations Involving Complex Numbers](DetailedDocs/COMPLEX_NUMBERS.md)](#queries-for-calculations-involving-complex-numbersdetaileddocscomplexnumbersmd)
  - [Comments in MmQL](#comments-in-mmql)
  - [Possible Errors](#possible-errors)
    - [Examples of errors](#examples-of-errors)
  - [Our Intentions Regarding this Project](#our-intentions-regarding-this-project)
  - [License](#license)
    - [Key Restrictions](#key-restrictions)
<!--toc:end-->

# MmQL - The Mathematical Query Language

> [!NOTE]
> ***I have stopped working on this project and will be rewritten in Rust (After I Learn Rust) and it will have more killer features (Inshallah).***

**MmQL** is a very lightweight computational query language used to compute operations involving real and complex numbers (the queries are interpreted by **MmQLC**) developed in **C++20**.

---

## What is MmQL ?

**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is an interpreted language as well as a case-sensitive **where uppercase and  lowercase matters**. The interpreter (**MmQLC**) is a custom and yet a very simple interpreter. Techniques like Tokenization and Parsing are used by **MmQLC**.

**MmQL** is a lightweight, *cross-platform* query language tailored for mathematical computations. Designed for speed and simplicity, **MmQL** allows users to write precise mathematical queries.
> [!NOTE]
>
> - Please note that **MmQL** is not a symbolic language, and it does not use CAS (Computer Algebra Systems)
> - **MmQL** is a unique because it does not use an **Abstract Syntax Tree**.

---

## What is MmQLC ?  

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler (although this is an interpreter 😁). It is a **case-sensitive** interpreted query language with a minimalistic syntax, focused on mathematical operations.  

## Key Features  

- **Portable and Cross-Platform:** The language can run on various platforms by compiling its interpreter for your operating system.  
- **Lightweight and Efficient:** Perfect for quick and resource-friendly computations.  
- **Case-Sensitive Syntax:** Commands are interpreted based on their casing.  
- Specializes in:  
  - **Real Numbers**  
  - **Complex Numbers**  

**MmQL** is particularly suited for users who need fast, precise calculations without the overhead of complex mathematical software.

---

## Why Choose MmQL?  

**MmQL** provides a lightweight and flexible environment for mathematical queries, perfect for students and professionals looking for:  

- A **simple and efficient query language** for real and complex number calculations.  
- A **cross-platform tool**, for any operating system (Windows, Linux and Mac) via compilation.  

With its clean syntax and custom interpreter, **MmQL** delivers a tailored solution for performing mathematical computations. Compile **MmQLC** on your preferred OS, and you're ready to handle your queries with speed and precision!

---

## Dependencies

This project has the following dependencies:

- [X] **components: {multiprecision,math}** from Boost C++ Library
- [X] GNU GMP Library
- [X] MPFR Library
- [X] FMT Library

This project also have the following build dependencies:

- **gcc** or **clang** complete toolchain. **clangd** is recommended but not necessary.
- **cmake** should be installed and properly configured.
- **vcpkg** should be installed and properly configured as per your toolchain.
- **vcpkg**  should be exposed to **cmake** via ***VCPKG_ROOT*** environment variable.

---

## Setting Up The Environment for Building From Source  
>
> [!WARNING]
> Only 64 bit x86 and ARM architectures are supported. We don't plan to support other architectures.

Building from source is dead simple, just launch your default terminal.

```bash
# Clone this repo 
git clone https://github.com/mtalha-codes/mmqlc.git
# navigate to repo
cd mmqlc
# download dependencies or libraries
vcpkg install 
# generate build scripts
cmake .
# compile and navigate to build directory
make -j$(nproc) && cd build
# run the interpreter.
./mmqlc --live
```

## Supported Queries

Following types of queries are supported by **MmQL**.

- ### [Queries For Calculations Involving Real Numbers](DetailedDocs/REAL_NUMBERS.md)

- ### [Queries For Calculations Involving Complex Numbers](DetailedDocs/COMPLEX_NUMBERS.md)

---

## Comments in MmQL

The MmQL language only support single-line comments.

**Comment Declaration**:
Comments looks like this

- `%% Comment`

---

## Possible Errors
>
> [!CAUTION]
Compound queries or stacking multiple queries on a single line may cause errors.
Nesting two or more queries or using inline comments will also throw errors.

### Examples of errors

- Compound Queries: `ADD 3,4 FACTORIAL 43`. This is strictly prohibited.
- Direct Nested Queries: `FACTORIAL ADD 3,4` , `INVERSE_SINE SINE 45`. Can be tackled via variables.
- Inline Comments: `ADD 4,5 %% add two numbers`. Work In Progress.

---

## Our Intentions Regarding this Project

[You can read about it here.](DetailedDocs/PLANS.md)

## License

This project is protected under a custom license. You are permitted to clone this repository for learning purposes only.

### Key Restrictions

1. Forking and redistribution without permission is prohibited.
2. The code may not be used for your academic submissions (e.g., final year projects, assignments) or included in resumes/portfolios except the owner(which is ME).
3. Contributions are allowed only with prior written permission. Email **<muhammadtalha.quant@gmail.com>**

[For more details on license, click to read it](./LICENSE)
