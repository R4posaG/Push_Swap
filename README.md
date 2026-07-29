***This project has been created as part of the 42 curriculum by hjacinto and ajoao.***

# Push_Swap

### Description

Push_Swap is a program made for sorting.

It sorts data on a stack, with a limited set of instructions, using the lowest possible number of actions. It does so by manipulating different types of algorithms, choosing the most appropriate solution for an optimized data sorting. 

---

#### ajoao
- Operations.

#### hjacinto
- Parsing.

---

### Parsing

This program only accepts valid positive integers as an argument.

---

### Operations

sa (swap a): Swap the first two elements at the top of stack a.  
- Do nothing if there is only one or no elements.  

sb (swap b): Swap the first two elements at the top of stack b.    
- Do nothing if there is only one or no elements.

ss : sa and sb at the same time.  

pa (push a): Take the first element at the top of b and put it at the top of a.  
- Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.  
- Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by one.  
- The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by one.  
- The first element becomes the last one.

rr : ra and rb at the same time.  
rra (reverse rotate a): Shift down all elements of stack a by one.  
- The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by one.
- The last element becomes the first one.

rrr : rra and rrb at the same time.