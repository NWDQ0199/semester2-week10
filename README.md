# Week 10

## Session 1: Benchmarks, Optimization & Profiling

On Linux systems, the execution of entire commands can be timed using the
`time` system utility. This measures both wall time (elapsed real time) and
CPU time (time that a process spends executing on the CPU).

Within Python programs, you can use functions provided in the `time` and
`timeit` modules to measure wall or CPU time for pieces of code, providing
useful **benchmarks** of program performance.

Within C programs, you can measure the usage of CPU time using the `clock()`
function from the standard library.

**Optimization** of C programs can be done to varying degrees using the `-O`
options of GCC, e.g.,

    gcc -O2 -o prog prog.c

**Profiling** provides deeper insights into performance. Profiling of C
programs can be done by compiling (and linking) code with the `-pg` option,
running the resulting executable to collect information on program execution,
then using `gprof` to analyze the collected data.
