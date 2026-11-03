_This project has been created as part of the 42 curriculum by ezaimaki, ekausiny_

## push_swap 

## Description

The goal of this project was to sort a list of integers in an ascending order in **stack a** whilst only using **stack a** and **stack b**. 
Sorting algoriths implemented analyse the input and generate the appropriate sequence of operations. The output of the strategy is the sequence of operations that sorts the stack.

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

Four distinct sorting strategies were implemented.

#### Simple

`Selection sort adaptation` - run time is O(n²).
_Time complexity - O(n2)_
_Space complexity - O(1)_
It operates by comparing values next to each other. It has performance advantages over more complicated algoriths in certain situations, but is inefficient on large lists. 


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
It operates by sorting numbers digit by digit, starting from the least significant digit (rightmost) to the most significant digit (leftmost).
It groups numbers based on each digit and rearranges them step by step until the lsit is sorted.
It's most efficient for a large sets of numbersm especially when the numbers have the same number of digits.

## Instructions 
```bash
make          #compiles the library libft.a
make clean    # removes the .o files
make fclean   # removes the .o files and libft.a
make re       # recompiles everything from scratch
```
## Resources
[DeepWiki graphs](https://deepwiki.com/tdanielsousa/42School/4.3.5-push_swap-utilities-and-build-system) to visualise the structure of the project
[K-sort](https://medium.com/@brakebein42/k-distribution-sort-applied-to-the-push-swap-problem-ae2d96d68376) algorithm resources
[Radix sort](https://medium.com/@drwasimahmadkhan/radix-sort-8f203467c642) [Radix GeekForGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/) algorithm resources

**AI usage:** AI was used for to build some of the test functions, to visualise and explain some of the sorting alorithms. 
All code was written and understood by the authors.

