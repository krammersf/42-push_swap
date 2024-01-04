
# Push Swap

Push Swap is a program that sorts a stack of integer numbers using two stacks and a set of allowed operations.

## How to use

### Compilation

To compile the program, run the following command:

```
make
```

### Execution

To run the program, execute the following command:

```
./push_swap [integer list]
```

where `[integer list]` is a list of integer numbers separated by spaces.
You can find some `[integer list]` in subject dir, in the _commands.txt file.

The program will output a list of instructions that will sort the integer list.

## Operations

The following operations are allowed:

- **sa** : swap the first two elements of stack A
- **sb** : swap the first two elements of stack B
- **ss** : sa and sb at the same time
- **pa** : take the first element from stack B and put it at the top of stack A
- **pb** : take the first element from stack A and put it at the top of stack B
- **ra** : shift up all elements of stack A by 1. The first element becomes the last one.
- **rb** : shift up all elements of stack B by 1. The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra** : shift down all elements of stack A by 1. The last element becomes the first one.
- **rrb** : shift down all elements of stack B by 1. The last element becomes the first one.
- **rrr** : rra and rrb at the same time.

## Example

```
$> ./push_swap 2 1 3 6 5 8 7 4
pb
ra
pb
ra
pb
rra
pa
ra
pa
ra
ra
```
## Sorting Types

It can be summarized as follows:

1. ***Chunk Division***: The algorithm starts by dividing the stack into two parts: stack A (initially containing all the numbers) and an empty stack B.

2. ***Push to Stack B***: The algorithm identifies the "cheapest" number in stack A, which is the number that requires the fewest number of moves to be pushed to stack B. It uses different operations (rotate, reverse rotate) to move this number to stack B.

3. ***Sorting in Stack B***: Once a number is pushed to stack B, the algorithm evaluates the remaining numbers in stack A and performs a similar process to find the next "cheapest" number. It continues this process until all numbers are in stack B.

5. ***Back to Stack A***: After all the numbers are in stack B, the algorithm begins the process of moving the numbers back to stack A while keeping them in the correct order, always caring about the cheapest numbers in both stacks. It performs a series of operations to achieve this.

## Bonus

## Grade: 100 / 100

## Used Tests
- Push-Swap-Tester: https://github.com/gemartin99/Push-Swap-Tester
-  push_swap_visualizer: https://github.com/o-reo/push_swap_visualizer

### Disclaimer

Maybe you could notice a different coding style. At 42 we need to follow some rules according to the coding standard of the school such as:
```
- No for, do while, switch, case or goto 
- No functions with more than 25 lines 
- No more than 5 functions per each file
- No more than 5 variables in the same function
- No assigns and declarations assigns in the same line
```
Click here to read the norm file of 42 school.
