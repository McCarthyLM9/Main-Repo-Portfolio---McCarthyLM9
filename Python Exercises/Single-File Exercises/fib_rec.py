"""Fibonacci function using recursion"""


def fib(n):
    """fibonnaci function

    Args:
        n (integer): fibonnaci numerical position

    Returns:
        integer: Fibonacci number at position n
    """
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)


def fibtest():
    """Main function to test the Fibonacci function"""
    while True:
        try:
            n = int(input("Enter a number: "))
            if n < 0:
                print("Please enter a non-negative integer.")
                continue
            print(f"The Fibonacci number at position {n} is: {fib(n)}")
            break
        except ValueError:
            print("Invalid input. Please enter a valid integer.")


def main():
    """Main function to run the Fibonacci test"""
    fibtest()


if __name__ == "__main__":
    main()
