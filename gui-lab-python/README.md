# Python GUI Lab (with Tkinter): Tip Calculator

## Objective
Learn the basics of building GUI applications with Python's Tkinter library by creating a simple Tip Calculator from scratch.

## Difficulty
Beginner

## Concepts Covered
- Creating a Tkinter window
- Using Labels, Entries, and Buttons
- Layout management with `pack()` or `grid()`
- Handling button click events
- Basic input validation and calculations
- Separating logic from GUI code

## Problem Description

Create a Tip Calculator application that:
1. Has a window titled "Tip Calculator"
2. Allows the user to enter a bill amount
3. Allows the user to enter a tip percentage (e.g., 15 for 15%)
4. Has a "Calculate" button that computes the tip amount and total
5. Displays the tip amount and total amount in labels

## Requirements

### GUI Elements
- Label and Entry for "Bill Amount ($)"
- Label and Entry for "Tip Percentage (%)"
- Button labeled "Calculate"
- Labels to display "Tip Amount:" and "Total Amount:" with their calculated values

### Functionality
- When Calculate is clicked, calculate:
  - Tip = Bill Amount * (Tip Percentage / 100)
  - Total = Bill Amount + Tip
- Display results rounded to 2 decimal places
- Handle basic cases (you can assume valid numbers are entered for this lab)

### Code Structure
Split your logic and GUI:
- Create a function `main()` that sets up and runs the GUI
- Call `main()` in a `if __name__ == "__main__":` block

**Tip:** You may create a helper function like `calculate_tip(bill, tip_percent)` to separate your logic from the GUI code, but it is not required.

## Getting Started

1. Open `main.py` - it has starter code with TODOs
2. Implement the required functions and GUI
3. Test your implementation
4. Run your app with `python main.py`

## Testing

Run the tests with:
```bash
python -m pytest test_main.py
```
or
```bash
python test_main.py
```

## Hints
- Import tkinter: `import tkinter as tk` or `from tkinter import *`
- Use `FloatVar()` or just get values with `.get()` and convert with `float()`
- For layout, `grid(row=..., column=...)` is often clean for forms
- Use `StringVar()` to update label text dynamically

## Solution
A complete solution is provided in `solution.py` for reference after you've attempted the lab yourself!
