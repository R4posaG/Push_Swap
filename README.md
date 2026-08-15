# *This project has been created as part of the 42 curriculum by hjacinto, ajoao.*

# Push_swap

## Description

The **push_swap** project consists of creating a highly efficient sorting algorithm that sorts data on a stack using a limited set of instructions, aiming for the lowest possible number of operations.

The program works with two stacks (`stack_a` and `stack_b`) and a restricted set of stack manipulation rules. It evaluates the degree of disorder of the input data and selects an optimized strategy to perform the sort.

This project provides a deeper understanding of:

* Data structures (doubly circular linked lists) and stack management;
* Algorithm complexity analysis ($O(n^2)$, $O(n\sqrt{n})$, and $O(n \log n)$);
* Sorting strategies (Selection Sort, Chunks/Moving Window, LSD Radix Sort);
* Adaptive algorithm selection based on structural disorder;
* Parsing, input validation, and flag handling in C.

---

### Features & Strategies

The program features benchmarking capabilities and four explicit sorting strategies that can be executed directly or selected adaptively:

| Strategy | Flag | Complexity | Description / Algorithm |
| --- | --- | --- | --- |
| **Simple** | `--simple` | $O(n^2)$ | Selection/Extraction sort: repeatedly moves the minimum element to Stack B, sorts the remaining 3 in Stack A, and pushes back. |
| **Medium** | `--medium` | $O(n\sqrt{n})$ | Chunks / Moving Window algorithm: calculates chunk sizes using $\sqrt{N}$, pushes ranges to Stack B, and retrieves them in descending order. |
| **Complex** | `--complex` | $O(n \log n)$ | Bitwise LSD Radix Sort: assigns normalized indices to nodes and processes bit positions across all values. |
| **Adaptive** | `--adaptive` | Dynamic | Automatically measures disorder ratio ($D$) and routes execution: $D < 0.2 \to O(n^2)$, $0.2 \le D < 0.5 \to O(n\sqrt{n})$, $D \ge 0.5 \to O(n \log n)$. |

Additional features:
* **Benchmark mode (`--bench`)**: Displays the disorder percentage, strategy used, total operations count, and breakdown per operation.

---

### Operations

The program manipulates stacks using only the following 11 instructions:

| Command | Name | Description | Exception / Rule |
| :---: | :--- | :--- | :--- |
| **`sa`** | Swap A | Swap the first two elements at the top of stack A. | Does nothing if 1 or 0 elements. |
| **`sb`** | Swap B | Swap the first two elements at the top of stack B. | Does nothing if 1 or 0 elements. |
| **`ss`** | Swap A & B | Execute `sa` and `sb` at the same time. | Subject to individual stack rules. |
| **`pa`** | Push A | Take the first element of B and put it at the top of A. | Does nothing if stack B is empty. |
| **`pb`** | Push B | Take the first element of A and put it at the top of B. | Does nothing if stack A is empty. |
| **`ra`** | Rotate A | Shift up all elements of stack A by one position. | The first element becomes the last. |
| **`rb`** | Rotate B | Shift up all elements of stack B by one position. | The first element becomes the last. |
| **`rr`** | Rotate A & B | Execute `ra` and `rb` at the same time. | Affects both stacks simultaneously. |
| **`rra`** | Reverse Rotate A | Shift down all elements of stack A by one position. | The last element becomes the first. |
| **`rrb`** | Reverse Rotate B | Shift down all elements of stack B by one position. | The last element becomes the first. |
| **`rrr`** | Reverse Rotate A & B | Execute `rra` and `rrb` at the same time. | Affects both stacks simultaneously. |

---

### Project Structure

| File / Directory | Description |
| --- | --- |
| `src/main.c` | Entry point, program initialization, and argument handling pipeline |
| `src/parsing.c` | Input validation, handling quoted strings, duplicate checks, and integer bounds |
| `src/flags.c` | Parsing CLI flags (`--bench`, `--simple`, `--medium`, `--complex`, `--adaptive`) |
| `src/stack_utils.c` | Creation, addition, duplicate checks, sorted state verification, and memory freeing |
| `src/indexing.c` | Index assignment to stack nodes ($0$ to $N-1$) for normalized processing |
| `src/check_disorder.c` | Calculates the inversion ratio / structural disorder rate of Stack A |
| `src/strategy.c` | Router for small stacks ($\\le 5$) and adaptive/explicit strategy assignment |
| `src/operations/` | Implementation of stack operations (`push`, `swap`, `rotate`, `rev_rotate`, `register`) |
| `src/algorithms/` | Implementation of sorting algorithms (`sort_small`, `sort_simple`, `sort_medium`, `sort_complex`) |
| `src/benchmark.c` | Benchmark printing formatting for operation counts and disorder rates |
| `push_swap.h` | Prototypes, structures (`t_stack`, `t_program`), enums, and inclusions |
| `Makefile` | Build compilation rules (`all`, `clean`, `fclean`, `re`) |

Example directory structure:

```text
push_swap/
├── push_swap.h
├── Makefile
├── libft/
└── src/
    ├── main.c
    ├── parsing.c
    ├── flags.c
    ├── indexing.c
    ├── stack_utils.c
    ├── utils.c
    ├── check_disorder.c
    ├── strategy.c
    ├── benchmark.c
    ├── benchmark_utils.c
    ├── operations/
    │   ├── push.c
    │   ├── swap.c
    │   ├── rotate.c
    │   ├── rev_rotate.c
    │   └── register.c
    └── algorithms/
        ├── algorithms_utils.c
        ├── sort_small.c
        ├── sort_simple.c
        ├── sort_medium.c
        └── sort_complex.c
```

---

## Instructions

### Requirements

* GCC / Clang
* Linux / macOS
* Standard C library
* 42 Norm compliant code (Norminette)

### Compilation

Compile the project using the provided Makefile:

```bash
make        # Compiles libft and push_swap with -Wall -Wextra -Werror
make clean  # Removes object files
make fclean # Removes object files and the push_swap binary
make re     # Executes fclean and rebuilds everything
```

### Usage

Run `push_swap` by passing a list of integers as individual arguments or enclosed in a string:

```bash
# Basic usage
./push_swap 2 1 3 6 5 8

# Usage with a quoted string
./push_swap "4 67 3 87 23"

# Benchmark mode
./push_swap --bench 3 1 2

# Specifying explicit strategies
./push_swap --simple "5 4 3 2 1"
./push_swap --bench --medium 9 4 2 1 7 5
./push_swap --complex 10 9 8 7 6 5 4 3 2 1
```

---

### Testing

This project has been thoroughly tested against edge cases, stress tests, and standard community tools.

Common test cases handled:

* **Error handling**: Inputs with duplicates, non-numeric values, values exceeding `INT_MAX`/`INT_MIN`, empty strings.
* **Already sorted lists**: Outputs 0 operations.
* **Small sets**: 2, 3, 4, and 5 numbers sorted within optimal operation limits.
* **Large sets**: 100 and 500 numbers validated for operation efficiency across medium and complex strategies.

---

## Resources

### Documentation and References

* 42 push_swap subject
* Sorting Algorithms & Computational Complexity ($O(n^2)$, $O(n\sqrt{n})$, $O(n \log n)$)
* Radix Sort and Bitwise Operations in C
* Doubly Circular Linked Lists in C

## AI Usage

Artificial Intelligence tools were used exclusively as learning, debugging, and documentation aids.

AI assistance was used for:

* reviewing stack pointer boundary conditions in circular doubly linked lists;
* discussing disorder calculation formulas and threshold adjustments;
* structuring the README formatting, tables, and documentation layout.

All implementation code, algorithmic architecture, debugging, refactoring for the 25-line limit, and testing were manually completed by the authors.

---

## Algorithm and Data Structure Choices

#### Overall Architecture

1. **Parsing & Validation**: Validates inputs, handles flags, checks for duplicates or overflow, and builds a circular doubly linked list (`t_stack`).
2. **Index Normalization**: Converts raw integer values into normalized relative ranks ($0$ to $N-1$), enabling bitwise and range operations regardless of value scale.
3. **Disorder Assessment**: Computes the inversion ratio $D = \frac{\text{mistakes}}{\text{total\_pairs}}$.
4. **Strategy Dispatcher**:
   * For $N \le 5$: Dedicated hardcoded/optimal routines (`sort_small`).
   * For $N > 5$: Evaluates flags or uses adaptive routing based on disorder level $D$.

#### Data Structure Used

A **Doubly Circular Linked List** (`t_stack`) with `next` and `prev` pointers:
* Allows $O(1)$ operations for swaps, rotations (`ra`/`rb`), and reverse rotations (`rra`/`rrb`).
* Provides convenient traversal in both directions when finding insertion targets or minimal steps.

---

## Complexity Analysis

| Strategy | Time Complexity | Space Complexity |
| --- | --- | --- |
| **Small Sort ($N \le 5$)** | $O(1)$ | $O(N)$ |
| **Simple Sort** | $O(N^2)$ | $O(N)$ |
| **Medium Sort (Chunks)** | $O(N\sqrt{N})$ | $O(N)$ |
| **Complex Sort (Radix)** | $O(N \log N)$ | $O(N)$ |

---

## Learning Objectives

This project helped develop knowledge about:

* Advanced linked list manipulation and pointer management in C;
* Algorithm selection trade-offs based on input characteristics and disorder metrics;
* Space and time complexity optimization under constrained instruction sets;
* Clean CLI design using modular flag parsing and benchmarking tools.

---

## Authors

* **hjacinto** — Parsing, Operations, Algorithms
* **ajoao** — Operations, Algorithms, README

42 School Students
