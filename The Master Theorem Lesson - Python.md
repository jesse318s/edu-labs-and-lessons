### Python Lesson: The Master Theorem

The Master Theorem provides a straightforward formula for determining the time complexity of divide-and-conquer algorithms. Before plugging in specific values, the standard unexpanded Master Theorem represents a general recurrence relation:

**T(n) = aT(n/b) + f(n)**

Here is what each variable represents when analyzing an algorithm's recursion tree:

* **T(n):** The total time required to solve a problem of size n.
* **a:** The number of recursive subproblems the algorithm spawns (must be >= 1).
* **b:** The factor by which the problem size is reduced for each recursive call (must be > 1).
* **f(n):** The time complexity of the work done *outside* the recursive calls (usually the cost of dividing the problem and merging the results).

#### The Master Theorem Equation Mapping for Binary Search

**Binary Search Code**
```python
def binary_search(arr, low, high, target):
    # 1. Base case and non-recursive work
    if low > high:
        return -1
    
    mid = (low + high) // 2
    
    if arr[mid] == target:
        return mid
    elif arr[mid] > target: # 2. Recursive calls on smaller subproblems
        return binary_search(arr, low, mid - 1, target)
    else:
        return binary_search(arr, mid + 1, high, target)
```

* **T(n) (Total Time):** Represents the total time it takes the `binary_search` function to run on an array (`arr`) of size n.
* **a = 1 (Number of subproblems):** In the code, although there are two `binary_search` statements written in the `if/else` block, the execution path ensures only **one** recursive call is actually made. The algorithm never searches both halves.
* **b = 2 (Subproblem size divisor):** When the recursive call is made, the new search space boundaries (`low` to `mid - 1` OR `mid + 1` to `high`) effectively divide the remaining array size n by 2.
* **f(n) = O(1) (Work done outside recursion):** This maps to the operations happening before the recursive calls. In the code, this includes checking `if low > high`, calculating `mid = (low + high) // 2`, and comparing `arr[mid]` to the `target`. These operations take constant time, regardless of the array size.

Putting it together, the exact unexpanded Master Theorem equation for binary search is:

**T(n) = 1T(n/2) + O(1)**

To find the final time complexity, we evaluate our equation using the Master Theorem's three cases. These cases simply compare the **recursive work** (`n^log_b(a)`) against the **outside work** (`f(n)`):

* **Case 1 (Recursion is heavier):** The recursive work grows faster than the outside work. The final time complexity is driven entirely by the recursion: `O(n^log_b(a))`.
* **Case 2 (Work is balanced):** Both sides grow at the exact same rate. We take that shared rate and multiply it by a log factor.
* **Case 3 (Outside work is heavier):** The outside work grows faster than the recursion. The final time complexity is driven entirely by the outside work: `O(f(n))`.

First, we calculate the "critical exponent" by evaluating `log_b(a)`. For binary search, this is `log_2(1) = 0`.

Next, we compare `n` to the power of that result (which is `n^0`, or simply 1) to our outside work, `f(n) = O(1)`. Because they grow at the exact same rate, this falls perfectly into **Case 2** of the Master Theorem.

According to Case 2, when the work to split the problem equals the work of the subproblems, we simply multiply our base work by log n. This gives binary search its famous final time complexity:

**T(n) = O(log n)**
