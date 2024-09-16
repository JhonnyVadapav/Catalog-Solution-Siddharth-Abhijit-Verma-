# Lagrange Interpolation - C++ Implementation

## Overview

This project provides a C++ implementation of Lagrange interpolation to find the constant term of a polynomial given a set of points. Specifically, it calculates the polynomial's value at \( x = 0 \), which corresponds to the constant term. This method is useful in various fields including cryptography and polynomial fitting.

## Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler installed. Options include GCC, Clang, or MSVC.
- **C++ Standard**: This project uses C++11 or later.

## Installation

1. **Clone the Repository**

   Clone this repository to your local machine using Git:

   ```bash
   git clone https://github.com/your-username/lagrange-interpolation.git

2. **RUN**
   Run the commands:
   ```cpp
   ./solution
    solution.exe

##TEST CASES
1. 
  ```bash
  map<string, map<string, string>> test_case = {
      {"keys", {{"n", "9"}, {"k", "6"}}},
      {"1", {{"base", "10"}, {"value", "28735619723837"}}},
      {"2", {{"base", "16"}, {"value", "1A228867F0CA"}}},
      {"3", {{"base", "12"}, {"value", "32811A4AA0B7B"}}},
      {"4", {{"base", "11"}, {"value", "917978721331A"}}},
      {"5", {{"base", "16"}, {"value", "1A22886782E1"}}},
      {"6", {{"base", "10"}, {"value", "28735619654702"}}},
      {"7", {{"base", "14"}, {"value", "71AB5070CC4B"}}},
      {"8", {{"base", "9"}, {"value", "122662581541670"}}},
      {"9", {{"base", "8"}, {"value", "642121030037605"}}}
  };
 OUTPUT: 28735619723864
```
```OUTPUT
2873561972386
```
```bash
{
    "keys": {
        "n": 4,
        "k": 3
    },
    "1": {
        "base": "10",
        "value": "4"
    },
    "2": {
        "base": "2",
        "value": "111"
    },
    "3": {
        "base": "10",
        "value": "12"
    },
    "6": {
        "base": "4",
        "value": "213"
    }
}
```
```output
3
```
