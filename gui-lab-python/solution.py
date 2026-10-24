import tkinter as tk
from tkinter import messagebox


def main():
    """
    Set up and run the Tip Calculator GUI
    """
    root = tk.Tk()
    root.title("Tip Calculator")
    root.geometry("300x250")
    root.resizable(False, False)
    
    # Variables to store results
    tip_result = tk.StringVar()
    total_result = tk.StringVar()
    tip_result.set("$0.00")
    total_result.set("$0.00")
    
    # Bill Amount
    bill_label = tk.Label(root, text="Bill Amount ($):")
    bill_label.grid(row=0, column=0, padx=10, pady=10, sticky="w")
    
    bill_entry = tk.Entry(root)
    bill_entry.grid(row=0, column=1, padx=10, pady=10)
    
    # Tip Percentage
    tip_label = tk.Label(root, text="Tip Percentage (%):")
    tip_label.grid(row=1, column=0, padx=10, pady=10, sticky="w")
    
    tip_entry = tk.Entry(root)
    tip_entry.grid(row=1, column=1, padx=10, pady=10)
    
    def calculate():
        try:
            bill = float(bill_entry.get())
            tip_percent = float(tip_entry.get())
            
            if bill < 0 or tip_percent < 0:
                messagebox.showerror("Error", "Values must be positive")
                return
            
            tip_amount = bill * (tip_percent / 100)
            total_amount = bill + tip_amount
            tip_amt = round(tip_amount, 2)
            total_amt = round(total_amount, 2)
            tip_result.set(f"${tip_amt:.2f}")
            total_result.set(f"${total_amt:.2f}")
        except ValueError:
            messagebox.showerror("Error", "Please enter valid numbers")
        except ZeroDivisionError:
            messagebox.showerror("Error", "Invalid input")
    
    # Calculate Button
    calc_button = tk.Button(root, text="Calculate", command=calculate, width=15)
    calc_button.grid(row=2, column=0, columnspan=2, pady=15)
    
    # Tip Amount Result
    tip_display_label = tk.Label(root, text="Tip Amount:")
    tip_display_label.grid(row=3, column=0, padx=10, pady=5, sticky="w")
    
    tip_value_label = tk.Label(root, textvariable=tip_result, font=("Arial", 10, "bold"))
    tip_value_label.grid(row=3, column=1, padx=10, pady=5, sticky="w")
    
    # Total Amount Result
    total_display_label = tk.Label(root, text="Total Amount:")
    total_display_label.grid(row=4, column=0, padx=10, pady=5, sticky="w")
    
    total_value_label = tk.Label(root, textvariable=total_result, font=("Arial", 10, "bold"))
    total_value_label.grid(row=4, column=1, padx=10, pady=5, sticky="w")
    
    root.mainloop()


if __name__ == "__main__":
    main()
