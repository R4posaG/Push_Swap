***This project has been created as part of the 42 curriculum by hjacinto and ajoao.***

# Push_Swap

### Description

Push_Swap is a program made for sorting.

It sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. It does so by manipulating different types of algorithms, choosing the most appropriate solution for an optimized data sorting. 

---

#### ajoao
- Operations
- Algorithms

#### hjacinto
- Parsing
- Operations
- Algorithms
- Readme

---

### Parsing

This program only accepts valid positive integers.  
The program can receive a flag `--bench` which displays the benchmark. And a couple other strategy flags: `--simple`, `--medium`, `--complex` and `--adaptive` wich select the strategy used for sorting. 

Examples:
 
```sh
./push_swap --bench 3 1 2
./push_swap --bench --simple "5 4 3 2 1"
```

---

### Operations


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

-----

### Instructions
 
```sh
make
```
 
This builds `libft` first, then compiles `push_swap` against it. Both are
compiled with `-Wall -Wextra -Werror`.
 
```sh
make clean   # remove object files (project + libft)
make fclean  # clean + remove the push_swap binary
make re      # fclean + all
```