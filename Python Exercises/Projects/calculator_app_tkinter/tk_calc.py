"""
A simple calculator application using tkinter.

This calculator supports basic arithmetic operations and follows
PEP8, pylint, and flake8 coding standards.
"""

import tkinter as tk
from tkinter import messagebox
import operator


class Calculator:
    """A simple calculator GUI application."""

    def __init__(self):
        """Initialize the calculator."""
        self.root = tk.Tk()
        self.root.title("Calculator")
        self.root.geometry("480x640")
        self.root.resizable(False, False)

        # Calculator state
        self.current_input = ""
        self.total = 0
        self.operation = None
        self.new_number = True

        # Operators mapping
        self.operators = {
            '+': operator.add,
            '-': operator.sub,
            '*': operator.mul,
            '/': operator.truediv
        }

        self._create_widgets()

    def _create_widgets(self):
        """Create and arrange all GUI widgets."""
        # Display frame
        display_frame = tk.Frame(self.root, bg='lightgray', padx=5, pady=5)
        display_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        # Display entry
        self.display = tk.Entry(
            display_frame,
            font=('Arial', 16),
            justify='right',
            state='readonly',
            bg='white'
        )
        self.display.pack(fill=tk.BOTH, expand=True)

        # Buttons frame
        buttons_frame = tk.Frame(self.root, padx=10, pady=5)
        buttons_frame.pack(fill=tk.BOTH, expand=True)

        # Configure grid for 4 columns
        for c in range(4):
            buttons_frame.grid_columnconfigure(c, weight=1)

        # Define button layout (excluding bottom row)
        buttons = [
            ['C', '±', '%', '/'],
            ['7', '8', '9', '*'],
            ['4', '5', '6', '-'],
            ['1', '2', '3', '+']
        ]

        # Create regular buttons (rows 0-3)
        for i, row in enumerate(buttons):
            for j, text in enumerate(row):
                self._create_button(buttons_frame, text, i, j)

        # Create bottom row buttons with '0' spanning 2 columns
        self._create_bottom_row_buttons(buttons_frame, ['0', '.', '='], 4)

    def _create_button(self, parent, text, row, col):
        """Create a single button with appropriate styling and command."""
        # Determine button properties
        if text in '0123456789.':
            bg_color = 'lightblue'
            command = self._create_number_command(text)
        elif text in '+-*/':
            bg_color = 'orange'
            command = self._create_operator_command(text)
        elif text == '=':
            bg_color = 'lightgreen'
            command = self._equals_clicked
        elif text == 'C':
            bg_color = 'lightcoral'
            command = self._clear_clicked
        elif text == '±':
            bg_color = 'lightgray'
            command = self._plus_minus_clicked
        elif text == '%':
            bg_color = 'lightgray'
            command = self._percent_clicked
        else:
            bg_color = 'white'
            command = None

        button = tk.Button(
            parent,
            text=text,
            font=('Arial', 14),
            bg=bg_color,
            relief='raised',
            bd=2,
            command=command,
            anchor='center'
        )

        button.grid(
            row=row,
            column=col,
            columnspan=1,
            sticky='nsew',
            padx=2,
            pady=2
        )

        parent.grid_rowconfigure(row, weight=1)

    def _create_bottom_row_buttons(self, parent, buttons_list, row):
        """
           Create the bottom row buttons (0, ., =)
           with appropriate column spans.
        """
        positions = [0, 2, 3]   # column positions for '0', '.', '='
        colspans = [2, 1, 1]    # columnspans for each button

        for i, text in enumerate(buttons_list):
            if text in ('0', '.'):
                bg_color = 'lightblue'
                command = self._create_number_command(text)
            elif text == '=':
                bg_color = 'lightgreen'
                command = self._equals_clicked
            else:
                continue

            button = tk.Button(
                parent,
                text=text,
                font=('Arial', 14),
                bg=bg_color,
                relief='raised',
                bd=2,
                command=command,
                anchor='center'
            )

            button.grid(
                row=row,
                column=positions[i],
                columnspan=colspans[i],
                sticky='nsew',
                padx=2,
                pady=2
            )

        parent.grid_rowconfigure(row, weight=1)

    def _create_number_command(self, number):
        """Create a command function for number buttons."""
        def number_command():
            self._number_clicked(number)
        return number_command

    def _create_operator_command(self, operator_symbol):
        """Create a command function for operator buttons."""
        def operator_command():
            self._operator_clicked(operator_symbol)
        return operator_command

    def _update_display(self, value=""):
        """Update the calculator display."""
        self.display.config(state='normal')
        self.display.delete(0, tk.END)
        if value:
            self.display.insert(0, str(value))
        else:
            self.display.insert(
                0, self.current_input if self.current_input else "0"
            )
        self.display.config(state='readonly')

    def _number_clicked(self, number):
        """Handle number button clicks."""
        if self.new_number:
            self.current_input = ""
            self.new_number = False

        if number == '.' and '.' in self.current_input:
            return  # Prevent multiple decimal points

        self.current_input += number
        self._update_display()

    def _operator_clicked(self, op):
        """Handle operator button clicks."""
        if self.current_input:
            if self.operation and not self.new_number:
                self._calculate()
            else:
                try:
                    self.total = float(self.current_input)
                except ValueError:
                    self._show_error("Invalid number")
                    return

            self.operation = op
            self.new_number = True

    def _equals_clicked(self):
        """Handle equals button click."""
        if self.operation and self.current_input and not self.new_number:
            self._calculate()

    def _calculate(self):
        """Perform the calculation."""
        try:
            current_number = float(self.current_input)

            if self.operation == '/' and current_number == 0:
                self._show_error("Cannot divide by zero")
                return

            result = self.operators[self.operation](self.total, current_number)

            # Format result to avoid floating point precision issues
            if result == int(result):
                result = int(result)
            else:
                result = round(result, 10)

            self.total = result
            self.current_input = str(result)
            self._update_display()

            self.operation = None
            self.new_number = True

        except (ValueError, OverflowError, ZeroDivisionError) as e:
            self._show_error(f"Error: {str(e)}")

    def _clear_clicked(self):
        """Handle clear button click."""
        self.current_input = ""
        self.total = 0
        self.operation = None
        self.new_number = True
        self._update_display("0")

    def _plus_minus_clicked(self):
        """Handle plus/minus button click."""
        if self.current_input and self.current_input != "0":
            if self.current_input.startswith('-'):
                self.current_input = self.current_input[1:]
            else:
                self.current_input = '-' + self.current_input
            self._update_display()

    def _percent_clicked(self):
        """Handle percent button click."""
        if self.current_input:
            try:
                value = float(self.current_input) / 100
                if value == int(value):
                    value = int(value)
                self.current_input = str(value)
                self._update_display()
            except ValueError:
                self._show_error("Invalid number")

    def _show_error(self, message):
        """Display error message and reset calculator."""
        messagebox.showerror("Error", message)
        self._clear_clicked()

    def run(self):
        """Start the calculator application."""
        self._update_display("0")
        self.root.mainloop()


def main():
    """Main function to run the calculator."""
    calculator = Calculator()
    calculator.run()


if __name__ == "__main__":
    main()
