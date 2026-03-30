# Task 3

In this task, you will examine the performance of the programs from Task 2
in more detail, plotting graphs of CPU time vs problem size.

## Setup

**DO NOT SKIP EITHER OF THESE STEPS!**

1. In the terminal, cd to the `session1/task3/` directory and do

       bash setup.sh

   This will install the Python packages required for the task. (If you see
   a pop-up message warning about not installing packages into a virtual
   environment, you can safely ignore it.)

2. Install the official Python and Jupyter extensions into VS Code, just
   as you did when we worked with Matplotlib last semester.

## Analyzing Bubble Sort Performance

1. In the same directory as `plot.py`, create a new file named `bubblesort.csv`.
   Populate this with performance benchmarks from the Python and C versions
   of Bubble Sort in Task 2.

   The first column should be the size of the list that is sorted. Try going
   from 1000 up to 10000, in steps of 1000. The second column should be
   the times measured by `bubblesort.py` and the third column should be the
   times measured by `bubblesort.c`. Use `"size"`, `"Python"` and `"C"` as
   column headings.

   The first few lines of your CSV file should look something like this
   (with different numbers, obviously):

   ```csv
   size,Python,C
   1000,0.02373,0.00129
   2000,0.09593,0.00518
   3000,0.21758,0.01127
   ```

2. Edit `plot.py` and add a call to the `plot()` function, at the location
   indicated by the comment:

   ```py
   plot(data)
   ```

  **Don't click on the Run button (the one with the triangle icon) to run the
  program!** Instead, select 'Run Current File in Interactive Window' from
  the list of options in the drop-down menu next to the Run button.

  You should see the times for the Python and C implementations plotted on
  the same graph.

3. Now modify the program to call `log_plot()` instead of `plot()`, then rerun
   it. This will use logarithmic scaling on both axes. You should now see
   two approximately straight lines which look like they have the same slope.

   Straight lines indicate polynomial complexity. The two lines have the same
   slope because the two implementations are using the same algorithm. They
   differ in performance only by a scaling factor, which manifests itself on
   log-log plots as a shift along the y axis.

4. Another thing we can try is fitting a polynomial to the data and plotting
   both together. Start by replacing the call to `log_plot()` with this:

   ```py
   linear_regression(data, "Python")
   ```

   After running this, try it again, using `"C"` as the column name instead
   of `"Python"`. You should see that a straight line doesn't fit the data
   well. (Note: the axis scaling is now linear, not logarithmic!)

5. Repeat Step 4, this time using the `quadratic_regression()` function.
   Now you should see curves that appear to match the data points closely.

6. We saw earlier that the two implementations produce straight lines on a
   log-log plot. Since bubble sort is O(n<sup>2</sup>), the slopes of these
   lines should both be 2.

   To verify this, replace the call to `quadratic_regression()` with this
   code:

   ```py
   log_fit(data, "Python")
   log_fit(data, "C")
   ```

   Note: this code doesn't do any plotting, so you can just click on the Run
   button to run this code; you don't need to run it in an interactive terminal.

   You should see a value close to 2 for both C and Python.

## Other Experiments

Try one of the following comparisons:

- C bubble sort vs `qsort()`
- Python Powersort vs C `qsort()`

Create a CSV file for your chosen comparison, in the same way as before.
Note that you will need to use much larger problem sizes here - e.g., start
from lists with 100,000 elements, and proceed in steps of 100,000. You may
want to use a larger number of trials, too (e.g., 10).

Use the `plot()` and `log_plot()` functions to visualize the comparison.
