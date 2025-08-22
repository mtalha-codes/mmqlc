# MmQL - The Mathematical Query Language 

> [!NOTE]
> ***I have stopped working on this project and will be rewritten in Rust and it will have more killer features (Inshallah), After my other [project](https://github.com/mtalha-codes/roobs-kitchen-rs) (through which I am gonna learn Practical Rust), which is also rewrite of my another C++ [project](https://github.com/mtalha-codes/roobs-kitchen-cpp).***

**MmQL** is a very lightweight computational query language used to compute operations involving real and complex numbers (the queries are interpreted by **MmQLC**) developed purely in **C++23**.

---

## What is MmQL ?
**MmQL** is an acronym that stands for **M**athe**m**atical **Q**uery **L**anguage. It is an interpreted language as well as a case-sensitive **where uppercase and  lowercase matters**. The interpreter (**MmQLC**) is a custom and yet a very simple interpreter. Techniques like Tokenization and Parsing are used by **MmQLC**.

**MmQL** is a lightweight, *cross-platform* query language tailored for mathematical computations. Designed for speed and simplicity, **MmQL** allows users to write precise mathematical queries.
> [!NOTE]
> - Please note that **MmQL** is not a symbolic language, and it does not use CAS (Computer Algebra Systems)
> - **MmQL** is a unique because it does not use an **Abstract Syntax Tree**.

---

# What is MmQLC ?  

**MmQLC** stands for **M**athe**m**atical **Q**uery **L**anguage **C**ompiler (although this is an interpreter 😁). It is a **case-sensitive** interpreted query language with a minimalistic syntax, focused on mathematical operations.  

### Key Features:  
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
This project depends upon the following libraries
They are as follows:
- [ ] Boost C++ Library
- [ ] GNU GMP Library 
- [ ] MPFR Library 
- [ ] FMT Library

---

## Setting Up The Environment for Building From Source  
### Windows:  
> [!IMPORTANT]  
> - [X] **Download And Install MSYS2**. Click [**this**](https://github.com/msys2/msys2-installer/releases/download/2025-02-21/msys2-x86_64-20250221.exe) to start downloading !.
> - [X] After Installation, A **UCRT64** Environment will open up for you, Enter the following commands one by one.
> ```bash  
> pacman -Syu # Updates the package database for latest metadata.  
> pacman -S mingw-w64-ucrt-x86_64-gcc # Install Latest version of GNU GCC Compiler.
> pacman -S mingw-w64-ucrt-x86_64-fmt # Installs FMT.
> pacman -S mingw-w64-ucrt-x86_64-boost # Installs Boost.  
> ```  
> - [X] Edit both top-level and inner `CMakeLists.txt` files to match your library paths.  
> - [X] Install `scoop`:  
> ```powershell  
> Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser  
> Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression  
> ```  
> - [X] Install `cmake` via `scoop`:  
> ```powershell  
> scoop install main/cmake  
> ```  
> - [X] Install `make` via `scoop`:  
> ```powershell  
> scoop install main/make  
> ```  

🎉 Congratulations! 🎉  
You have set up the environment for building **MmQLC** for Windows.  

---

### MacOS:  
> [!IMPORTANT]  
> - [X] **Install Homebrew**. Watch this [guide](https://brew.sh/) for installation instructions.  
> - [X] **Don't close your terminal yet! Paste these commands one by one:**  
> ```bash  
> brew update # Updates the package database for latest metadata.  
> brew install gcc # Installs GCC compiler.  
> brew install gmp mpfr fmt boost cmake make # Installs all required libraries and tools.  
> ```  
> - [X] Add the base **dir** of `boost` as a new **environment variable(if needed)**.  
> - [X] Edit both top-level and inner `CMakeLists.txt` files to match your library paths.  

🎉 Congratulations! 🎉  
You have set up the environment for building **MmQLC** for macOS.  

---

### Linux(Arch Linux):  
> [!IMPORTANT]  
> - [X] **Install dependencies**. Open your terminal and paste these commands one by one:  
> ```bash  
> sudo pacman -Sy # Update Package Database
> sudo -S boost mpfr fmt gmp. # Install Dependencies.  
> ```
> - [X] Edit both top-level and inner `CMakeLists.txt` files to match your library paths.  

🎉 Congratulations! 🎉  
You have set up the environment for building **MmQLC** for Linux.  

---

### Step-By-Step Easy Building Procedure (Same on All OS):
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

---

## Using the MmQL Language For Calculations

**MmQL**  is pretty simple to use , just download either the installer(**Windows**) from **Release** section or the source code **(If you want to build it for yourself.)(Other than Windows)**
- First of all write queries by using text editor.
- Now for generation of answer file then you should run **MmQLC.exe** with special command line **arguments** defined for **MmQLC** The method for generating answer file from a query file is explained [**Here.**](DetailedDocs/MMQLC_USE.md)
- To view or see the answers, open the **.ans** in any text editor.

>- **MmQLC v2.2+** also includes a sophisticated **REPL** mode if you want direct calculations.

 > [!NOTE]
 > - Consider adding **MmQLC.exe** to your environment variables for running it from the shell directly. Click  [**Here**](https://www.youtube.com/watch?v=z84UIZy_qgE) if you don't know how to do it.


>[!NOTE]
> There will be no installer in the future. Building from source is recommended.
---

## Supported Queries
Following types of queries are supported by **MmQL**.
- ### Queries For Calculations Involving Real Numbers. Click [**Here**](DetailedDocs/REAL_NUMBERS.md) to see.
- ### Queries For Calculations Involving Complex Numbers. Click [**Here**](DetailedDocs/COMPLEX_NUMBERS.md) to see.

---

## Comments in MmQL
The MmQL language only support single-line comments.

**Comment Declaration**: 
Comments looks like this
- `%% Comment`

---

## Possible Errors
> [!CAUTION]
Compound queries or stacking multiple queries on a single line may cause errors.
Nesting two or more queries or using inline comments will also throw errors.
### Examples of errors:
- Compound Queries: `ADD 3,4 FACTORIAL 43`. This is strictly prohibited.
- Direct Nested Queries: `FACTORIAL ADD 3,4` , `INVERSE_SINE SINE 45`. Can be tackled via variables.
- Inline Comments: `ADD 4,5 %% add two numbers`. Work In Progress.

---

## Message !:
Active development has been stopped from now till my 12th class exam ends.... Development will be continued somewhere after 20th July 2025, after I qualify the GIKI Entrance Test with Fully Funded Scholarship (Please Pray For Me 🤲 😢).
However, the codebase will be constantly reviewed and optimizations and refactorings will be done when needed.



## Our Intentions Regarding this Project
You can read about it [**here**](DetailedDocs/PLANS.md)

## License
This project is protected under a custom license. You are permitted to clone this repository for learning purposes only. 

### Key Restrictions:
1. Forking, redistribution, or creating derivative works is prohibited.
2. The code may not be used for your academic submissions (e.g., final year projects, assignments) or included in resumes/portfolios.
3. Contributions are allowed only with prior written permission. Email **khankkhan123apsacs@gmail.com** if you'd like to contribute.

For more details, see the [LICENSE](LICENSE) file.
---
