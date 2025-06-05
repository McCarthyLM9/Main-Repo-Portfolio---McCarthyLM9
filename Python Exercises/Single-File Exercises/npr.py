"""This module calculates the number of permutations (nPr)."""
from math import factorial


def npr(n, r):
    """Calculate the number of permutations (nPr).

    Args:
        n (int): Total number of items
        r (int): Number of items to choose

    Returns:
        float: The number of permutations
    """
    return factorial(n) // factorial(n - r)


def main():
    """Main function to accept user input and compute nPr."""
    try:
        n = int(input("Enter n: "))
        r = int(input("Enter r: "))
    except ValueError:
        print("Invalid input: Please enter integers.")
        return 1
    if n < r or n < 0 or r < 0:
        print("Invalid input: n must be >= r and both must be non-negative.")
        return 1
    print(f"nPr: {npr(n, r)}")


if __name__ == "__main__":
    main()
