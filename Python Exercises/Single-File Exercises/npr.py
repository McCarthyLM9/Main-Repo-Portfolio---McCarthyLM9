"""This module calculates the number of permutations (nPr)."""


def factorial(n):
    """Compute the factorial of a non-negative integer n.

    Args:
        n (int): A non-negative integer

    Returns:
        int: The factorial of n
    """
    if n == 0 or n == 1:
        return 1
    return n * factorial(n - 1)


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
    return 0


if __name__ == "__main__":
    main()
