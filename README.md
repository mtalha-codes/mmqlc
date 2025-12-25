# MmQL - The Mathematical Query Language

> [!NOTE]
> Want to know what is planned about this project ?
> See [PLANS.md](DetailedDocs/PLANS.md).

**MmQL** is a very lightweight computational query language used to compute operations involving real and complex
numbers of arbitrary precision. The interpreter for MmQL is designed in C++20.

---

## What is MmQL ?

**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is an interpreted by **mmqli** and is also
a case-sensitive language.

**MmQL** is a lightweight, *cross-platform* query language tailored for mathematical computations. Designed for speed
and simplicity, **MmQL** allows users to write precise mathematical queries.
> [!NOTE]
>
> - Please note that **MmQL** is not a symbolic language. It does not leverage the use of CAS technologies like WolframAlpha or MapleSoft.
> - **MmQL** has simpler syntax because it does not construct an AST internally.

---

## What is mmqli ?

**mmqli** stands for **m**athe**m**atical **q**uery **l**anguage **i**nterpreter. It is
a **case-sensitive** interpreted query language with a minimalistic syntax, focused on mathematical operations.

## Key Features

- **Portable and Cross-Platform:** The language can run on various platforms by compiling its interpreter for your
  operating system.
- **Lightweight and Efficient:** Perfect for quick and resource-friendly computations.
- **Case-Sensitive Syntax:** Commands are interpreted based on their casing.
- Specializes in:
    - **Real Numbers**
    - **Complex Numbers**

**MmQL** is particularly suited for users who need fast, precise and accurate calculations without the overhead of complex
mathematical software.

---

## Why Choose MmQL?

**MmQL** provides a lightweight and flexible environment for mathematical queries, perfect for students and
professionals looking for:

- A **simple and efficient query language** for calculations involving complex numbers and real numbers of any arbitrary precision.
- A **cross-platform tool**, for any operating system (Windows, Linux and Mac).
-
    - **Windows** and **Linux** binaries will be available in the upcoming release.
-
    - For **macOS** however, the inner level CMakeLists.txt is configured, but you will have to compile it on your
      system.

With its clean syntax and custom interpreter, **MmQL** delivers a tailored solution for performing chunky mathematical
computations with precision.

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
git clone https://github.com/mtalha-codes/mmqli.git
# navigate to repo
cd mmqli
# download dependencies or libraries
vcpkg install 
# generate build scripts
mkdir build && cd build && cmake ..
# compile and navigate to build directory
make -j$(nproc)
# run the interpreter.
./mmqli
```

## Supported Queries

MmQL has mostly the same set of queries overloaded for both real and complex numbers of arbitrary precision. So it all differs by the calling convention.
Like for real numbers, you'd do `query 3,4` or `query 43+10` or whatever, but on the other hand,
for complex numbers you'd do `query 3+4i,5-6i` or `query 5e+10+6e-100i`.  

To know about queries, Read [Queries for Real Numbers](DetailedDocs/QUERIES_REAL_NUMBERS.md) and [Queries for Complex Numbers](DetailedDocs/QUERIES_COMPLEX_NUMBERS.md).

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
> Stacking multiple queries on a single line also causes errors.
> Nesting two or more queries or using inline comments will also throw errors.

### Examples of errors

- Compound Queries: `add 3,4 factoral 43`. This is strictly prohibited.
- Direct Nested Queries: `factorial add 3,4` , `inverse_sine sine 45`.
- - You can achieve nesting by storing result of each internal query in a variable. See [VARIABLES.md](DetailedDocs/VARIABLES.md) for more details.
- Inline Comments: `add 4,5 %% add two numbers`. [WIP]

---

## License

This project is protected under a custom flavor of AGPL v3+ license.
See [LICENSE](LICENSE) for more details.
