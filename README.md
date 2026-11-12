*This project has been created as part of the 42 curriculum by mabd-elh, yaabed.*

# Push_swap

Because Swap_push doesn't feel as natural.

## Description

**Push_swap** is an algorithmic project designed to introduce developers to the concepts of time and space complexity, optimization, and data sorting. The objective is highly straightforward: sort a given stack of integers in ascending order using a secondary empty stack and a highly constrained set of operations. 

The primary challenge is not just to sort the data, but to do so using the absolute minimum number of moves. To achieve this, the project implements various sorting strategies tailored to the input size and its initial level of "disorder."

### The Rules
We have two stacks, `a` (initialized with a random list of unique integers) and `b` (initialized as empty). We can only use the following operations:
*   **`sa` / `sb` / `ss`**: Swap the first two elements at the top of stack `a` / `b` / both.
*   **`pa` / `pb`**: Push the top element from stack `b` to `a` / stack `a` to `b`.
*   **`ra` / `rb` / `rr`**: Rotate stack `a` / `b` / both upwards (first element becomes the last).
*   **`rra` / `rrb` / `rrr`**: Reverse rotate stack `a` / `b` / both downwards (last element becomes the first).

## Instructions

### Compilation
To compile the project, run the following command at the root of the repository:
```bash
make
```
This will compile the `push_swap` executable. You can also run `make bonus` to compile the `checker` program if you have implemented it.

### Execution
Run the program by passing a list of integers as arguments. The numbers must be space-separated.
```bash
./push_swap 2 1 3 6 5 8
```

#### Flags
You can optionally specify a strategy selector to force the program to use a specific sorting algorithm:
*   `--simple`: Forces the $O(n^2)$ algorithm.
*   `--medium`: Forces the $O(n\sqrt{n})$ algorithm.
*   `--complex`: Forces the $O(n \log n)$ algorithm.
*   `--adaptive`: Selects the best algorithm based on the measured disorder (Default behavior).
*   `--bench`: Displays benchmark metrics on standard error (disorder %, strategy used, and operation breakdown) after sorting.

Example with benchmark mode:
```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

## Algorithms and Justification

In accordance with the project requirements, four distinct sorting strategies have been implemented to handle different scales of input and disorder levels.

### 1. The Disorder Metric
Before sorting, the program analyzes stack `a` to determine its disorder—a value between $0$ (perfectly sorted) and $1$ (worst-case reverse sorted). It is calculated by counting how many pairs of numbers are out of order relative to the total possible pairs.

### 2. Simple Algorithm — $O(n^2)$
* **Threshold:** Low disorder (Disorder $< 0.2$)
* **Explanation:** For inputs that are already nearly sorted or very small, complex overhead is unnecessary. This algorithm relies on a highly optimized adaptation of Selection/Insertion sort, keeping the number of instructions drastically low when only a few elements are out of place.

### 3. Medium Algorithm — $O(n\sqrt{n})$
* **Threshold:** Medium disorder ($0.2 \le$ Disorder $< 0.5$)
* **Explanation:** When the data has moderate disorder, this chunk-based strategy is employed. The stack is virtually divided into $\sqrt{n}$ chunks. Elements are pushed to stack `b` based on their chunk affiliation, which pre-sorts them in a rough funnel before they are meticulously pushed back to stack `a`.

### 4. Complex Algorithm — $O(n \log n)$
* **Threshold:** High disorder (Disorder $\ge 0.5$)
* **Explanation:** For completely random and large datasets, a time-optimized algorithm is strictly required. This is implemented via a Radix Sort / Quicksort adaptation utilizing stack partitioning, guaranteeing scalable performance even at 500+ elements.

### 5. Adaptive Strategy
The core of our push_swap program's intelligence lies in the `--adaptive` default routing. By analyzing the disorder metric upfront, it actively branches into the Simple, Medium, or Complex strategy. This guarantees that an already sorted stack isn't unnecessarily churned through a complex $O(n \log n)$ algorithm, saving thousands of operations in edge cases.

## Resources

*   **Algorithmic Complexity & Big-O Notation:** [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
*   **Push Swap visulizer:** [Push Swap visulizer](https://github.com/o-reo/push_swap_visualizer)
*   **Sorting Algorithms Visualized:** [VisuAlgo](https://visualgo.net/en/sorting)
*   **AI Usage:** AI was used to create the README file. No AI was used to write the core sorting logic or bypass the learning objectives of the curriculum.