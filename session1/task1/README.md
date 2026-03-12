# Task 1

This task involves timing the execution of various programs using the Linux
`time` utility.

## `lower.c`

This program reads text from a file, transforming any uppercase characters
into lowercase and writing these to a new file. Names for the input and
output files must be provided on the command line.

We have also provided the text of Leo Tolstoy's famously lengthy novel
"War And Peace", for you to use with this program.

1. Briefly examine the contents of `war_and_peace.txt`.

2. Compile the program with `make lower`, then time its execution on the
   file with

       time ./lower war_and_peace.txt tmp.txt

   Make a note of the times that you see.

3. Briefly examine `tmp.txt` to verify that the operation has been performed
   correctly, then remove this file.

4. The same task can actually be performed the standard character translation
   utility of Linux systems, `tr`. Try this out now:

       time tr A-Z a-z < war_and_peace.txt > tmp.txt

   As before, check the contents of `tmp.txt` and then remove the file.

## `sin_sum.c`

This program invokes `sin()` from the C math library a very large number of
times, summing the values that are returned.

1. Examine the source code of `sin_sum.c`.

2. Compile the program with `make sin_sum`, then time its execution with

       time ./sin_sum

   Make a note of the times that you see.

## Comparisons

How does elapsed real time compare with the total of user and system CPU
time for the programs in `lower.c` and `sin_sum.c`?

You should observe that CPU time represents nearly all of the elapsed time
for `sin_sum.c`, whereas the bulk of the elapsed time for `lower.c` is
not spent on the CPU.

The program in `sin_sum.c` does very little I/O and is **CPU-bound**,
whereas the program in `lower.c` is **I/O-bound**.
