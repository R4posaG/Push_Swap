*This project has been created as part of the 42 curriculum by hjacinto, ajoao.*

# Push_Swap

## Description

This project consists of creating a set of highly efficient sorting algorithms that sort data on a stack using a limited set of instructions, aiming for the lowest possible number of operations.

The program works with two stacks (`stack_a` and `stack_b`) and a restricted set of stack manipulation rules. It evaluates the degree of disorder of the input data and selects an optimized strategy to perform the sort.

This project provides a deeper understanding of:

* Data structures (doubly circular linked lists) and stack management;
* Algorithm complexity analysis ( $O(n^2)$, $O(n\sqrt{n})$, and $O(n$ log $n)$ );
* Sorting strategies (Selection Sort, Chunks/Moving Window, LSD Radix Sort);
* Adaptive algorithm selection based on structural disorder;
* Parsing, input validation, and flag handling in C.

---

## Features & Strategies

The program features benchmarking capabilities and four explicit sorting strategies that can be executed directly or selected adaptively:

| Strategy | Flag | Complexity | Description / Algorithm |
| --- | --- | --- | --- |
| **Simple** | `--simple` | $O(n^2)$ | Selection/Extraction sort: repeatedly moves the minimum element to Stack B, sorts the remaining 3 in Stack A, and pushes back. |
| **Medium** | `--medium` | $O(n\sqrt{n})$ | Chunks / Moving Window algorithm: calculates chunk sizes using $\sqrt{N}$, pushes ranges to Stack B, and retrieves them in descending order. |
| **Complex** | `--complex` | $O(n \log n)$ | Bitwise LSD Radix Sort: assigns normalized indices to nodes and processes bit positions across all values. |
| **Adaptive** | `--adaptive` | Dynamic | Automatically measures disorder ratio ($D$) and routes execution: $D < 0.2 \to O(n^2)$, $0.2 \le D < 0.5 \to O(n\sqrt{n})$, $D \ge 0.5 \to O(n \log n)$. |

Additional features:
* **Benchmark mode (`--bench`)**: Displays the disorder percentage, strategy used, total operations count and breakdown per operation.

		[bench] disorder: 73.33%
		[bench] strategy: Adaptive / O(n log n)
		[bench] total_ops: 29
		[bench] sa:  0  sb:  0  ss:  0  pa:  11  pb:  11
		[bench] ra:  7  rb:  0  rr:  0  rra:  0  rrb:  0  rrr:  0

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

## Project Structure

| File / Directory | Description |
| --- | --- |
| `src/main.c` | Entry point, program initialization, and argument handling pipeline |
| `src/parsing.c` | Input validation, handling quoted strings, duplicate checks, and integer bounds |
| `src/flags.c` | Parsing CLI flags (`--bench`, `--simple`, `--medium`, `--complex`, `--adaptive`) |
| `src/stack_utils.c` | Creation, addition, duplicate checks, sorted state verification, and memory freeing |
| `src/indexing.c` | Index assignment to stack nodes ($0$ to $N-1$) for normalized processing |
| `src/check_disorder.c` | Calculates the inversion ratio / structural disorder rate of Stack A |
| `src/strategy.c` | Selects the best sorting algorithm based on flags, disorder and stack size |
| `src/benchmark.c` | Benchmark printing formatting for operation counts, strategy used and disorder rates |
| `src/operations/` | Implementation of stack operations (`push`, `swap`, `rotate`, `rev_rotate`) and  `register` wich prints every used operation to stdout. |
| `src/algorithms/` | Implementation of sorting algorithms (`sort_small`, `sort_simple`, `sort_medium`, `sort_complex`) |
| `push_swap.h` | Prototypes, structures (`t_stack`, `t_program`), enums, and inclusions |
| `Makefile` | Build compilation rules (`all`, `clean`, `fclean`, `re`) |

---

## Data Structure Used

A **Doubly Circular Linked List** (`t_stack`) with `next` and `prev` pointers:
* Allows $O(1)$ operations for swaps, rotations (`ra`/`rb`), and reverse rotations (`rra`/`rrb`).
* Provides convenient traversal in both directions when finding insertion targets or minimal steps.

---

## Algorithms Used

### Simple Algorithm: Selection Sort / Element Extraction
  The algorithm scans `stack_a` to find the absolute minimum element using `find_min`. It calculates the shortest rotation path (choosing dynamically between `ra` and `rra` based on the element's position relative to the middle of the stack). Once the minimum element reaches the top, it is pushed to `stack_b` via `pb`. 
  This loop repeats until only 3 elements remain in `stack_a`, which are instantly sorted using a hardcoded, maximum 2-operation base case (`sort_three`). Finally, all elements are pushed back to `stack_a` via `pa` in perfect ascending order.

---

### Medium Algorithm: Chunk-Based Sorting
This strategy divides the normalized stack indexes into $\sqrt{n}$ dynamic blocks (chunks). To achieve optimal performance and minimize `ra`/`rra` tracking costs in `stack_a`, the theoretical chunk size is mathematically scaled by a factor of `1.5` using integer arithmetic (`chunk_size = ft_sqrt(size) * 15 / 10`).
  
  The algorithm uses a sliding window:
  * Elements with indexes within the current window are pushed immediately to `stack_b` (`pb`).
  * Elements smaller than the window's starting index are pushed and rotated to the bottom of `stack_b` (`pb` followed by `rb`) to form pre-sorted sub-chunks.
  * The window slides forward as elements are cleared.

Once `stack_a` is empty, the algorithm efficiently pulls elements back from `stack_b` to `stack_a` by always rotating the maximum remaining element to the top via the shortest path.

---

### Complex Algorithm: Bitwise Radix Sort

This algorithm operates on the binary representation of the pre-assigned normalized element indexes (from `0` to `size_a - 1`). By sorting the structural indexes instead of raw values, it safely handles negative numbers and large integer spacing while minimizing the required bit-width.
  
  The algorithm loops through each bit digit (from the least significant bit to the most significant bit):
  * It performs a full pass of the stack. If the bit at the current position `i` of the top element's index is `0`, it pushes the node to `stack_b` (`pb`).
  * If the bit is `1`, it rotates the element to the back of `stack_a` (`ra`).
  * After checking all elements for the current bit, it empties `stack_b` back into `stack_a` (`pa`), shifting all `0`-bit elements to the top for that digit column.
  
  By the end of the loop everything will be sorted.

---

## Instructions

### Requirements

* GCC / Clang
* Linux / macOS


### Compilation

Compile the project using the provided Makefile:

```bash
make        # Compiles libft and push_swap with -Wall -Wextra -Werror
make clean  # Removes object files
make fclean # Removes object files and the push_swap binary
make re     # Executes fclean and rebuilds everything
```

This builds `libft` first, then compiles `push_swap` against it. Both are
compiled with `-Wall -Wextra -Werror`.

### Usage

Run `push_swap` by passing a list of integers as individual arguments or enclosed in a string:

```bash
# Basic usage
./push_swap 2 1 3 -6 5 -8

# Usage with a quoted string
./push_swap "4 67 3 -87 23"

# Benchmark mode
./push_swap --bench 3 1 2

# Specifying explicit strategies
./push_swap --simple "5 4 3 2 1"
./push_swap --bench --medium 9 4 2 1 -7 5
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
* **No memory leaks**: All allocated memory is properly freed and protected.

---

## Resources

### Documentation and References

* 42 push_swap subject
* A Common-Sense Guide to Data Structures and Algorithms by Jay Wengrow
* LINGUAGEM C by Luís Damas

## AI Usage

Artificial Intelligence tools were used exclusively as learning, debugging, and documentation aids.

AI assistance was used for structuring the README formatting, tables, and documentation layout.
All implementation code, algorithmic architecture, debugging, refactoring for the norm and testing were manually completed by the authors.

---

## Authors

* **hjacinto** — Parsing, Operations, Algorithms, README
* **ajoao** — Operations, Algorithms, README