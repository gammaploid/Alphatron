
# Alphatron

## Description

**Alphatron** is a simple educational virtual machine that interprets a custom assembly-like language. It simulates a memory array, an accumulator, and a program counter, supporting basic instructions like input, output, arithmetic, and control flow. For understandg of low-level programming opreations

## Features

- Reads and executes programs written in a numeric instruction format (`.alp` files)
- Supports input/output, arithmetic, memory operations, and jumps
- Easy to extend for more instructions

## Example Program

A sample [`inputplus2.alp`](inputplus2.alp):

```
1100 INPUT into ACC
2000 INC
2000 INC
1000 OUTPUT ACC
RUN
```

This program reads a number, increments it twice, and prints the result.

## Building

1. Ensure you have a C++ compiler (e.g., `g++`) installed.
2. Clone this repository and navigate to the project directory.
3. Compile using:

    ```sh
    g++ -std=c++11 -o alphatron main.cpp Alphatron.cpp
    ```

## Usage

Run the interpreter and provide your `.alp` program via standard input:

```sh
./alphatron < inputplus2.alp
```

You will be prompted for input if the program uses the `INPUT` instruction.

## File Structure

- [`Alphatron.cpp`](Alphatron.cpp) / [`Alphatron.h`](Alphatron.h): Core VM implementation
- [`main.cpp`](main.cpp): Entry point
- `*.alp`: Example programs

## License

This project is for educational purposes only.  
Starter files were provided by instructors at Flinders University.
Do not redistribute or use for commercial purposes.
