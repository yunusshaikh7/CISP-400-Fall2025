# CISP 400 (Fall 2025) Assignments

This repository collects Yunus Shaikh's solutions for the Sacramento City College **CISP 400: Object Oriented Programming in C++** course. Each folder contains a self-contained assignment demonstrating a specific language concept or data structure.

## Repository layout
- **Assignment 1** – Introductory GradeBook exercises and Employee class demos. Source files live under `Assignment 1/ShaikhYA1CISP40025F/` and `Assignment 1/ShaikhYAD1CISP40025F/`.
- **Assignment 2** – Integer encryption utility tested via `CISP400V10A2.cpp` and `Encrypt.cpp` in `Assignment 2/ShaikhYA2CISP40025F/`.
- **Assignment 3** – Extended GradeBook that accepts user input and prints reports (`Assignment 3/ShaikhYA3CISP40025F/`).
- **Assignment 4** – Composition of `Date` and `Time` classes with tick-based advancement (`Assignment 4/ShaikhYA4CISP40025F/`).
- **Assignment 5** – Complex number class featuring stream insertion/extraction and arithmetic operator overloading (`Assignment 5/ShaikhYA5CISP40025F/`).
- **Assignment 6** – Function template `isEqualTo` exercised across primitive types plus `Complex` and `Date` objects (`Assignment 6/ShaikhYA6CISP40025F/`).
- **Assignment 7** – Quicksort implementation that generates and sorts vectors of random integers (`Assignment 7/ShaikhYA7CISP40025F/`).

## Building and running
Each assignment is isolated; compile from within the appropriate folder. A typical build command uses `g++` with C++17 support:

```bash
cd "Assignment 5/ShaikhYA5CISP40025F"
g++ -std=c++17 CISP400V10A5.cpp Complex.cpp -o assignment5
./assignment5
```

Most drivers include `system("PAUSE")` calls intended for Windows consoles; you can remove or comment them out when running on Unix-like systems.
