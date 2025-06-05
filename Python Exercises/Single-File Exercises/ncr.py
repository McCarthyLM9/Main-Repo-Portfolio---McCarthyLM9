"""Combinations (Discrete Mathematics)"""
from math import factorial


def ncr(n, r):
    """Calculate n choose r (nCr) using the factorial function"""
    return factorial(n) // (factorial(n - r) * factorial(r))


def main():
    """Main function to execute the nCr calculation"""
    try:
        n = int(input("Enter n: "))
        r = int(input("Enter r: "))
    except ValueError:
        print("Invalid input: Please enter integers.")
        return 1
    if n < r or n < 0 or r < 0:
        print("Invalid input: n must be >= r and both must be non-negative.")
        return 1
    print(f"nCr: {ncr(n, r)}")


if __name__ == "__main__":
    main()
