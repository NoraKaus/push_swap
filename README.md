_This project has been created as part of the 42 curriculum by ezaimaki, ekausiny_

## push_swap 

## Description

The goal of this project was to sort a list of integers in ascending order in **stack a**, using only **stack a**, **stack b** and a limited set of operations.
The program analyses the input, chooses a sorting strategy, depending on the user's input, and prints the sequence of operations that sorts the stack, one per line.

#### Available operations

`sa (swap a)` Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.

`sb (swap b)`: Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.

`ss` : sa and sb at the same time.

`pa (push a)`: Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

`pb (push b)`: Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

`ra (rotate a)`: Shift up all elements of stack a by one.
The first element becomes the last one.

`rb (rotate b)`: Shift up all elements of stack b by one.
The first element becomes the last one.

`rr` : ra and rb at the same time.

`rra (reverse rotate a)`: Shift down all elements of stack a by one.
The last element becomes the first one.

`rrb (reverse rotate b)`: Shift down all elements of stack b by one.
The last element becomes the first one.

`rrr` : rra and rrb at the same time

### Disorder metric 

Disorder was measured with a number between 0 (sorted) and 1 (furthest away from being sorted). 

### Algorithm selection

Four strategies were implemented: three sorting algorithms and an adaptive mode that chooses between them.
Very small inputs (up to 5 numbers) are handled by a dedicated short sort that uses a minimal, hard-coded set of moves.

#### Simple

`Min extraction` - run time is O(n²).
_Time complexity - O(n2)_
_Space complexity - O(1)_
It operates by finding smallest int and moving it to stack b, till stack a is empty, then moving all values back to stack a. It has performance advantages over more complicated algorithms in certain situations, but is inefficient on large lists. 

#### Medium 

`K-Distribution sort` - run time is O(n√n).
_Time complexity - O(n√n)_
_Space complexity - _
It operates by iteratively pushing elements from stack A to stack B, using a growing threshold to decide which elements to transfer and how to place them within B. The technique is particularly known for shaping stack B into a "K-like" structure when visualized—hence the name.
Best suited for n = [50, 500] elements in push_swap projects, though it remains effective and reliable for a broader range from around 10 to 1000 elements.

#### Complex

`Radix sort` - run time O(n log n).
_Time complexity - O(nk)_
_Space complexity - O(n + k)_
It operates by sorting numbers bit by bit, starting from the least significant bit (rightmost) to the most significant bit(leftmost).
It groups numbers based on each bit and rearranges them step by step until the list is sorted.
It's most efficient for a large sets of numbers especially when the numbers have the same number of bits.

## Instructions 
```bash
make          # compiles the push_swap
make clean    # removes the .o files
make fclean   # removes the .o files and push_swap
make re       # recompiles everything from scratch
ARG="2 1 0"; ./push_swap $ARG | ./checker_linux $ARG 

```

## Flags

`--bench`
`--simple`
`--medium`
`--complex`
`--adaptive`

## Work distribution

We started by discussing the project and outlining the steps we'll need to take to solve it. We've split the project into smaller funtions that will be needed to run it and split them between each other.

ekausiny
- Error handling
- Input validation
- flag processing
- input conversion to int
- medium sort
- short sort
- picking of alorithms

ezaimaki
- disorder measure
- duplicate checker
- push / swap / rotates build and definition
- list build and processing
- simple sort
- complex sort
- bench

Throughout the project we've reached out to each other if we needed any help with writing functions, or to further clarify the layout of the project

## Resources
[DeepWiki graphs](https://deepwiki.com/tdanielsousa/42School/4.3.5-push_swap-utilities-and-build-system) to visualise the structure of the project
[K-sort](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376) algorithm resources
[Radix sort](https://medium.com/@drwasimahmadkhan/radix-sort-8f203467c642) [Radix GeekForGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/) algorithm resources

**AI usage:** AI was used for to build some of the test functions, to visualise and explain some of the sorting alorithms. 
All code was written and understood by the authors.

