"""Roman to Integer Converter"""


class RomanToInteger:
    """A class to convert Roman numeral strings to their integer values.
    """
    def __init__(self):
        self.roman_numerals = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

    def roman_to_integer(self, s: str) -> int:
        """Convert a Roman numeral string to an integer.

        Args:
            s (str): A string representing a Roman numeral.

        Returns:
            int: The integer value of the Roman numeral.
        """
        total = 0
        prev_value = 0

        for char in reversed(s):
            value = self.roman_numerals[char]
            if value < prev_value:
                total -= value
            else:
                total += value
            prev_value = value

        return total


def main():
    """Main function to run the Roman to Integer converter.
    """
    converter = RomanToInteger()
    roman_string = input("Enter a number in Roman numerals: ")
    integer_value = converter.roman_to_integer(roman_string)
    print(f"The integer value of '{roman_string}' is: {integer_value}")


if __name__ == "__main__":
    main()
