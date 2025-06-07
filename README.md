# 🧮 Push Swap

This was my first bigger C project, and I’m incredibly proud of how it turned out. From designing my own data structures and logic to debugging and optimizing move counts — this project gave me a real taste of low-level programming, and it’s one I’ll always remember fondly.

Push Swap taught me how to think in stacks, solve problems in steps, and debug with lldb. 💪

**Push Swap** is a sorting algorithm visualizer and logic-based challenge completed as part of the 42 coding curriculum. The goal of the project is to sort a stack of integers with the least number of operations using only two stacks (`a` and `b`) and a restricted set of instructions.

This implementation follows a smart rotation and scoring strategy inspired by [this article by Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a), which focuses on minimizing the number of moves based on calculated costs and optimal rotation directions.

---

## 📌 Project Overview

You're given a sequence of integers (no duplicates), and your task is to sort them using only a limited set of stack operations:

### ✅ Allowed Operations

| Operation | Description                        |
|----------|------------------------------------|
| `sa`, `sb`, `ss` | Swap top two elements of stack `a`, `b`, or both |
| `pa`, `pb`       | Push the top element from one stack to the other |
| `ra`, `rb`, `rr` | Rotate stack up (first becomes last) |
| `rra`, `rrb`, `rrr` | Reverse rotate (last becomes first) |

The objective is to output a **sequence of these commands** that sorts the stack using the **fewest possible moves**.

---

## 🧠 Strategy & Algorithm

This implementation uses:

- 🧮 **Cost scoring**: For each number in stack `b`, the program calculates how many moves are needed to place it in the correct position in stack `a`.
- 🔁 **Smart rotation**: Chooses between `ra/rra` and `rb/rrb` depending on which combination results in fewer total moves.
- 🧩 **Chunking**: For large input sizes, elements are divided into value-based chunks that are progressively pushed to stack `b` and reintegrated.
- 🧼 **Input validation**: Handles non-integer input, duplicates, and integer overflows.

Inspired by Jamie Dawson’s scoring technique, this version computes optimal positions in both stacks before deciding the best combined rotation strategy.

---

## 🛠️ Build & Run

### Requirements

- A C compiler (`clang` or `gcc`)
- Make

### Build

```bash
make
chmod +x int_generator.sh
chmod +x checker_Mac

### Run
./bin/push_swap 3 2 5 1 4
or
./bin/push_swap "3 2 5 1 4"

The program outputs the operations to standard output:
pb
ra
pb
sa
pa
pa

Use with 42's checker binary to verify the sorting:
ARG="3 2 5 1 4"
./bin/push_swap $ARG | ./checker $ARG

You can use my int_generator bash script currently set at 500 random integers.
./int_generator.sh
OK
    6642


